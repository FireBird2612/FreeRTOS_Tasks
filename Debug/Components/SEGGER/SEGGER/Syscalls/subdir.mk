################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c 

OBJS += \
./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o 

C_DEPS += \
./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d 


# Each subdirectory must supply rules for building sources it contributes
Components/SEGGER/SEGGER/Syscalls/%.o Components/SEGGER/SEGGER/Syscalls/%.su Components/SEGGER/SEGGER/Syscalls/%.cyclo: ../Components/SEGGER/SEGGER/Syscalls/%.c Components/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/include" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/MemMang" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER/Syscalls" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/OS" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-SEGGER-2f-SEGGER-2f-Syscalls

clean-Components-2f-SEGGER-2f-SEGGER-2f-Syscalls:
	-$(RM) ./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.cyclo ./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./Components/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.su

.PHONY: clean-Components-2f-SEGGER-2f-SEGGER-2f-Syscalls

