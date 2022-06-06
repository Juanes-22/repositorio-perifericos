/**
 * @file pedal_hw.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Archivo header para pedal_hw.c
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _PEDAL_HW_H_
#define _PEDAL_HW_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

/* BSP (board support package) include */
#include "stm32f4xx_perifericos.h"

/* STM32 specific hardware configuration includes */
#include "adc.h"
#include "dma.h"
#include "tim.h"

/* STM32 HAL include */
#include "main.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/* Tamaño de buffer de ADC */
#define ADC_BUF_LEN 				10

/***********************************************************************************************************************
 * Types declarations
 **********************************************************************************************************************/

/**
 * @brief Tipo de dato adc_conv_status_t para estado conversión ADC
 *
 */
typedef enum
{
    ADC_CONV_COMPLETED = 0, 		/**< Conversión ADC completada */
    ADC_CONV_NOT_COMPLETED   		/**< Conversión ADC no completada */
} adc_conv_status_t;

/***********************************************************************************************************************
 * Public function prototypes
 **********************************************************************************************************************/

void PEDAL_HW_Init(void);

/***********************************************************************************************************************
 * Global variables declarations
 **********************************************************************************************************************/

/* Buffer lectura ADC DMA */
extern uint16_t adc_buf[ADC_BUF_LEN];

/** Bandera conversión ADC */
extern adc_conv_status_t flag_adc;

#endif /* _PEDAL_HW_H_ */
