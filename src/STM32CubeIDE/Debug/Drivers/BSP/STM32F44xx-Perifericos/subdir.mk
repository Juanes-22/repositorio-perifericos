################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/juane/OneDrive/Escritorio/elektron-stm32-workspace/Perifericos/Drivers/BSP/STM32F44x-Perifericos/stm32f4xx_perifericos.c 

OBJS += \
./Drivers/BSP/STM32F44xx-Perifericos/stm32f4xx_perifericos.o 

C_DEPS += \
./Drivers/BSP/STM32F44xx-Perifericos/stm32f4xx_perifericos.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F44xx-Perifericos/stm32f4xx_perifericos.o: C:/Users/juane/OneDrive/Escritorio/elektron-stm32-workspace/Perifericos/Drivers/BSP/STM32F44x-Perifericos/stm32f4xx_perifericos.c Drivers/BSP/STM32F44xx-Perifericos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/STM32F44x-Perifericos -I"C:/Users/juane/OneDrive/Escritorio/elektron-stm32-workspace/Perifericos/Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F44xx-2d-Perifericos

clean-Drivers-2f-BSP-2f-STM32F44xx-2d-Perifericos:
	-$(RM) ./Drivers/BSP/STM32F44xx-Perifericos/stm32f4xx_perifericos.d ./Drivers/BSP/STM32F44xx-Perifericos/stm32f4xx_perifericos.o

.PHONY: clean-Drivers-2f-BSP-2f-STM32F44xx-2d-Perifericos

