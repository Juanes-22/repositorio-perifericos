/**
 * @file can_hw.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Código hardware de CAN
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "can_hw.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/* CAN object instance */
CAN_t can_obj;

/** Bandera mensaje recibido CAN */
can_rx_status_t flag_rx_can = CAN_MSG_NOT_RECEIVED;

/** Bandera transmisión CAN */
can_tx_status_t flag_tx_can = CAN_TX_READY;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void CAN_HW_Init(void)
{
  /* Initialize time base timer for CAN triggering */
  MX_TIM7_Init();

  /* Inicializa CAN usando driver */
  CAN_API_Init( &can_obj,
				STANDARD_FRAME,
				NORMAL_MSG,
				CAN_Wrapper_Init,
				CAN_Wrapper_TransmitData,
				CAN_Wrapper_ReceiveData,
				CAN_Wrapper_DataCount);

  /* Initialize CAN2 */
  //MX_CAN2_Init();

  /* Start CAN module */
  HAL_CAN_Start(&hcan2);

  /* Activate CAN notification (enable interrupts) */
  HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);

  /* Start time base trigger CAN timer */
  HAL_TIM_Base_Start_IT(&htim7);
}

/***********************************************************************************************************************
 * Exported functions implementation
 **********************************************************************************************************************/

/* Callback mensaje CAN recibido */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan)
{
    /* The flag indicates that the callback was called */
    flag_rx_can = CAN_MSG_RECEIVED;
}

/* Callback timer trigger de transmisión de datos de bus de salida CAN a módulo CAN */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
  /* Toggle LED 1 (Red LED) */
  BSP_LED_Toggle(LED1);

  /* The flag indicates that the callback was called */
  flag_tx_can = CAN_TX_READY;
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/
