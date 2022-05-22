/**
 * @file stm32f4xx_perifericos.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para stm32f4xx_perifericos.c
 * @version 0.1
 * @date 2022-04-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _STM32F4XX_PERIFERICOS_H_
#define _STM32F4XX_PERIFERICOS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "stm32f4xx_hal.h"
#include "stm32f4xx_perifericos_errno.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/** @addtogroup BSP
  * @brief Board Support Package.
  * @{
  */

/** @addtogroup VULCANO_PERIPHERALS_BOARD VULCANO-PERIPHERALS-BOARD
  * @{
  */

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL LOW LEVEL
  * @{
  */

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL LOW LEVEL LED Constants
  * @{
  */
#define LEDn                                    3

#define LED1_GPIO_PIN                           GPIO_PIN_3
#define LED1_GPIO_PORT                          GPIOD
#define LED1_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOD_CLK_DISABLE()

#define LED2_GPIO_PIN                           GPIO_PIN_4
#define LED2_GPIO_PORT                          GPIOD
#define LED2_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOD_CLK_DISABLE()

#define LED3_GPIO_PIN                           GPIO_PIN_5
#define LED3_GPIO_PORT                          GPIOD
#define LED3_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOD_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOD_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)         __HAL_RCC_GPIOD_CLK_ENABLE()
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)       	__HAL_RCC_GPIOD_CLK_DISABLE()
/**
  * @}
  */

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL LOW LEVEL BUZZER Constants
  * @{
  */
#define BUZZER_PWM_TIM_INSTANCE					TIM2
#define BUZZER_PWM_TIM_CHANNEL					TIM_CHANNEL_3
#define BUZZER_GPIO_PIN                        	GPIO_PIN_2
#define BUZZER_GPIO_PORT                        GPIOA
#define BUZZER_GPIO_CLK_ENABLE()                __HAL_RCC_GPIOA_CLK_ENABLE()
#define BUZZER_GPIO_CLK_DISABLE()               __HAL_RCC_GPIOA_CLK_DISABLE()
#define BUZZER_TIM_CLK_ENABLE()					__HAL_RCC_TIM2_CLK_ENABLE()
#define BUZZER_TIM_CLK_DISABLE()				__HAL_RCC_TIM2_CLK_DISABLE()
/**
  * @}
  */

/***********************************************************************************************************************
 * Types declarations
 **********************************************************************************************************************/

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL_Exported_Types LOW LEVEL Exported Types
  * @{
  */
typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
}Led_TypeDef;
/**
  * @}
  */

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL_LED_Functions LOW LEVEL LED Functions
  * @{
  */

int32_t    BSP_LED_Init(Led_TypeDef Led);

int32_t    BSP_LED_DeInit(Led_TypeDef Led);

int32_t    BSP_LED_On(Led_TypeDef Led);

int32_t    BSP_LED_Off(Led_TypeDef Led);

int32_t    BSP_LED_Toggle(Led_TypeDef Led);

int32_t    BSP_LED_GetState(Led_TypeDef Led);

/**
  * @}
  */

/** @defgroup VULCANO_PERIPHERALS_BOARD_LOW_LEVEL_BUZZER_Functions LOW LEVEL BUZZER Functions
  * @{
  */

int32_t    BSP_BUZZER_Init(void);

int32_t    BSP_BUZZER_DeInit(void);

int32_t    BSP_BUZZER_On(void);

int32_t    BSP_BUZZER_Off(void);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* _STM32F4XX_PERIFERICOS_H_ */
