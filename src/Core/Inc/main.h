/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_HM1_Pin GPIO_PIN_3
#define BTN_HM1_GPIO_Port GPIOE
#define BTN_HM2_Pin GPIO_PIN_4
#define BTN_HM2_GPIO_Port GPIOE
#define LED_ECO_Pin GPIO_PIN_9
#define LED_ECO_GPIO_Port GPIOC
#define BTN_ECO_Pin GPIO_PIN_8
#define BTN_ECO_GPIO_Port GPIOA
#define LED_NORMAL_Pin GPIO_PIN_9
#define LED_NORMAL_GPIO_Port GPIOA
#define BTN_NORMAL_Pin GPIO_PIN_10
#define BTN_NORMAL_GPIO_Port GPIOA
#define LED_SPORT_Pin GPIO_PIN_11
#define LED_SPORT_GPIO_Port GPIOA
#define BTN_SPORT_Pin GPIO_PIN_12
#define BTN_SPORT_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
