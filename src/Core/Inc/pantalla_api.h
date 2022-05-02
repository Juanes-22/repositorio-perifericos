/**
 * @file pantalla_api.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para pantalla_api.c
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _PANTALLA_API_H_
#define _PANTALLA_API_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

void PANTALLA_API_SendtoGauge(char *obj, uint16_t value,UART_HandleTypeDef huart);

void PANTALLA_API_SendtoNum(char *obj, uint16_t value,UART_HandleTypeDef huart);

void PANTALLA_API_SendtoPB(char *obj, uint16_t value,UART_HandleTypeDef huart);

void PANTALLA_API_SendtoTxt(char *obj, uint16_t value,UART_HandleTypeDef huart);

void PANTALLA_API_SendtoImage(char *obj, uint16_t value,UART_HandleTypeDef huart);

#endif /* _PANTALLA_API_H_ */
