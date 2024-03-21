/*
 * Ultrasonic_Interface.h
 *
 *  Created on: Feb 29, 2024
 *      Author: Abdallah Essam
 */

#ifndef INC_ULTRASONIC_INTERFACE_H_  // Header guard to prevent recursive inclusion
#define INC_ULTRASONIC_INTERFACE_H_

#include "main.h"           // Include main header file for project-specific definitions
#include "stm32f4xx_hal.h"  // Include HAL library for STM32

#define max_speed 80  // Define the maximum motor speed

/* Function Prototypes */

/**
 * @brief Create a delay in microseconds.
 * @param time: The time duration of the delay in microseconds.
 */
void delay(uint16_t time);

/**
 * @brief Callback function for handling input capture interrupts.
 * @param htim: Pointer to a TIM_HandleTypeDef structure that contains the configuration information for the TIM module.
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

/**
 * @brief Trigger ultrasonic sensor and read distance for sensor 1.
 */
void HCSR04_Read1(void);

/**
 * @brief Trigger ultrasonic sensor and read distance for sensor 2.

void HCSR04_Read2(void);

/**
 * @brief Trigger ultrasonic sensor and read distance for sensor 3.

void HCSR04_Read3(void);

/**
 * @brief Trigger ultrasonic sensor and read distance for sensor 4.

void HCSR04_Read4(void);
*/
#endif /* INC_ULTRASONIC_INTERFACE_H_ */
