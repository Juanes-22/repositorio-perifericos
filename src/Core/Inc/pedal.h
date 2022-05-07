/**
 * @file pedal.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para pedal.h
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _PEDAL_H_
#define _PEDAL_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pedal_hw.h"
#include "buses.h"

#include "main.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/**
 * @brief Función principal para el pedal. Se procesa y se guarda la lectura del ADC en el
 * bus de datos. Se envía lectura del ADC mapeada a bus de datos y a bus de salida CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param   None
 * @retval  None
 */
void PEDAL_Process(void);

#endif /* _PEDAL_H_ */
