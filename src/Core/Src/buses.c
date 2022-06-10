/**
 * @file buses.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Buses arquitectura de firmware de Periféricos
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "buses.h"

/***********************************************************************************************************************
 * Buses initialization
 **********************************************************************************************************************/

/* Inicialización de bus de datos (bus 1) */
typedef_bus1_t bus_data =
{
	/* Variable botón modo de manejo presionado */
	.btn_modo_manejo = kBTN_NONE,

	/* Variables botones hombre muerto */
	.btn_hm1 = kBTN_NOT_PRESSED,
	.btn_hm2 = kBTN_NOT_PRESSED,

	/* Variable estado de hombre muerto */
	.hm_state = kHOMBRE_MUERTO_OFF,

	/* Variables lectura ADC pedal */
	.adc_reading = 0U,
	.pedal = 0.0,

	/* Estructuras con variables decodificadas de los módulos */
	.Rx_Control = 
	{
		.driving_mode = kDRIVING_MODE_NORMAL,
		.failure = kFAILURE_CAUTION1,
		.control_ok = kMODULE_INFO_ERROR
	},
	.Rx_Bms = {0},
	.Rx_Inversor = {0}
};

/* Inicialización de bus de salida CAN (bus 2) */
typedef_bus2_t bus_can_output =
{
	.pedal = 0,
	.hombre_muerto = CAN_VALUE_HOMBRE_MUERTO_OFF,
	.botones_cambio_estado = CAN_VALUE_BTN_NONE,
	.perifericos_ok = CAN_VALUE_MODULE_IDLE
};

/* Inicialización de bus de recepción CAN (bus 3) */
typedef_bus3_t bus_can_input =
{
	.estado_manejo = CAN_VALUE_DRIVING_MODE_NORMAL,
	.estado_falla = CAN_VALUE_FAILURE_CAUTION1,
	.control_ok = CAN_VALUE_MODULE_OK
};
