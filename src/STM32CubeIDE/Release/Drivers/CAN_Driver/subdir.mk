################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Drivers/CAN_Driver/can_api.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Drivers/CAN_Driver/can_wrapper.c 

OBJS += \
./Drivers/CAN_Driver/can_api.o \
./Drivers/CAN_Driver/can_wrapper.o 

C_DEPS += \
./Drivers/CAN_Driver/can_api.d \
./Drivers/CAN_Driver/can_wrapper.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CAN_Driver/can_api.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Drivers/CAN_Driver/can_api.c Drivers/CAN_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/STM32F4xx-Perifericos -I../../Drivers/CAN_Driver -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/CAN_Driver/can_wrapper.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Drivers/CAN_Driver/can_wrapper.c Drivers/CAN_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/BSP/STM32F4xx-Perifericos -I../../Drivers/CAN_Driver -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CAN_Driver

clean-Drivers-2f-CAN_Driver:
	-$(RM) ./Drivers/CAN_Driver/can_api.d ./Drivers/CAN_Driver/can_api.o ./Drivers/CAN_Driver/can_wrapper.d ./Drivers/CAN_Driver/can_wrapper.o

.PHONY: clean-Drivers-2f-CAN_Driver

