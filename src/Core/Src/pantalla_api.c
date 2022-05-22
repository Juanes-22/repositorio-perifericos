/**
 * @file pantalla_api.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Funciones para envío de datos a pantalla Nextion
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pantalla_api.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

uint8_t Cmd_End[3] = {0xFF, 0xFF, 0xFF}; // command end sequence

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void PANTALLA_API_SendtoGauge(char *obj, uint16_t value, UART_HandleTypeDef huart)
{
    char buf[30];
    value += 180; // 0 error

    if (value >= 360)
    {
        value = value - 360;
    }

    int len = sprintf(buf, "%s=%u", obj, value);

    HAL_UART_Transmit(&huart, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(&huart, Cmd_End, 3, 3000);
}

void PANTALLA_API_SendtoNum(char *obj, uint16_t value,UART_HandleTypeDef huart)
{
	char buf[30];
	int len = sprintf (buf,"%s=%u",obj,value);

	HAL_UART_Transmit(&huart, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart, Cmd_End, 3, 3000);
}

void PANTALLA_API_SendtoTxt(char *obj, uint16_t value,UART_HandleTypeDef huart)
{
	char buf[30];
	int len;

	if(strcmp("bat_level.txt",obj)==0){

		len = sprintf (buf,"%s=\"%u%%\"",obj,value);

	}else if(strcmp("power.txt",obj)==0){

		len = sprintf (buf,"%s=\"%u W\"",obj,value);

	}else if(strcmp("bat_voltage.txt",obj)==0){

		len = sprintf (buf,"%s=\"%u V\"",obj,value);

	}else{
		len = sprintf (buf,"%s=\"%u\"",obj,value);
	}

	HAL_UART_Transmit(&huart, (uint8_t *)buf, len, 1000);
	HAL_UART_Transmit(&huart, Cmd_End, 3, 3000);
}

void PANTALLA_API_SendtoPB(char *obj, uint16_t value,UART_HandleTypeDef huart)
{
    char buf[30];
    int len = sprintf(buf, "%s=%u", obj, value);

    HAL_UART_Transmit(&huart, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(&huart, Cmd_End, 3, 3000);
}

void PANTALLA_API_SendtoImage(char *obj, uint16_t value,UART_HandleTypeDef huart){

    char buf[30];
    int len;
    int pic;

    if (strcmp(obj, "bat_icon.pic") == 0)
    {
        if (value >= 0 && value <= 33)
        {
            pic = 28; // una barra
            len = sprintf(buf, "%s=%u", obj, pic);
        }
        else if (value > 33 && value <= 66)
        {
            pic = 29; // dos barras
            len = sprintf(buf, "%s=%u", obj, pic);
        }
        else if (value > 66 && value <= 100)
        {
            pic = 27; // tres barras
            len = sprintf(buf, "%s=%u", obj, pic);
        }
    }
    else if (strcmp(obj, "driving_mode.pic") == 0)
    {
        if (value == 1)
        {
            pic = 23; // eco
            len = sprintf(buf, "%s=%u", obj, pic);
        }
        else if (value == 2)
        {
            pic = 24; // normal
            len = sprintf(buf, "%s=%u", obj, pic);
        }
        else if (value == 3)
        {
            pic = 25; // sport
            len = sprintf(buf, "%s=%u", obj, pic);
        }
    }
    else if (strcmp(obj, "warning.pic") == 0)
    {
        if (value == 1)
        {
            pic = 33; // warning
            len = sprintf(buf, "%s=%u", obj, pic);
        }
        else if (value == 0)
        {
            pic = 32; // no warning
            len = sprintf(buf, "%s=%u", obj, pic);
        }
    }

    HAL_UART_Transmit(&huart, (uint8_t *)buf, len, 1000);
    HAL_UART_Transmit(&huart, Cmd_End, 3, 3000);
}
