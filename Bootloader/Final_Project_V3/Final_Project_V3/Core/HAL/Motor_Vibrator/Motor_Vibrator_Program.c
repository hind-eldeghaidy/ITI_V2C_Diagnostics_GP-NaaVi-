/*
 * Motor_Vibrator_Interface.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "Motor_Vibrator_Interface.h"  // Include header file for Motor Vibrator interface
#include "stm32f4xx_hal.h"             // Include the HAL library for STM32

// Function to activate the motor vibrator
void Mvoid_Motor_Vibrator(void)
{
    HAL_GPIO_WritePin(Motor_Vibrator_GPIO_Port, Motor_Vibrator_Pin, GPIO_PIN_SET);  // Set the motor vibrator pin to HIGH
}
