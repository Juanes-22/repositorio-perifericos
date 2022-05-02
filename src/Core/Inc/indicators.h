/**
 * @file indicators.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para indicators.c
 * @version 0.1
 * @date 2022-04-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _INDICATORS_H_
#define _INDICATORS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "buses.h"

#include "main.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/**
 * @brief Función principal bloque generación de indicadores.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void INDICATORS_Process(void);

/**
 * @brief Indicación de que la tarjeta ha finalizado la inicialización.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void INDICATORS_Finish_StartUp(void);


#endif /* _INDICATORS_H_ */
