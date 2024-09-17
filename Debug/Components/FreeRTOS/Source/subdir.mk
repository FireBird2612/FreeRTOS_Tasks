################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Components/FreeRTOS/Source/croutine.c \
../Components/FreeRTOS/Source/event_groups.c \
../Components/FreeRTOS/Source/list.c \
../Components/FreeRTOS/Source/queue.c \
../Components/FreeRTOS/Source/stream_buffer.c \
../Components/FreeRTOS/Source/tasks.c \
../Components/FreeRTOS/Source/timers.c 

OBJS += \
./Components/FreeRTOS/Source/croutine.o \
./Components/FreeRTOS/Source/event_groups.o \
./Components/FreeRTOS/Source/list.o \
./Components/FreeRTOS/Source/queue.o \
./Components/FreeRTOS/Source/stream_buffer.o \
./Components/FreeRTOS/Source/tasks.o \
./Components/FreeRTOS/Source/timers.o 

C_DEPS += \
./Components/FreeRTOS/Source/croutine.d \
./Components/FreeRTOS/Source/event_groups.d \
./Components/FreeRTOS/Source/list.d \
./Components/FreeRTOS/Source/queue.d \
./Components/FreeRTOS/Source/stream_buffer.d \
./Components/FreeRTOS/Source/tasks.d \
./Components/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Components/FreeRTOS/Source/%.o Components/FreeRTOS/Source/%.su Components/FreeRTOS/Source/%.cyclo: ../Components/FreeRTOS/Source/%.c Components/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/include" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/FreeRTOS/Source/portable/MemMang" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/SEGGER/Syscalls" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/Config" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/SEGGER/OS" -I"/Users/simpleyetfulling/dev/rtos-wk/EMotoRad_A/Components/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Components-2f-FreeRTOS-2f-Source

clean-Components-2f-FreeRTOS-2f-Source:
	-$(RM) ./Components/FreeRTOS/Source/croutine.cyclo ./Components/FreeRTOS/Source/croutine.d ./Components/FreeRTOS/Source/croutine.o ./Components/FreeRTOS/Source/croutine.su ./Components/FreeRTOS/Source/event_groups.cyclo ./Components/FreeRTOS/Source/event_groups.d ./Components/FreeRTOS/Source/event_groups.o ./Components/FreeRTOS/Source/event_groups.su ./Components/FreeRTOS/Source/list.cyclo ./Components/FreeRTOS/Source/list.d ./Components/FreeRTOS/Source/list.o ./Components/FreeRTOS/Source/list.su ./Components/FreeRTOS/Source/queue.cyclo ./Components/FreeRTOS/Source/queue.d ./Components/FreeRTOS/Source/queue.o ./Components/FreeRTOS/Source/queue.su ./Components/FreeRTOS/Source/stream_buffer.cyclo ./Components/FreeRTOS/Source/stream_buffer.d ./Components/FreeRTOS/Source/stream_buffer.o ./Components/FreeRTOS/Source/stream_buffer.su ./Components/FreeRTOS/Source/tasks.cyclo ./Components/FreeRTOS/Source/tasks.d ./Components/FreeRTOS/Source/tasks.o ./Components/FreeRTOS/Source/tasks.su ./Components/FreeRTOS/Source/timers.cyclo ./Components/FreeRTOS/Source/timers.d ./Components/FreeRTOS/Source/timers.o ./Components/FreeRTOS/Source/timers.su

.PHONY: clean-Components-2f-FreeRTOS-2f-Source

