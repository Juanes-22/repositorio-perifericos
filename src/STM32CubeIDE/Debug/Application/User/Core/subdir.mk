################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/adc.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/app_perifericos.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/botones.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/botones_hw.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/buses.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can_app.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can_hw.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/decode_data.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/dma.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/gpio.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/indicators.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/main.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla_api.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla_hw.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pedal.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pedal_hw.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/stm32f4xx_it.c \
../Application/User/Core/syscalls.c \
../Application/User/Core/sysmem.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/tim.c \
C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/usart.c 

OBJS += \
./Application/User/Core/adc.o \
./Application/User/Core/app_perifericos.o \
./Application/User/Core/botones.o \
./Application/User/Core/botones_hw.o \
./Application/User/Core/buses.o \
./Application/User/Core/can.o \
./Application/User/Core/can_app.o \
./Application/User/Core/can_hw.o \
./Application/User/Core/decode_data.o \
./Application/User/Core/dma.o \
./Application/User/Core/gpio.o \
./Application/User/Core/indicators.o \
./Application/User/Core/main.o \
./Application/User/Core/pantalla.o \
./Application/User/Core/pantalla_api.o \
./Application/User/Core/pantalla_hw.o \
./Application/User/Core/pedal.o \
./Application/User/Core/pedal_hw.o \
./Application/User/Core/stm32f4xx_hal_msp.o \
./Application/User/Core/stm32f4xx_it.o \
./Application/User/Core/syscalls.o \
./Application/User/Core/sysmem.o \
./Application/User/Core/tim.o \
./Application/User/Core/usart.o 

C_DEPS += \
./Application/User/Core/adc.d \
./Application/User/Core/app_perifericos.d \
./Application/User/Core/botones.d \
./Application/User/Core/botones_hw.d \
./Application/User/Core/buses.d \
./Application/User/Core/can.d \
./Application/User/Core/can_app.d \
./Application/User/Core/can_hw.d \
./Application/User/Core/decode_data.d \
./Application/User/Core/dma.d \
./Application/User/Core/gpio.d \
./Application/User/Core/indicators.d \
./Application/User/Core/main.d \
./Application/User/Core/pantalla.d \
./Application/User/Core/pantalla_api.d \
./Application/User/Core/pantalla_hw.d \
./Application/User/Core/pedal.d \
./Application/User/Core/pedal_hw.d \
./Application/User/Core/stm32f4xx_hal_msp.d \
./Application/User/Core/stm32f4xx_it.d \
./Application/User/Core/syscalls.d \
./Application/User/Core/sysmem.d \
./Application/User/Core/tim.d \
./Application/User/Core/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Core/adc.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/adc.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/app_perifericos.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/app_perifericos.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/botones.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/botones.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/botones_hw.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/botones_hw.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/buses.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/buses.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/can.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/can_app.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can_app.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/can_hw.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/can_hw.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/decode_data.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/decode_data.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/dma.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/dma.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/gpio.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/gpio.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/indicators.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/indicators.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/main.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/main.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/pantalla.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/pantalla_api.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla_api.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/pantalla_hw.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pantalla_hw.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/pedal.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pedal.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/pedal_hw.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/pedal_hw.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_hal_msp.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/stm32f4xx_hal_msp.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/stm32f4xx_it.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/stm32f4xx_it.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/%.o: ../Application/User/Core/%.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/tim.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/tim.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/Core/usart.o: C:/Users/juane/OneDrive/Escritorio/STM32-Programming/elektron-stm32-workspace/Perifericos/Core/Src/usart.c Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I"../../Drivers/BSP/STM32F4xx-Perifericos" -I"../../Drivers/CAN_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Core

clean-Application-2f-User-2f-Core:
	-$(RM) ./Application/User/Core/adc.d ./Application/User/Core/adc.o ./Application/User/Core/app_perifericos.d ./Application/User/Core/app_perifericos.o ./Application/User/Core/botones.d ./Application/User/Core/botones.o ./Application/User/Core/botones_hw.d ./Application/User/Core/botones_hw.o ./Application/User/Core/buses.d ./Application/User/Core/buses.o ./Application/User/Core/can.d ./Application/User/Core/can.o ./Application/User/Core/can_app.d ./Application/User/Core/can_app.o ./Application/User/Core/can_hw.d ./Application/User/Core/can_hw.o ./Application/User/Core/decode_data.d ./Application/User/Core/decode_data.o ./Application/User/Core/dma.d ./Application/User/Core/dma.o ./Application/User/Core/gpio.d ./Application/User/Core/gpio.o ./Application/User/Core/indicators.d ./Application/User/Core/indicators.o ./Application/User/Core/main.d ./Application/User/Core/main.o ./Application/User/Core/pantalla.d ./Application/User/Core/pantalla.o ./Application/User/Core/pantalla_api.d ./Application/User/Core/pantalla_api.o ./Application/User/Core/pantalla_hw.d ./Application/User/Core/pantalla_hw.o ./Application/User/Core/pedal.d ./Application/User/Core/pedal.o ./Application/User/Core/pedal_hw.d ./Application/User/Core/pedal_hw.o ./Application/User/Core/stm32f4xx_hal_msp.d ./Application/User/Core/stm32f4xx_hal_msp.o ./Application/User/Core/stm32f4xx_it.d ./Application/User/Core/stm32f4xx_it.o ./Application/User/Core/syscalls.d ./Application/User/Core/syscalls.o ./Application/User/Core/sysmem.d ./Application/User/Core/sysmem.o ./Application/User/Core/tim.d ./Application/User/Core/tim.o ./Application/User/Core/usart.d ./Application/User/Core/usart.o

.PHONY: clean-Application-2f-User-2f-Core

