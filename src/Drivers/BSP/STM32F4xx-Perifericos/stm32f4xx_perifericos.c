/**
 * @file stm32f4xx_perifericos.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Driver BSP (board support package) para tarjeta de Periféricos
 * @version 0.1
 * @date 2022-04-18
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "stm32f4xx_perifericos.h"

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/** @brief Board LEDs PORTs array */
static GPIO_TypeDef*  LED_PORT[LEDn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT};

/** @brief Board LEDs PINS array */
static const uint16_t LED_PIN[LEDn] = {LED1_GPIO_PIN, LED2_GPIO_PIN, LED3_GPIO_PIN};

/* @brief Board BUZZER TIM handle */
static TIM_HandleTypeDef BUZZER_htim;

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Configures Buzzer PWM.
 *
 * @param None
 * @retval BSP status
 */
int32_t BSP_BUZZER_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};

	/* Configure the Buzzer PWM Timer */
    BUZZER_htim.Instance = BUZZER_PWM_TIM_INSTANCE;
    BUZZER_htim.Init.Prescaler = 0;
    BUZZER_htim.Init.CounterMode = TIM_COUNTERMODE_UP;
    BUZZER_htim.Init.Period = 39062;
    BUZZER_htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    BUZZER_htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
    HAL_TIM_Base_Init(&BUZZER_htim);

    BUZZER_TIM_CLK_ENABLE();	// TIM peripheral clock enable

    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource(&BUZZER_htim, &sClockSourceConfig);

    HAL_TIM_PWM_Init(&BUZZER_htim);

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = 3906;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&BUZZER_htim, &sConfigOC, BUZZER_PWM_TIM_CHANNEL);

    /* HAL_TIM_MspPostInit:  */

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    BUZZER_GPIO_CLK_ENABLE();
    /** BUZZER GPIO Configuration
        PA2     ------> TIM9_CH1
     */
    GPIO_InitStruct.Pin = BUZZER_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TIM9;

    HAL_GPIO_Init(BUZZER_GPIO_PORT, &GPIO_InitStruct);

    return BSP_ERROR_NONE;
}

/**
 * @brief DeInit Buzzer.
 *
 * @param None
 * @note Buzzer DeInit does not disable the GPIO clock nor disable the Mfx
 * @return BSP Status
 */
int32_t BSP_BUZZER_DeInit(void)
{
    /* Turn off BUZZER */
	HAL_TIM_PWM_Stop(&BUZZER_htim, BUZZER_PWM_TIM_CHANNEL);

    /* DeInit the BUZZER PWM timer */
    HAL_TIM_PWM_DeInit(&BUZZER_htim);

    return BSP_ERROR_NONE;
}

/**
 * @brief Turns Buzzer On.
 *
 * @param None
 * @return BSP Status
 */
int32_t BSP_BUZZER_On(void)
{
	HAL_TIM_PWM_Start(&BUZZER_htim, TIM_CHANNEL_1);

    return BSP_ERROR_NONE;
}

/**
 * @brief Turns Buzzer Off.
 *
 * @param None
 * @return BSP Status
 */
int32_t BSP_BUZZER_Off(void)
{
    HAL_TIM_PWM_Stop(&BUZZER_htim, TIM_CHANNEL_1);

    return BSP_ERROR_NONE;
}

/**
 * @brief Configures LED GPIO.
 *
 * @param Led: Led to be configured.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 *
 * @return BSP Status
 */
int32_t BSP_LED_Init(Led_TypeDef Led)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Enable the GPIO_LED Clock */
    LEDx_GPIO_CLK_ENABLE(Led);

    /* Configure the GPIO_LED pin */
    GPIO_InitStruct.Pin = LED_PIN[Led];
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(LED_PORT[Led], &GPIO_InitStruct);
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);

    return BSP_ERROR_NONE;
}

/**
 * @brief DeInit LEDs.
 *
 * @param Led: LED to be de-init.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 * @note Led DeInit does not disable the GPIO clock nor disable the Mfx
 * @return BSP Status
 */
int32_t BSP_LED_DeInit(Led_TypeDef Led)
{
    /* Turn off LED */
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);

    /* DeInit the GPIO_LED pin */
    HAL_GPIO_DeInit(LED_PORT[Led], LED_PIN[Led]);

    return BSP_ERROR_NONE;
}

/**
 * @brief Turns selected LED On.
 *
 * @param Led: Specifies the Led to be set on.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 * @return BSP Status
 */
int32_t BSP_LED_On(Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);

    return BSP_ERROR_NONE;
}

/**
 * @brief Turns selected LED Off.
 *
 * @param Led: Specifies the Led to be set off.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 * @return BSP Status
 */
int32_t BSP_LED_Off(Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);

    return BSP_ERROR_NONE;
}

/**
 * @brief Toggles the selected LED.
 *
 * @param Led: Specifies the Led to be toggled.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 * @return BSP Status
 */
int32_t BSP_LED_Toggle(Led_TypeDef Led)
{
    HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);

    return BSP_ERROR_NONE;
}

/**
 * @brief Get the status of the selected LED.
 *
 * @param Led: Specifies the Led to get its state.
 *        This parameter can be one of the following values:
 *          @arg LED1
 *          @arg LED2
 *          @arg LED3
 * @return BSP Status
 */
int32_t BSP_LED_GetState(Led_TypeDef Led)
{
    return (int32_t)HAL_GPIO_ReadPin(LED_PORT[Led], LED_PIN[Led]);

    return BSP_ERROR_NONE;
}

