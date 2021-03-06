/**
 * @file botones_hw.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para botones_hw.c
 * @version 0.1
 * @date 2022-04-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _BOTONES_HW_H_
#define _BOTONES_HW_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

/* STM32 specific hardware configuration includes */
#include "gpio.h"

/* STM32 HAL include */
#include "main.h"

/***********************************************************************************************************************
 * Types declarations
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

void BOTONES_HW_Init(void);

/***********************************************************************************************************************
 * Global variables declarations
 **********************************************************************************************************************/

#endif /* _BOTONES_HW_H_ */
