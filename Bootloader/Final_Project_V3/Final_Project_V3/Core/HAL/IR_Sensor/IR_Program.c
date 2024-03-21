/*
 * IR_Program.c
 *
 *  Created on: Feb 27, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "IR_Interface.h"    // Include header file for IR sensor interface
#include "main.h"            // Include main header file

// Function to read the right IR sensor
uint8_t IR_u8Read_RightIR(void)
{
    return HAL_GPIO_ReadPin(IR_Right_GPIO_Port, IR_Right_Pin); // Read the value of the right IR sensor pin
}

// Function to read the left IR sensor
uint8_t IR_u8Read_LeftIR(void)
{
    return HAL_GPIO_ReadPin(IR_Left_GPIO_Port, IR_Left_Pin); // Read the value of the left IR sensor pin
}
