/**
 * @file indicators.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Generación de indicadores de tarjeta Periféricos
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "indicators.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/** @brief Duración de blink de los LEDs */
#define BLINK_TIME              250U

/** @brief Duración para apagado de los LEDs */
#define LEDS_TURNOFF_TIME       3000U

/** @brief Duración para apagado del buzzer */
#define BUZZER_TURNOFF_TIME     2000U

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Indicación de que la tarjeta ha finalizado la inicialización.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void INDICATORS_Finish_StartUp(void)
{
    uint32_t tickstart;

    uint32_t blink_tickstart;

    BSP_BUZZER_On();

    tickstart = HAL_GetTick();      // get ticks for the turn off time of LEDs and buzzer

    blink_tickstart = tickstart;    // ticks for the blinking of the LEDs

    BSP_LED_Off(LED1);
    BSP_LED_Off(LED2);
    BSP_LED_Off(LED3);

    while(1)
    {
        if( (HAL_GetTick() - blink_tickstart) > BLINK_TIME )  		// 250ms
        {
            BSP_LED_Toggle(LED1);
            BSP_LED_Toggle(LED2);
            BSP_LED_Toggle(LED3);

            blink_tickstart = HAL_GetTick();
        }

        if( (HAL_GetTick() - tickstart) > BUZZER_TURNOFF_TIME )   	// 2s
        {
            BSP_BUZZER_Off();
        }

        if( (HAL_GetTick() - tickstart) > LEDS_TURNOFF_TIME )   	// 3s
        {
            BSP_LED_Off(LED1);
            BSP_LED_Off(LED2);
            BSP_LED_Off(LED3);

            break;  // startup is completed
        }
    }
}

/**
 * @brief Función principal bloque generación de indicadores.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void INDICATORS_Process(void)
{
	//BSP_LED_Off(LED1);
	//BSP_LED_Off(LED2);
	//BSP_LED_Off(LED3);

	asm("nop");
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/
