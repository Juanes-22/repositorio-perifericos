/**
 * @file botones.h
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para botones.c
 * @version 0.1
 * @date 2022-04-16
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef _BOTONES_H_
#define _BOTONES_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

/* Application includes */
#include "botones_hw.h"
#include "buses.h"

/* CAN application includes */
#include "can_def.h"

/* STM32 HAL include */
#include "main.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/**
 * @brief Función principal de manejo de botones. Se manejan los pulsadores de 
 * modo de manejo y los pulsadores de hombre muerto, y con ello se modifican las 
 * variables en el bus de datos. Se envían a bus de salida CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param   None
 * @retval  None
 */
void BOTONES_Process(void);

#endif /* _BOTONES_H_ */
