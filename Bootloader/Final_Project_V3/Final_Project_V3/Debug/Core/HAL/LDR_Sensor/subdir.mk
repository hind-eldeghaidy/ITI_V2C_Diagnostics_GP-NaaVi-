################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/HAL/LDR_Sensor/LDR_Sensor_Program.c 

OBJS += \
./Core/HAL/LDR_Sensor/LDR_Sensor_Program.o 

C_DEPS += \
./Core/HAL/LDR_Sensor/LDR_Sensor_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Core/HAL/LDR_Sensor/%.o Core/HAL/LDR_Sensor/%.su Core/HAL/LDR_Sensor/%.cyclo: ../Core/HAL/LDR_Sensor/%.c Core/HAL/LDR_Sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-HAL-2f-LDR_Sensor

clean-Core-2f-HAL-2f-LDR_Sensor:
	-$(RM) ./Core/HAL/LDR_Sensor/LDR_Sensor_Program.cyclo ./Core/HAL/LDR_Sensor/LDR_Sensor_Program.d ./Core/HAL/LDR_Sensor/LDR_Sensor_Program.o ./Core/HAL/LDR_Sensor/LDR_Sensor_Program.su

.PHONY: clean-Core-2f-HAL-2f-LDR_Sensor

