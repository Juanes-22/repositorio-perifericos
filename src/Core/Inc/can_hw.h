/*
 * can_hw.h
 *
 *  Created on: 24/04/2022
 *      Author: Juan
 */

#ifndef _CAN_HW_H_
#define _CAN_HW_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "can.h"
#include "tim.h"

#include "can_api.h"
#include "can_wrapper.h"

#include "main.h"

/***********************************************************************************************************************
 * Types declarations
 **********************************************************************************************************************/

/**
 * @brief Tipo de dato can_rx_status_t para estado de recepción de mensaje CAN
 *
 */
typedef enum
{
	CAN_MSG_RECEIVED = 0, 		/**< Mensaje CAN recibido */
    CAN_MSG_NOT_RECEIVED   		/**< Mensaje CAN no recibido */
} can_rx_status_t;

/**
 * @brief Tipo de dato can_tx_status_t para estado de transmisión de mensaje CAN
 *
 */
typedef enum
{
    CAN_TX_READY = 0, 		/**< Listo para transmitir mensaje CAN */
    CAN_TX_NOT_READY   		/**< No listo para transmitir mensaje CAN */
} can_tx_status_t;

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

void CAN_HW_Init(void);

/***********************************************************************************************************************
 * Global variables declarations
 **********************************************************************************************************************/

/** Bandera mensaje recibido CAN */
extern can_rx_status_t flag_rx_can;

/** Bandera transmisión CAN */
extern can_tx_status_t flag_tx_can;

#endif /* _CAN_HW_H_ */
