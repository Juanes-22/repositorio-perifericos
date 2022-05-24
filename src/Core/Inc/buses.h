/**
 * @file buses.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para buses.c
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _BUSES_H_
#define _BUSES_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "types.h"
#include "can_def.h"

/***********************************************************************************************************************
 * Types declarations
 **********************************************************************************************************************/

/**
 * @brief Bus 1: bus de variables internas
 *
 */
typedef struct bus1
{
	/* Variable botón modo de manejo presionado */
	btn_modo_manejo_t 		btn_modo_manejo;

	/* Variables botones hombre muerto */
	btn_state_t 			btn_hm1;
	btn_state_t 			btn_hm2;

	/* Variable estado de hombre muerto */
	hm_state_t 				hm_state;

	/* Variables lectura ADC pedal */
	uint32_t 				adc_reading;
	float 					pedal;

	/* Estructuras con variables decodificadas de los módulos */
	rx_control_vars_t		Rx_Control;
	rx_bms_vars_t           Rx_Bms;
	rx_inversor_vars_t		Rx_Inversor;

} typedef_bus1_t;

/**
 * @brief Bus 2: bus de variables que se transmiten por CAN
 *
 */
typedef struct bus2
{
	uint8_t pedal;					    /**< CAN 0x002 */
	uint8_t hombre_muerto;			    /**< CAN 0x003 */
	uint8_t botones_cambio_estado;	    /**< CAN 0x004 */
	uint8_t perifericos_ok;			    /**< CAN 0x005 */

} typedef_bus2_t;

/**
 * @brief Bus 3: bus de variables que se reciben por CAN
 *
 */
typedef struct bus3
{
	uint8_t estado_manejo;			    /**< CAN 0x010 */
	uint8_t estado_falla;			    /**< CAN 0x011 */
	uint8_t control_ok;				    /**< CAN 0x014 */

	uint8_t voltaje_bms;			    /**< CAN 0x020 */
	uint8_t corriente_bms;			    /**< CAN 0x021 */
	uint8_t potencia_bms;			    /**< CAN 0x023 */
	uint8_t nivel_bateria_bms;		    /**< CAN 0x025 */

	uint8_t velocidad_inv;			    /**< CAN 0x040 */

} typedef_bus3_t;

/***********************************************************************************************************************
 * Global variables declarations
 **********************************************************************************************************************/

/** @brief Bus 1: Bus de datos */
extern typedef_bus1_t bus_data;

/** @brief Bus 2: Bus de transmisión de datos CAN */
extern typedef_bus2_t bus_can_output;

/** @brief Bus 3: Bus de recepción de datos CAN */
extern typedef_bus3_t bus_can_input;

#endif /* _BUSES_H_ */
