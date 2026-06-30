################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tasks/stopwatch_task.c \
../tasks/tasks.c 

OBJS += \
./tasks/stopwatch_task.o \
./tasks/tasks.o 

C_DEPS += \
./tasks/stopwatch_task.d \
./tasks/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
tasks/%.o tasks/%.su tasks/%.cyclo: ../tasks/%.c tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I"C:/stm_workspace_1.16.1/stm32f411_RE/tasks" -I../Core/Inc -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/module" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tasks

clean-tasks:
	-$(RM) ./tasks/stopwatch_task.cyclo ./tasks/stopwatch_task.d ./tasks/stopwatch_task.o ./tasks/stopwatch_task.su ./tasks/tasks.cyclo ./tasks/tasks.d ./tasks/tasks.o ./tasks/tasks.su

.PHONY: clean-tasks

