/**
 * @file botones.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Manejo de botones de modos de manejo y hombre muerto
 * @version 0.1
 * @date 2022-04-16
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "botones.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void BOTONES_Update_HM_Btns(void);

static void BOTONES_Update_HM_State(void);

static void BOTONES_Send_HM_State(hm_state_t to_send, typedef_bus2_t* bus_can_output);

static void BOTONES_Send_DrivingMode_Btn(btn_modo_manejo_t to_send, typedef_bus2_t* bus_can_output);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal de manejo de botones. Se manejan los
 * pulsadores de modo de manejo y los pulsadores de hombre muerto, y con ello
 * se modifican las variables en el bus de datos. Se envían a bus de salida CAN.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param   None
 * @retval  None
 */
void BOTONES_Process(void)
{
	BOTONES_Update_HM_Btns();									// actualice pulsadores de hombre muerto en bus de datos

	BOTONES_Update_HM_State();									// actualice estado de hombre muerto en bus de datos

	BOTONES_Send_HM_State( bus_data.hm_state, 
							&bus_can_output);					// envie estado hombre muerto a bus de salida CAN

	BOTONES_Send_DrivingMode_Btn( bus_data.btn_modo_manejo, 
									&bus_can_output);			// envie modo de manejo presionado a bus de salida CAN
}

/***********************************************************************************************************************
 * Exported functions implementation
 **********************************************************************************************************************/

/**
 * @brief Callback interrupción para pulsadores de modos de manejo. Actualiza
 * valor de pulsador de modo de manejo presionado en bus de datos.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param GPIO_Pin
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == BTN_ECO_Pin)
	{
		bus_data.btn_modo_manejo = kBTN_ECO;
	}
	if(GPIO_Pin == BTN_NORMAL_Pin)
	{
		bus_data.btn_modo_manejo = kBTN_NORMAL;
	}
	if(GPIO_Pin == BTN_SPORT_Pin)
	{
		bus_data.btn_modo_manejo = kBTN_SPORT;
	}
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función lectura de pulsadores de hombre muerto. Actualiza
 * valor de pulsador HM1 y HM2 en bus de datos.
 *
 * @param None
 * @retval None
 */
static void BOTONES_Update_HM_Btns(void)
{
	/* Pulsador 1 hombre muerto */
	if(HAL_GPIO_ReadPin(BTN_HM1_GPIO_Port, BTN_HM1_Pin) == GPIO_PIN_RESET)
	{
		bus_data.btn_hm1 = kBTN_PRESSED;
	}
	else
	{
		bus_data.btn_hm1 = kBTN_NOT_PRESSED;
	}

	/* Pulsador 2 hombre muerto */
	if(HAL_GPIO_ReadPin(BTN_HM2_GPIO_Port, BTN_HM2_Pin) == GPIO_PIN_RESET)
	{
		bus_data.btn_hm2 = kBTN_PRESSED;
	}
	else
	{
		bus_data.btn_hm2 = kBTN_NOT_PRESSED;
	}
}

/**
 * @brief Actualiza estado de hombre muerto de acuerdo
 * a los valores de pulsador HM1 y HM2 en el bus de datos.
 *
 * @param None
 * @retval None
 */
static void BOTONES_Update_HM_State(void)
{
	/* Ambos pulsadores de hombre muerto no presionados */
	if(bus_data.btn_hm1 == kBTN_NOT_PRESSED && bus_data.btn_hm2 == kBTN_NOT_PRESSED)
	{
		bus_data.hm_state = kHOMBRE_MUERTO_ON;
	}

	/* Cualquiera de los pulsadores de hombre muerto presionados */
	else if(bus_data.btn_hm1 == kBTN_PRESSED || bus_data.btn_hm2 == kBTN_PRESSED)
	{
		bus_data.hm_state = kHOMBRE_MUERTO_OFF;
	}
}

/**
 * @brief Envío de estado de hombre muerto a bus de salida CAN.
 *
 * @param to_send           Estado de hombre muerto a enviar
 * @param bus_can_output    Puntero a estructura de tipo typedef_bus2_t (bus de salida CAN)
 */
static void BOTONES_Send_HM_State(hm_state_t to_send, typedef_bus2_t* bus_can_output)
{
    /* Envío a bus de salida CAN */
    switch (to_send)
    {
    case kHOMBRE_MUERTO_ON:
        bus_can_output->hombre_muerto = CAN_VALUE_HM_PRESSED;
        break;
    case kHOMBRE_MUERTO_OFF:
        bus_can_output->hombre_muerto = CAN_VALUE_HM_NOT_PRESSED;
        break;
    default:
        break;
    }
}

/**
 * @brief Envío de modo de manejo presionado a bus de salida CAN.
 *
 * @param to_send           Modo de manejo presionado a enviar
 * @param bus_can_output    Puntero a estructura de tipo typedef_bus2_t (bus de salida CAN)
 */
static void BOTONES_Send_DrivingMode_Btn(btn_modo_manejo_t to_send, typedef_bus2_t* bus_can_output)
{
    /* Envío a bus de salida CAN */
    switch (to_send)
    {
    case kBTN_NONE:
        bus_can_output->botones_cambio_estado = CAN_VALUE_BTN_NONE;
        break;
    case kBTN_ECO:
        bus_can_output->botones_cambio_estado = CAN_VALUE_BTN_ECO;
        break;
    case kBTN_NORMAL:
        bus_can_output->botones_cambio_estado = CAN_VALUE_BTN_NORMAL;
        break;
    case kBTN_SPORT:
        bus_can_output->botones_cambio_estado = CAN_VALUE_BTN_SPORT;
        break;
    default:
        break;
    }
}
