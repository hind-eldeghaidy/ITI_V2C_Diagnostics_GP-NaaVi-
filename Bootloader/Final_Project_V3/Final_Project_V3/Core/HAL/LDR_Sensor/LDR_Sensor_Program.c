/*
 * LDR_Sensor.c
 *
 *  Created on: Feb 27, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "LDR_Sensor_interface.h"  // Include header file for LDR sensor interface
#include "main.h"                  // Include main header file

// Function to handle LDR sensor
void voidLDR_Sensor()
{
    // Check the state of the LDR sensor pin
    if(HAL_GPIO_ReadPin(LDR_Sensor_GPIO_Port, LDR_Sensor_Pin) == GPIO_PIN_RESET) // If sensor is activated (LDR_SENSOR_PIN is grounded)
    {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET); // Turn on the LED (if sensor is activated, meaning it's dark)
    }
    else // If sensor is not activated (LDR_SENSOR_PIN is not grounded)
    {
        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET); // Turn off the LED (if sensor is not activated, meaning it's light)
    }
}
