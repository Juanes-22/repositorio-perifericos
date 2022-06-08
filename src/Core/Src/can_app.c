/**
 * @file can_app.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Codigo aplicativo para envío y recepción CAN
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "can_app.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/** @brief CAN number of messages to transmit */
#define CAN_NUM_OF_MSGS					4

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/** @brief Array of CAN IDs to transmit */
static const uint32_t can_ids_array[CAN_NUM_OF_MSGS] = {CAN_ID_PERIFERICOS_PEDAL,
														CAN_ID_PERIFERICOS_HOMBRE_MUERTO,
														CAN_ID_PERIFERICOS_BOTONES_CAMBIO_ESTADO,
														CAN_ID_PERIFERICOS_OK};

/** @brief Array of CAN values to transmit */
static uint8_t can_values_array[CAN_NUM_OF_MSGS];

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal de CAN a nivel de aplicación.
 *
 * Guarda mensaje CAN recibido en bus de entrada CAN cuando se activa
 * bandera de recepción. Envía datos de bus de salida CAN cuando se
 * activa bandera de transmisión.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void CAN_APP_Process(void)
{
	/** Increments every time CAN TX flag is set as CAN_TX_READY */
	static int can_tx_flag_count = 0;

    /* Recibió mensaje CAN */
    if (flag_rx_can == CAN_MSG_RECEIVED)
    {
		/* Toggle LED 2 (Green LED) */
		BSP_LED_Toggle(LED2);

        /* Guarda mensaje CAN recibido en bus de entrada CAN */
        CAN_APP_Store_ReceivedMessage();

        /* Clear CAN received message flag */
        flag_rx_can = CAN_MSG_NOT_RECEIVED;

        /* Activa bandera para decodificar */
        flag_decodificar = DECODIFICA;
    }

    /* Hubo trigger para transmisión mensaje CAN */
    if (flag_tx_can == CAN_TX_READY)
    {
    	/* Incrementa contador de bandera transmisión CAN */
    	can_tx_flag_count++;

    	/* Send bus variables every 500ms (CAN transmission timer is set to 100ms) */
    	if(can_tx_flag_count % 5 == 0)
    	{
    		/* Toggle LED 1 (Red LED) */
    		BSP_LED_Toggle(LED1);

			/* Envío de datos del bus de salida CAN a módulo CAN */
			CAN_APP_Send_BusData(&bus_can_output);

			/* Better reset this to zero */
			can_tx_flag_count = 0;
    	}

        /* Clear CAN TX ready flag */
        flag_rx_can = CAN_TX_NOT_READY;
    }
}

/**
 * @brief Función de envío de datos de bus de salida CAN a módulo CAN.
 *
 * Realiza el envío de las variables que se encuentran en el bus de salida CAN a módulo CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param bus_can_output Puntero a estructura de tipo typedef_bus2_t (bus de salida CAN)
 * @retval None
 */
void CAN_APP_Send_BusData(typedef_bus2_t *bus_can_output)
{
	/* Index for CAN values array and CAN IDs array */
	static int i = 0;

	/* Bus data into CAN values array */
	can_values_array[0] = bus_can_output->pedal;
	can_values_array[1] = bus_can_output->hombre_muerto;
	can_values_array[2] = bus_can_output->botones_cambio_estado;
	can_values_array[3] = bus_can_output->perifericos_ok;

	/* Index exceeds number of messages to transmit */
	if(i >= CAN_NUM_OF_MSGS)
	{
		i=0;
		return;
	}

	/* Set up can_obj for message transmission */
	can_obj.Frame.id = can_ids_array[i];
	can_obj.Frame.payload_length = 1;
	can_obj.Frame.payload_buff[0] = can_values_array[i];

	/* Send message */
	if (CAN_API_Send_Message(&can_obj) != CAN_STATUS_OK)
	{
		Error_Handler();
	}

	i++;
}

/**
 * @brief Función guardar mensaje CAN recibido en bus de entrada CAN.
 *
 * Según standard identifier que se recibió, guarda dato en variables de bus de recepción CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void CAN_APP_Store_ReceivedMessage(void)
{
	switch(can_obj.Frame.id)
	{

	/* ------------------------ Control ----------------------- */

	case CAN_ID_CONTROL_ESTADO_MANEJO:
		bus_can_input.estado_manejo = can_obj.Frame.payload_buff[0];
		break;
	case CAN_ID_CONTROL_ESTADO_FALLA:
		bus_can_input.estado_falla = can_obj.Frame.payload_buff[0];
		break;
	case CAN_ID_CONTROL_OK:
		bus_can_input.control_ok = can_obj.Frame.payload_buff[0];
		break;

	/* ------------------------- BMS -------------------------- */

	case CAN_ID_BMS_VOLTAJE:
		bus_can_input.voltaje_bms = can_obj.Frame.payload_buff[0];
		break;
	case CAN_ID_BMS_CORRIENTE:
		bus_can_input.corriente_bms = can_obj.Frame.payload_buff[0];
		break;
	case CAN_ID_BMS_POTENCIA:
		bus_can_input.potencia_bms = can_obj.Frame.payload_buff[0];
		break;
	case CAN_ID_BMS_NIVEL_BATERIA:
		bus_can_input.nivel_bateria_bms = can_obj.Frame.payload_buff[0];
		break;

	/* ----------------------- Inversor ----------------------- */

	case CAN_ID_INVERSOR_VELOCIDAD:
		bus_can_input.velocidad_inv = can_obj.Frame.payload_buff[0];
		break;

    default:
        break;
	}
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/
