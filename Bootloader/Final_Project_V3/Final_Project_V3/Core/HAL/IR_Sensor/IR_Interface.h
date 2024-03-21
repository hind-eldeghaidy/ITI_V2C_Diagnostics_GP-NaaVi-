/*
 * IR_Interface.h
 *
 *  Created on: Feb 27, 2024
 *      Author: Abdallah Essam
 */

#ifndef INC_IR_INTERFACE_H_  // Header guard to prevent multiple inclusions
#define INC_IR_INTERFACE_H_

#include "stm32f4xx_hal.h"  // Include HAL library for STM32
#define WHITE   0            // Define constant for white color
#define BLACK   1            // Define constant for black color

/* Function Prototypes */
uint8_t IR_u8Read_RightIR(void);  // Function to read right IR sensor
uint8_t IR_u8Read_LeftIR(void);   // Function to read left IR sensor

#endif /* INC_IR_INTERFACE_H_ */
