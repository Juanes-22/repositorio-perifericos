/*
 * can_app.h
 *
 *  Created on: 20/04/2022
 *      Author: Juan
 */

#ifndef _CAN_APP_H_
#define _CAN_APP_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "can_api.h"
#include "can_hw.h"
#include "can_def.h"
#include "decode_data.h"
#include "buses.h"

#include "main.h"

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

/**
 * @brief Función principal de CAN a nivel de aplicación
 *
 * Guarda mensaje CAN recibido en bus de entrada CAN cuando se activa
 * bandera de recepción. Envía datos de bus de salida CAN cuando se
 * activa bandera de transmisión.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void CAN_APP_Process(void);

/**
 * @brief Función de envío de datos de bus de salida CAN a módulo CAN.
 *
 * Realiza el envío de las variables que se encuentran en el bus de salida CAN a módulo CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param bus_can_output Puntero a estructura de tipo typedef_bus2_t (bus de salida CAN)
 * @retval None
 */
void CAN_APP_Send_BusData(typedef_bus2_t *bus_can_output);

#endif /* _CAN_APP_H_ */
