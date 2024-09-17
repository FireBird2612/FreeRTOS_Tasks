################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c 

OBJS += \
./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o 

C_DEPS += \
./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Components/SEGGER/Config/%.o Components/SEGGER/Config/%.su Components/SEGGER/Config/%.cyclo: ../Components/SEGGER/Config/%.c Components/SEGGER/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/include" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/MemMang" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER/Syscalls" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/OS" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-SEGGER-2f-Config

clean-Components-2f-SEGGER-2f-Config:
	-$(RM) ./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.d ./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.o ./Components/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-Components-2f-SEGGER-2f-Config

