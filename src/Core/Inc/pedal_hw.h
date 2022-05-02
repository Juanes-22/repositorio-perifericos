/*
 * pedal_hw.h
 *
 *  Created on: 24/04/2022
 *      Author: Juan
 */

#ifndef _PEDAL_HW_H_
#define _PEDAL_HW_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "adc.h"
#include "dma.h"
#include "tim.h"

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
