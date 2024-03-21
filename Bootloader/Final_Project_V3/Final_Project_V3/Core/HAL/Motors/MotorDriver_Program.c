/*
 * MotorDriver_Program.c
 *
 *  Created on: Feb 21, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "../HAL/Motors/MotorDriver_Interface.h" // Include the header file for the MotorDriver interface
#include "gpio.h"                  // Include the header file for GPIO configuration
#include "stm32f401xc.h"           // Include the header file for STM32F401xC

// Function to move the motor forward
void MotorDriver_voidMoveForward(uint8_t DutyCycle)
{
    // Set the duty cycle for both PWM channels
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);  // Set pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);  // Set pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor backward
void MotorDriver_voidMoveBackward(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // Reset pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);   // Set pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // Reset pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);   // Set pin PB3 (Motor2 backward)
}

// Function to move the motor right
void MotorDriver_voidMoveRight(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // Reset pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // Set pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor left
void MotorDriver_voidMoveLeft(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // Set pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // Reset pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor forward and right
void MotorDriver_voidMoveForRight(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // Reset pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // Set pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor forward and left
void MotorDriver_voidMoveForLeft(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // Set pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // Reset pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor backward and right
void MotorDriver_voidMoveBackRight(uint8_t DutyCycle)
{
    TIM2->CCR1 = DutyCycle; // Set duty cycle for channel 1
    TIM2->CCR2 = DutyCycle; // Set duty cycle for channel 2

    // Configure GPIO pins for motor direction control
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // Reset pin PA2 (Motor1 forward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);   // Set pin PA3 (Motor1 backward)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // Reset pin PA4 (Motor2 forward)
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // Reset pin PB3 (Motor2 backward)
}

// Function to move the motor backward and left
void MotorDriver_voidMoveBackLeft(uint8_t DutyCycle)
{
    // Set duty cycle for both motor channels
    TIM2->CCR1= DutyCycle;
    TIM2->CCR2= DutyCycle;

    // Control GPIO pins to set the direction of the motors
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET); // Motor 1 backward
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET); // Motor 1 backward
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); // Motor 2 backward
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET); // Motor 2 forward
}

// Function to stop the motor
void MotorDriver_voidStop(void)
{
    // Turn off all motor control GPIO pins
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
}
