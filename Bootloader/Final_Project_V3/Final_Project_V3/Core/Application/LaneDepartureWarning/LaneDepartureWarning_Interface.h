/*
 * LaneDepartureWarning_Interface.h
 *
 *  Created on: Mar 16, 2024
 *      Author: Abdallah Essam
 */

#ifndef INC_LANEDEPARTUREWARNING_INTERFACE_H_  // Header guard to prevent multiple inclusions
#define INC_LANEDEPARTUREWARNING_INTERFACE_H_

#include "../HAL/Buzzer/Buzzer_Interface.h"  // Include header file for buzzer interface
#include "../HAL/IR_Sensor/IR_Interface.h"      // Include header file for IR interface

extern uint8_t left_IR;   // Declare left_IR variable as extern
extern uint8_t right_IR;  // Declare right_IR variable as extern

// Function prototypes
void LDW_LeftIRCallBack(void);   // Callback function for left IR sensor
void LDW_RightIRCallBack(void);  // Callback function for right IR sensor

#endif /* INC_LANEDEPARTUREWARNING_INTERFACE_H_ */
