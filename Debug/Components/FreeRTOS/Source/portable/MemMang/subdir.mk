################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./Components/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Components/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Components/FreeRTOS/Source/portable/MemMang/%.o Components/FreeRTOS/Source/portable/MemMang/%.su Components/FreeRTOS/Source/portable/MemMang/%.cyclo: ../Components/FreeRTOS/Source/portable/MemMang/%.c Components/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/include" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/MemMang" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER/Syscalls" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/OS" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-Components-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Components/FreeRTOS/Source/portable/MemMang/heap_4.cyclo ./Components/FreeRTOS/Source/portable/MemMang/heap_4.d ./Components/FreeRTOS/Source/portable/MemMang/heap_4.o ./Components/FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-Components-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

