################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/SEGGER/SEGGER/SEGGER_RTT.c \
../Components/SEGGER/SEGGER/SEGGER_RTT_printf.c \
../Components/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../Components/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Components/SEGGER/SEGGER/SEGGER_RTT.o \
./Components/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Components/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Components/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Components/SEGGER/SEGGER/SEGGER_RTT.d \
./Components/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Components/SEGGER/SEGGER/%.o Components/SEGGER/SEGGER/%.su Components/SEGGER/SEGGER/%.cyclo: ../Components/SEGGER/SEGGER/%.c Components/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/include" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/MemMang" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER/Syscalls" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/OS" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Components/SEGGER/SEGGER/%.o: ../Components/SEGGER/SEGGER/%.S Components/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Components-2f-SEGGER-2f-SEGGER

clean-Components-2f-SEGGER-2f-SEGGER:
	-$(RM) ./Components/SEGGER/SEGGER/SEGGER_RTT.cyclo ./Components/SEGGER/SEGGER/SEGGER_RTT.d ./Components/SEGGER/SEGGER/SEGGER_RTT.o ./Components/SEGGER/SEGGER/SEGGER_RTT.su ./Components/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Components/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Components/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./Components/SEGGER/SEGGER/SEGGER_RTT_printf.d ./Components/SEGGER/SEGGER/SEGGER_RTT_printf.o ./Components/SEGGER/SEGGER/SEGGER_RTT_printf.su ./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./Components/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Components-2f-SEGGER-2f-SEGGER

