/*
 * pedal.h
 *
 *  Created on: 18/04/2022
 *      Author: Juan
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
