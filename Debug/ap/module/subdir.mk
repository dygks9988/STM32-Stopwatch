################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ap/module/stopwatch.c 

OBJS += \
./ap/module/stopwatch.o 

C_DEPS += \
./ap/module/stopwatch.d 


# Each subdirectory must supply rules for building sources it contributes
ap/module/%.o ap/module/%.su ap/module/%.cyclo: ../ap/module/%.c ap/module/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/tasks" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw" -I"C:/stm_workspace_1.16.1/stm32f411_RE/ap/module" -I"C:/stm_workspace_1.16.1/stm32f411_RE/hw/driver" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ap-2f-module

clean-ap-2f-module:
	-$(RM) ./ap/module/stopwatch.cyclo ./ap/module/stopwatch.d ./ap/module/stopwatch.o ./ap/module/stopwatch.su

.PHONY: clean-ap-2f-module

