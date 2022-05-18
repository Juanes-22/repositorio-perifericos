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
		.btn_modo_manejo = kBTN_NONE,
		.btn_hm1 = kBTN_NOT_PRESSED,
		.btn_hm2 = kBTN_NOT_PRESSED,
		.hm_state = kHOMBRE_MUERTO_OFF,

		.pedal = 0.0,

		.Rx_Control = {.control_ok = kMODULE_INFO_ERROR},
		.Rx_Bms = {0},
		.Rx_Inversor = {0}
};

/* Inicialización de bus de salida CAN (bus 2) */
typedef_bus2_t bus_can_output = { .perifericos_ok = CAN_VALUE_MODULE_OK };

/* Inicialización de bus de recepción CAN (bus 3) */
typedef_bus3_t bus_can_input = { .control_ok = CAN_VALUE_MODULE_OK };
