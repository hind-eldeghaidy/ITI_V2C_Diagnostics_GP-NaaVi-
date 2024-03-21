/*
 * Ultrasonic_Program.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "Ultrasonic_Interface.h"       // Include the header file for Ultrasonic sensor interface
#include "../HAL/Motors/MotorDriver_Interface.h"       // Include the header file for MotorDriver interface
#include "../HAL/Motor_Vibrator/Motor_Vibrator_Interface.h"   // Include the header file for Motor Vibrator interface
#include "main.h"                        // Include main header file

// Define global variables
uint32_t IC_Val1 = 0;          // Variable to store first captured value for sensor 1
uint32_t IC_Val2 = 0;          // Variable to store second captured value for sensor 1
uint32_t Difference = 0;        // Variable to store time difference between two captures
uint8_t Is_First_Captured1 = 0; // Flag to indicate if the first value is captured for sensor 1
uint8_t Is_First_Captured2 = 0; // Flag to indicate if the first value is captured for sensor 2
uint8_t Is_First_Captured3 = 0; // Flag to indicate if the first value is captured for sensor 3
uint8_t Is_First_Captured4 = 0; // Flag to indicate if the first value is captured for sensor 4
uint8_t Distance1  = 0;         // Variable to store distance calculated from sensor 1
uint8_t Distance2  = 0;         // Variable to store distance calculated from sensor 2
uint8_t Distance3  = 0;         // Variable to store distance calculated from sensor 3
uint8_t Distance4 = 0;          // Variable to store distance calculated from sensor 4
uint8_t speed = 70;             // Initial speed of the motor

// External declaration of the timer handle
extern TIM_HandleTypeDef htim1;

// Function to create a delay in microseconds
void delay(uint16_t time)
{
    __HAL_TIM_SetCounter(&htim1, 0);  // Reset the counter
    while (__HAL_TIM_GET_COUNTER(&htim1) < time); // Wait for the specified time
}

// Callback function for handling input capture interrupts
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    // Check if the interrupt source is channel 1
    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        // If the first value is not captured
        if (Is_First_Captured1 == 0)
        {
            // Read the first value
            IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            Is_First_Captured1 = 1;  // Set the flag to indicate the first value is captured for sensor 1

            // Change the polarity to falling edge
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
        }
        else if (Is_First_Captured1 == 1) // If the first value is already captured for sensor 1
        {
            // Read the second value
            IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            __HAL_TIM_SET_COUNTER(htim, 0);  // Reset the counter

            // Calculate the time difference between the two captures
            if (IC_Val2 > IC_Val1)
            {
                Difference = IC_Val2 - IC_Val1;
            }
            else if (IC_Val1 > IC_Val2)
            {
                Difference = (0xffff - IC_Val1) + IC_Val2;
            }

            // Calculate the distance based on the time difference for sensor 1
            Distance1 = Difference * 0.034 / 2;

            // Control the motor based on the calculated distance
            if (Distance1 < 35 && Distance1 > 12)
            {
                // Adjust speed based on distance
                speed = ((((max_speed - 60) * Distance1) - (5 * max_speed) + 1500) / 20);
                MotorDriver_voidMoveForward(speed);  // Move the motor forward
                Mvoid_Motor_Vibrator();              // Trigger the motor vibrator
            }
            else if (Distance1 <= 12)
            {
                MotorDriver_voidStop();  // Stop the motor
               // speed = 0;               // Set speed to 0
            }
            else if (Distance1 >= 35)
            {
                speed = 95;              // Set speed to default value
                MotorDriver_voidMoveForward(speed);  // Move the motor forward
            }

            Is_First_Captured1 = 0;  // Reset the flag for sensor 1

            // Set polarity to rising edge
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
            __HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1); // Disable further interrupts for this channel
        }
    }
}

// Function to trigger ultrasonic sensor and read distance for sensor 1
void HCSR04_Read1(void)
{
    __HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);   // Enable input capture interrupt for channel 1
    HAL_GPIO_WritePin(TRIG1_PIN_GPIO_Port, TRIG1_PIN_Pin, GPIO_PIN_SET);  // Pull the TRIG pin HIGH
    delay(10);  // Wait for 10 microseconds
    HAL_GPIO_WritePin(TRIG1_PIN_GPIO_Port, TRIG1_PIN_Pin, GPIO_PIN_RESET);  // Pull the TRIG pin low
}
