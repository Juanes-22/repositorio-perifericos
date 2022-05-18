/**
 * @file app_perifericos.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Código aplicativo de tarjeta Periféricos
 * @version 0.1
 * @date 2022-04-20
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "app_perifericos.h"

#include "buses.h"
#include "botones.h"
#include "pedal.h"
#include "pantalla.h"
#include "indicators.h"
#include "decode_data.h"
#include "can_app.h"

#include "main.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/** Duración de blink de LED de estado kWAITING_ECHO */
#define BLINK_TIME              250U

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/** @brief Estados posibles de la máquina de estados */
enum App_States
{
	kWAITING_ECHO = 0,      	/**< Estado WAITING_ECHO */
    kRUNNING,       			/**< Estado RUNNING */
};

/** @brief Estado de la máquina de estados */
static uint8_t app_state = kWAITING_ECHO;

/** Para blink LED de estado kWAITING_ECHO */
static uint32_t blink_tickstart;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void MX_APP_Init(void)
{
    /* Initialize board LEDs */
    BSP_LED_Init(LED1);
    BSP_LED_Init(LED2);
    BSP_LED_Init(LED3);

    /* Initialize board buzzer */
    BSP_BUZZER_Init();

    /* Initialize hardware */
    BOTONES_HW_Init();
    PEDAL_HW_Init();
    PANTALLA_HW_Init();
    CAN_HW_Init();

    /* Indicate that initialization was completed */
    for(int i=0; i<3; i++)
    {
    	BSP_LED_On(LED1);
    	BSP_LED_On(LED2);
    	BSP_LED_On(LED3);

    	HAL_Delay(200);

    	BSP_LED_Off(LED1);
    	BSP_LED_Off(LED2);
    	BSP_LED_Off(LED3);

    	HAL_Delay(200);
    }
}

void MX_APP_Process(void)
{
	switch (app_state)
	{

	/* Estado esperando echo de Tarjeta de Control */
	case kWAITING_ECHO:

		/* Ticks for the blinking of the LED */
		blink_tickstart = HAL_GetTick();

		while(1)
		{
			if( (HAL_GetTick() - blink_tickstart) > BLINK_TIME )
			{
				/* Toggle LED 1 (Red LED) */
				BSP_LED_Toggle(LED1);

				blink_tickstart = HAL_GetTick();
			}

			if (bus_can_input.control_ok == CAN_VALUE_MODULE_OK)
			{
				HAL_Delay(500);

				/* Send perifericos_ok MODULE_OK response */
				bus_can_output.perifericos_ok = CAN_VALUE_MODULE_OK;
				//CAN_APP_Send_BusData(&bus_can_output);

				/* Indicate that start up has finished */
				INDICATORS_Finish_StartUp();

				app_state = kRUNNING;

				break;
			}
		}
		break;

	/* Estado Tarjeta de Periféricos running */
	case kRUNNING:

	    BOTONES_Process();

	    PEDAL_Process();

	    PANTALLA_Process();

	    INDICATORS_Process();

	    DECODE_DATA_Process();

	    //CAN_APP_Process();

		break;
	}
}
