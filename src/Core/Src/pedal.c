/**
 * @file pedal.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Código aplicativo para pedal
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pedal.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/** Valores que corresponden al 0 y 100 del pedal */
#define MIN_ADC_VAL			300.0
#define MAX_ADC_VAL			3800.0

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void PEDAL_Map_ADC_Reading(void);

static void PEDAL_Send_Pedal_Value(uint32_t to_send, typedef_bus2_t* bus_can_output);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal para el pedal. Se procesa y se guarda la lectura del ADC en el
 * bus de datos. Se envía lectura del ADC mapeada a bus de datos y a bus de salida CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param   None
 * @retval  None
 */
void PEDAL_Process(void)
{
	/* Mapeo de lectura ADC pedal */
	PEDAL_Map_ADC_Reading();

	/* Envío de valor de pedal mapeado a bus de salida CAN */
	PEDAL_Send_Pedal_Value(bus_data.pedal, &bus_can_output);
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

/**
 * @brief Mapeo de lectura ADC del pedal. Guarda valor de pedal mapeado en bus
 * de datos.
 *
 * @param None
 * @retval None
 */
static void PEDAL_Map_ADC_Reading(void)
{
	if(flag_adc == ADC_CONV_COMPLETED)
	{
		/* Guarda lectura de ADC en bus de datos */
		bus_data.adc_reading = adc_buf[0];

		/* ADC reading mapping */
		if(bus_data.adc_reading < MIN_ADC_VAL)
		{
			bus_data.pedal = 0.0;
		}
		else if(bus_data.adc_reading > MAX_ADC_VAL)
		{
			bus_data.pedal = 100.0;
		}
		else
		{
			bus_data.pedal = ((bus_data.adc_reading - MIN_ADC_VAL) / (MAX_ADC_VAL - MIN_ADC_VAL)) * 100;
		}

		/* Clear ADC conversion flag */
		flag_adc = ADC_CONV_NOT_COMPLETED;
	}
}

/**
 * @brief Envío de valor de pedal mapeado a bus de salida CAN.
 *
 * @param to_send           Valor de pedal a enviar
 * @param bus_can_output    Puntero a estructura de tipo typedef_bus2_t (bus de salida can)
 */
static void PEDAL_Send_Pedal_Value(uint32_t to_send, typedef_bus2_t* bus_can_output)
{
	bus_can_output->pedal = (uint8_t) to_send;
}
