/**
 * @file pantalla.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para pantalla.c
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _PANTALLA_H_
#define _PANTALLA_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

/* Application includes */
#include "pantalla_hw.h"
#include "pantalla_api.h"
#include "buses.h"

/* BSP (board support package) include */
#include "stm32f4xx_perifericos.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/**
 * @brief Función principal de manejo de pantalla Nextion.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void PANTALLA_Process(void);

#endif /* _PANTALLA_H_ */
