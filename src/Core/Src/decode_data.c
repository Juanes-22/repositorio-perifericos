/**
 * @file decode_data.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Decodificación de datos provenientes de CAN
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "decode_data.h"

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/** @brief Bandera para ejecutar bloque de decodificación de datos */
decode_status_t flag_decodificar = NO_DECODIFICA;

/** @brief Puntero a estructura de tipo rx_control_vars_t que contiene los valores de las variables decodificadas de Control */
rx_control_vars_t* Rx_Control = &bus_data.Rx_Control;

/** @brief Puntero a estructura de tipo rx_bms_vars_t que contiene los valores de las variables decodificadas del BMS */
rx_bms_vars_t* Rx_Bms = &bus_data.Rx_Bms;

/** @brief Puntero a estructura de tipo rx_inversor_vars_t que contiene los valores de las variables decodificadas del inversor */
rx_inversor_vars_t* Rx_Inversor = &bus_data.Rx_Inversor;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void DECODE_DATA_Decode_Control(void);

static void DECODE_DATA_Decode_Bms(void);

static void DECODE_DATA_Decode_Inversor(void);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal de decodificación de datos de bus de recepción CAN.
 *
 * Decodifica los datos que se reciben desde el bus CAN. Los datos decodificados quedan
 * guardados en estructuras de tipo rx_control_vars_t, rx_bms_vars_t, y rx_inversor_vars_t,
 * en el bus de datos.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void DECODE_DATA_Process(void)
{
    if (flag_decodificar == DECODIFICA)
    {
    	DECODE_DATA_Decode_Control();

    	DECODE_DATA_Decode_Bms();

    	DECODE_DATA_Decode_Inversor();

        flag_decodificar = NO_DECODIFICA;
    }
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

/**
 * @brief Decodifica los datos de Control
 *
 * Decodifica las variables que se reciben de Control por CAN y guarda
 * los datos en la estructura Rx_Control del tipo rx_control_vars_t y que
 * se encuentra en el bus_data.
 *
 */
static void DECODE_DATA_Decode_Control(void)
{
    /* Decodifica info de Control */
    switch (bus_can_input.control_ok)
    {
    case CAN_VALUE_MODULE_OK:
        Rx_Control->control_ok = kMODULE_INFO_OK;
        break;
    case CAN_VALUE_MODULE_ERROR:
        Rx_Control->control_ok = kMODULE_INFO_ERROR;
        break;
    }

	/* Decodifica modos de manejo de Control */
    switch (bus_can_input.estado_manejo)
    {
    case CAN_VALUE_DRIVING_MODE_ECO:
    	Rx_Control->driving_mode = kDRIVING_MODE_ECO;
        break;
    case CAN_VALUE_DRIVING_MODE_NORMAL:
    	Rx_Control->driving_mode = kDRIVING_MODE_NORMAL;
        break;
    case CAN_VALUE_DRIVING_MODE_SPORT:
    	Rx_Control->driving_mode = kDRIVING_MODE_SPORT;
        break;
    }

    /* Decodifica fallas de Control */
    switch (bus_can_input.estado_falla)
    {
    case CAN_VALUE_FAILURE_OK:
    	Rx_Control->failure = kFAILURE_OK;
        break;
    case CAN_VALUE_FAILURE_CAUTION1:
    	Rx_Control->failure = kFAILURE_CAUTION1;
        break;
    case CAN_VALUE_FAILURE_CAUTION2:
    	Rx_Control->failure = kFAILURE_CAUTION2;
    case CAN_VALUE_FAILURE_AUTOKILL:
    	Rx_Control->failure = kFAILURE_AUTOKILL;
        break;
    }
}

/**
 * @brief Decodifica los datos del BMS
 *
 * Decodifica las variables que se reciben del BMS por CAN y guarda
 * los datos en la estructura Rx_Bms del tipo rx_bms_vars_t y que
 * se encuentra en el bus_data.
 *
 */
static void DECODE_DATA_Decode_Bms(void)
{
	/* Decodifica las variables analógicas de BMS */
    Rx_Bms->voltaje = (rx_var_t)bus_can_input.voltaje_bms;

    Rx_Bms->corriente = (rx_var_t)bus_can_input.corriente_bms;

    Rx_Bms->potencia = (rx_var_t)bus_can_input.potencia_bms;

    Rx_Bms->nivel_bateria = (rx_var_t)bus_can_input.nivel_bateria_bms;
}

/**
 * @brief Decodifica los datos del Inversor
 *
 * Decodifica las variables que se reciben del inversor por CAN y guarda
 * los datos en la estructura Rx_Inversor del tipo rx_inversor_vars_t y
 * que se encuentra en el bus_data.
 *
 */
static void DECODE_DATA_Decode_Inversor(void)
{
	/* Decodifica las variables analógicas de Inversor */
    Rx_Inversor->velocidad = (rx_var_t)bus_can_input.velocidad_inv;
}
