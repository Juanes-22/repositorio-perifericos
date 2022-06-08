/**
 * @file pantalla.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Código aplicativo para envío de datos a pantalla Nextion
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pantalla.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/** @brief Intervalo de tiempo de transmisión serial a pantalla Nextion en ms */
#define DISPLAY_TRANSMIT_INTERVAL_MS		100U

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void PANTALLA_Demo(void);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal de manejo de pantalla Nextion.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void PANTALLA_Process(void)
{
    PANTALLA_Demo();
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

static void PANTALLA_Demo(void)
{
	/* Ticks for serial transmit to Nextion display */
	static uint32_t tickstart = 0;

	int speed = 0;

	if((HAL_GetTick() - tickstart) > DISPLAY_TRANSMIT_INTERVAL_MS)
	{
		/* Turn on LED 3 (yellow LED) */
		BSP_LED_Toggle(LED3);

		/* Envía estado hombre muerto */
		if(bus_data.hm_state == kHOMBRE_MUERTO_ON)
		{
			PANTALLA_API_SendtoNum("is_warning.val", 1, huart6);
		}
		else if(bus_data.hm_state == kHOMBRE_MUERTO_OFF)
		{
			PANTALLA_API_SendtoNum("is_warning.val", 0, huart6);
		}

		/* Envía modo de manejo */
		if(bus_data.btn_modo_manejo == kBTN_ECO)
		{
			PANTALLA_API_SendtoImage("driving_mode.pic", 1, huart6);
		}
		else if(bus_data.btn_modo_manejo == kBTN_NORMAL)
		{
			PANTALLA_API_SendtoImage("driving_mode.pic", 2, huart6);
		}
		else if(bus_data.btn_modo_manejo == kBTN_SPORT)
		{
			PANTALLA_API_SendtoImage("driving_mode.pic", 3, huart6);
		}

		/* Envía velocidad */
		speed = (int) bus_data.pedal;

		if(speed == 100)
		{
			PANTALLA_API_SendtoTxt("speed.txt", 99, huart6);
		}
		else
		{
			PANTALLA_API_SendtoTxt("speed.txt", speed, huart6);
			PANTALLA_API_SendtoPB("speed_bar.val", speed, huart6);
		}

		/* Reset ticks */
		tickstart = HAL_GetTick();
	}
}
