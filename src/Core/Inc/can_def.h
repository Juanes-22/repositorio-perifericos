/**
 * @file can_def.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Definiciones para IDs y valores de CAN
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _CAN_DEF_H_
#define _CAN_DEF_H_

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/********************************************************************************
 *                                CAN IDs                                       *
 *******************************************************************************/

/* --------------------------- ID Transmition -------------------------------- */

#define CAN_ID_PEDAL					0x002
#define CAN_ID_HOMBRE_MUERTO			0x003
#define CAN_ID_BOTONES_CAMBIO_ESTADO	0x004
#define CAN_ID_PERIFERICOS_OK			0x005

/* ---------------------------- ID Reception --------------------------------- */

#define CAN_ID_ESTADO_MANEJO 			0x010
#define CAN_ID_ESTADO_FALLA				0x011
#define CAN_ID_CONTROL_OK				0x014

#define CAN_ID_VOLTAJE_BMS				0x020
#define	CAN_ID_CORRIENTE_BMS			0x021
#define CAN_ID_POTENCIA_BMS				0x023
#define	CAN_ID_NIVEL_BATERIA_BMS		0x025

#define CAN_ID_VELOCIDAD_INVERSOR		0x040

/********************************************************************************
 *                                CAN values                                    *
 *******************************************************************************/

/* ----------------------------- hombre_muerto ------------------------------- */

#define CAN_VALUE_HM_PRESSED			0x01
#define CAN_VALUE_HM_NOT_PRESSED		0x02

/* -------------------------- botones_cambio_estado -------------------------- */

#define CAN_VALUE_BTN_NONE				0x04
#define CAN_VALUE_BTN_ECO				0x02
#define CAN_VALUE_BTN_NORMAL			0x01
#define CAN_VALUE_BTN_SPORT				0x03

/* ------------------------ perifericos_ok, control_ok ------------------------ */

#define CAN_VALUE_MODULE_IDLE           0x00
#define CAN_VALUE_MODULE_OK          	0x01
#define CAN_VALUE_MODULE_ERROR       	0x02

/* ------------------------------ estado_manejo ------------------------------ */

#define CAN_VALUE_DRIVING_MODE_ECO		0x03
#define CAN_VALUE_DRIVING_MODE_NORMAL 	0x02
#define CAN_VALUE_DRIVING_MODE_SPORT	0x04

/* ------------------------------ estado_falla ------------------------------- */

#define CAN_VALUE_FAILURE_OK			0x00
#define CAN_VALUE_FAILURE_CAUTION1     	0x01
#define CAN_VALUE_FAILURE_CAUTION2		0x02
#define CAN_VALUE_FAILURE_AUTOKILL		0x03

#endif /* _CAN_DEF_H_ */
