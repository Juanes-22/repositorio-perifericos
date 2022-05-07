/**
 * @file pantalla.c
 * @author Subgrupo Control y Periféricos - Elektron Motorsports
 * @brief Envío de datos a pantalla Nextion
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/

#include "pantalla.h"

/***********************************************************************************************************************
 * Private macros
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private variables definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private functions prototypes
 **********************************************************************************************************************/

static void PANTALLA_Demo(void);

/***********************************************************************************************************************
 * Public functions implementation
 **********************************************************************************************************************/

/**
 * @brief Función principal de manejo de pantalla Nextion.
 *
 * No es static, por lo que puede ser usada por otros archivos.
 *
 * @param None
 * @retval None
 */
void PANTALLA_Process(void)
{
    PANTALLA_Demo();
}

/***********************************************************************************************************************
 * Private functions implementation
 **********************************************************************************************************************/

static void PANTALLA_Demo(void)
{
    int value = 0;
    int img;

    for (value = 0; value >= 100; value++)
    {
        if (value >= 0 && value <= 33)
        {
            img = 1;
        }
        else if (value > 33 && value <= 66)
        {
            img = 2;
        }
        else if (value > 66 && value <= 100)
        {
            img = 3;
        }

        PANTALLA_API_SendtoImage("bat_icon.pic", value, huart6);
        PANTALLA_API_SendtoImage("driving_mode.pic", img, huart6);
        PANTALLA_API_SendtoImage("warning.pic", img, huart6);

        PANTALLA_API_SendtoTxt("bat_level.txt", value, huart6);
        PANTALLA_API_SendtoTxt("bat_voltage.txt", value, huart6);
        PANTALLA_API_SendtoTxt("power.txt", value, huart6);
        PANTALLA_API_SendtoTxt("speed.txt", value, huart6);

        PANTALLA_API_SendtoPB("speed_bar", value, huart6);

        HAL_Delay(40);
    }
}
