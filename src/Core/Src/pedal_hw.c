/**
 * @file pedal_hw.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Configuración hardware de pedal
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pedal_hw.h"

/***********************************************************************************************************************
 * Macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/* Buffer lectura ADC DMA */
uint16_t adc_buf[ADC_BUF_LEN];

/** Bandera conversión ADC */
adc_conv_status_t flag_adc = ADC_CONV_NOT_COMPLETED;

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

void PEDAL_HW_Init(void)
{
	/* Initialize DMA */
	MX_DMA_Init();

	/* Initialize ADC1 */
	MX_ADC1_Init();

	/* Initialize time base timer for ADC triggering */
	MX_TIM3_Init();

	/* Start ADC with DMA */
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, ADC_BUF_LEN);

	/* Start time base trigger ADC timer */
	HAL_TIM_Base_Start(&htim3);
}

/***********************************************************************************************************************
 * Exported functions implementation
 **********************************************************************************************************************/

/* Called when buffer is completely filled */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	/* Turn on LED 3 (yellow LED) */
	BSP_LED_Toggle(LED3);

	/* Start ADC DMA again */
	HAL_ADC_Start_DMA(hadc, (uint32_t*)adc_buf, ADC_BUF_LEN);

	/* The flag indicates that the callback was called */
	flag_adc = ADC_CONV_COMPLETED;
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/
