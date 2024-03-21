################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.c 

OBJS += \
./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.o 

C_DEPS += \
./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.d 


# Each subdirectory must supply rules for building sources it contributes
Core/HAL/Motor_Vibrator/%.o Core/HAL/Motor_Vibrator/%.su Core/HAL/Motor_Vibrator/%.cyclo: ../Core/HAL/Motor_Vibrator/%.c Core/HAL/Motor_Vibrator/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-HAL-2f-Motor_Vibrator

clean-Core-2f-HAL-2f-Motor_Vibrator:
	-$(RM) ./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.cyclo ./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.d ./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.o ./Core/HAL/Motor_Vibrator/Motor_Vibrator_Program.su

.PHONY: clean-Core-2f-HAL-2f-Motor_Vibrator

