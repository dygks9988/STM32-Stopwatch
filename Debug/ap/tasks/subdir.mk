################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ap/tasks/stopwatch_task.c 

OBJS += \
./ap/tasks/stopwatch_task.o 

C_DEPS += \
./ap/tasks/stopwatch_task.d 


# Each subdirectory must supply rules for building sources it contributes
ap/tasks/%.o ap/tasks/%.su ap/tasks/%.cyclo: ../ap/tasks/%.c ap/tasks/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/tasks" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/module" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ap-2f-tasks

clean-ap-2f-tasks:
	-$(RM) ./ap/tasks/stopwatch_task.cyclo ./ap/tasks/stopwatch_task.d ./ap/tasks/stopwatch_task.o ./ap/tasks/stopwatch_task.su

.PHONY: clean-ap-2f-tasks

