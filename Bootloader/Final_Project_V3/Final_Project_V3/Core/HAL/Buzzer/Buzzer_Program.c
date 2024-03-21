/*
 * Buzzer_Program.c
 *
 *  Created on: Mar 16, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "Buzzer_Interface.h"    // Include header file for buzzer interface
#include "main.h"                // Include main header file

// Function to turn on the buzzer
void Buzzer_ON(void)
{
    HAL_GPIO_WritePin(Buzzer_Pin_GPIO_Port, Buzzer_Pin_Pin, GPIO_PIN_SET); // Set the buzzer pin to HIGH
}

// Function to turn off the buzzer
void Buzzer_Off(void)
{
    HAL_GPIO_WritePin(Buzzer_Pin_GPIO_Port, Buzzer_Pin_Pin, GPIO_PIN_RESET); // Set the buzzer pin to LOW
}
