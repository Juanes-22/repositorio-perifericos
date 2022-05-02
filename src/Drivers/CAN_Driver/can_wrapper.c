/**
 * @file can_wrapper.c
 * @author Subgrupo Control y Periféricos.
 * @brief Implementaciones funciones wrapper CAN para tarjeta de Periféricos.
 * @version 0.1
 * @date 2022-01-05
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "can_wrapper.h"

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/** @brief CAN handle structure instance */
static CAN_HandleTypeDef hcan2;

/** @brief CAN filter configuration structure instance */
static CAN_FilterTypeDef aFilterConfig;

/** @brief CAN Tx message header structure instance */
static CAN_TxHeaderTypeDef txHeader;

/** @brief CAN Rx message header structure definition */
static CAN_RxHeaderTypeDef rxHeader;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void CAN2_Init(void);

static void CAN2_FilterConfig(void);

static void CAN2_ActivateNotification(void);

static void CAN2_Start(void);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función wrapper inicialización de periférico CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param   None
 * @retval  None
 */
can_status_t CAN_Wrapper_Init(void)
{
    CAN2_Init();					// CAN2 peripheral initialization
    CAN2_FilterConfig();    		// CAN2 filter configuration
	CAN2_ActivateNotification();	// CAN2 enable interrupt
	CAN2_Start();					// CAN2 start the CAN module

	return CAN_STATUS_OK;
}

/**
 * @brief Función wrapper transmisión de datos CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param id Standard identifier
 * @param ide Type of identifier
 * @param rtr Type of frame
 * @param dlc Length of frame
 * @param data Data to transmit
 * @retval None
 */
can_status_t CAN_Wrapper_TransmitData(uint32_t id, uint8_t ide, uint8_t rtr, uint8_t dlc, uint8_t *data)
{
    uint32_t mailbox;

	txHeader.StdId = id;            // standard identifier value
	txHeader.DLC = dlc; 			// length of frame
	txHeader.IDE = CAN_ID_STD; 		// type of identifier
	txHeader.RTR = CAN_RTR_DATA;    // data frame

	HAL_CAN_AddTxMessage(&hcan2, &txHeader, data, &mailbox);

	if(mailbox == CAN_TX_MAILBOX2)
    {
		while( HAL_CAN_IsTxMessagePending(&hcan2, CAN_TX_MAILBOX0));
	}

	return CAN_STATUS_OK;
}

/**
 * @brief Función wrapper recepción de datos CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param id Received identifier
 * @param data Received data
 * @retval  None
 */
can_status_t CAN_Wrapper_ReceiveData(uint32_t *id, uint8_t *data)
{
    HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO0, &rxHeader, data);

    *id = rxHeader.StdId;	// received standard identifier

	return CAN_STATUS_OK;
}

/**
 * @brief Función wrapper conteo dato recibido por CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @return can_status_t
 */
can_status_t CAN_Wrapper_DataCount(void)
{
	return CAN_STATUS_OK;
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

/**
 * @brief STM32 CAN1 Initialization Function.
 *
 * @param None
 * @retval None
 */
static void CAN2_Init(void)
{
	hcan2.Instance = CAN2;
	hcan2.Init.Prescaler = 16;
	hcan2.Init.Mode = CAN_MODE_NORMAL;
	hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
	hcan2.Init.TimeSeg1 = CAN_BS1_1TQ;
	hcan2.Init.TimeSeg2 = CAN_BS2_1TQ;
	hcan2.Init.TimeTriggeredMode = DISABLE;
	hcan2.Init.AutoBusOff = DISABLE;
	hcan2.Init.AutoWakeUp = DISABLE;
	hcan2.Init.AutoRetransmission = DISABLE;
	hcan2.Init.ReceiveFifoLocked = DISABLE;
	hcan2.Init.TransmitFifoPriority = DISABLE;
	if (HAL_CAN_Init(&hcan2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
 * @brief STM32 CAN1 Filter Configuration Function.
 *
 * @param None
 * @retval None
 */
static void CAN2_FilterConfig(void)
{
	aFilterConfig.FilterBank = 0;
	aFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
	aFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	aFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	aFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
	aFilterConfig.SlaveStartFilterBank = 14;

	//aFilterConfig.FilterIdHigh = ID_PEDAL<<5;
	aFilterConfig.FilterIdLow = 0x000;
	//aFilterConfig.FilterMaskIdHigh = ID_PEDAL<<5;
	aFilterConfig.FilterMaskIdLow = 0x000;

	HAL_CAN_ConfigFilter(&hcan2, &aFilterConfig);

	aFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
	aFilterConfig.FilterBank = 1;
	aFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	aFilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
	aFilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
	//aFilterConfig.FilterIdHigh = ID_CORRIENTE_BMS<<5;
	//aFilterConfig.FilterIdLow = ID_POTENCIA_BMS<<5;
	//aFilterConfig.FilterMaskIdHigh = ID_NIVEL_BATERIA_BMS<<5;
	//aFilterConfig.FilterMaskIdLow = ID_VELOCIDAD_INV<<5;
	//aFilterConfig.SlaveStartFilterBank = 14;

	HAL_CAN_ConfigFilter(&hcan2, &aFilterConfig);
}

/**
 * @brief STM32 CAN1 Enable Interrupt
 *
 * @param None
 * @retval None
 */
static void CAN2_ActivateNotification(void)
{
	HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);
}

/**
 * @brief STM32 CAN1 Start the CAN Module
 *
 * @param None
 * @retval None
 */
static void CAN2_Start(void)
{
	HAL_CAN_Start(&hcan2);
}

