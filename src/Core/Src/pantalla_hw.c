/*
 * pantalla_hw.c
 *
 *  Created on: 24/04/2022
 *      Author: Juan
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pantalla_hw.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void PANTALLA_HW_Init(void)
{
    MX_USART6_UART_Init();
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/