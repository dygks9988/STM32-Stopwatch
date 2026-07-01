################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../scheduler/rtos_task.c \
../scheduler/stopwatch_task.c \
../scheduler/uart_cmd_task.c 

OBJS += \
./scheduler/rtos_task.o \
./scheduler/stopwatch_task.o \
./scheduler/uart_cmd_task.o 

C_DEPS += \
./scheduler/rtos_task.d \
./scheduler/stopwatch_task.d \
./scheduler/uart_cmd_task.d 


# Each subdirectory must supply rules for building sources it contributes
scheduler/%.o scheduler/%.su scheduler/%.cyclo: ../scheduler/%.c scheduler/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"C:/stm_workspace_1.16.1/stm32f411_RE/scheduler" -I../Core/Inc -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/module" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-scheduler

clean-scheduler:
	-$(RM) ./scheduler/rtos_task.cyclo ./scheduler/rtos_task.d ./scheduler/rtos_task.o ./scheduler/rtos_task.su ./scheduler/stopwatch_task.cyclo ./scheduler/stopwatch_task.d ./scheduler/stopwatch_task.o ./scheduler/stopwatch_task.su ./scheduler/uart_cmd_task.cyclo ./scheduler/uart_cmd_task.d ./scheduler/uart_cmd_task.o ./scheduler/uart_cmd_task.su

.PHONY: clean-scheduler

