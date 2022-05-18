/**
 * @file can_hw.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Código configuración hardware CAN
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

CAN_FilterTypeDef sFilterConfig;

CAN_TxHeaderTypeDef TxHeader;

CAN_RxHeaderTypeDef RxHeader;

uint8_t TxData[8];

uint8_t RxData[8];

uint32_t TxMailbox;

uint8_t msg_id = 0x30;

/* CAN object instance */
CAN_t can_obj;

/** Bandera mensaje recibido CAN */
can_rx_status_t flag_rx_can = CAN_MSG_NOT_RECEIVED;

/** Bandera transmisión CAN */
can_tx_status_t flag_tx_can = CAN_TX_READY;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void CAN_FilterConfig(void);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void CAN_HW_Init(void)
{
	/* Initialize time base timer for CAN triggering */
	MX_TIM7_Init();

	/* Initialize CAN1 */
	MX_CAN2_Init();

	/* Disable debug freeze */
	CAN2->MCR &= (~CAN_MCR_DBF);

	/* CAN filter configuration */
	CAN_FilterConfig();

	/* Start CAN module */
	if (HAL_CAN_Start(&hcan2) != HAL_OK)
	{
		Error_Handler();
	}

	/* Activate CAN notification (enable interrupts) */
	if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		Error_Handler();		// notification Error
	}

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

    /* Get the received message */
	HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &RxHeader, RxData);
}

/* Callback timer trigger de transmisión de datos de bus de salida CAN a módulo CAN */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim == &htim7)
	{
		/* Toggle LED 1 (Red LED) */
		BSP_LED_Toggle(LED1);

		/* The flag indicates that the callback was called */
		flag_tx_can = CAN_TX_READY;
	}
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

static void CAN_FilterConfig(void)
{
	sFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
	sFilterConfig.FilterBank = 1;							// CAN 1 [0..13]
	sFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;

	sFilterConfig.FilterIdHigh = 0x30 << 5;					// msg_id << 5;  // 000 0011 0000
	sFilterConfig.FilterIdLow = 0;
	sFilterConfig.FilterMaskIdHigh = 0x3F << 5; 			// msg_id << 5;  // 000 0011 1111
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;  		// ID // 001 0011 0000
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.SlaveStartFilterBank = 0;

	if (HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig)!= HAL_OK)
	{
		Error_Handler();
	}
}
