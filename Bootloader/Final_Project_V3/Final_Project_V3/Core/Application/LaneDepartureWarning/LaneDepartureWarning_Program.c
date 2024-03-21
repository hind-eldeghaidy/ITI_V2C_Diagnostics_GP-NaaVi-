/*
 * LaneDepartureWarning_Program.c
 *
 *  Created on: Mar 16, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "LaneDepartureWarning_Interface.h"  // Include header file for Lane Departure Warning interface
//#include "IR_Interface.h"                     // Include header file for IR sensor interface (commented out)

// Define variables to store IR sensor readings
uint8_t left_IR = 0;   // Variable to store left IR sensor reading
uint8_t right_IR = 0;  // Variable to store right IR sensor reading

// Callback function for left IR sensor interrupt
void LDW_LeftIRCallBack(void) {
    /* Get readings from left and right IR sensors */
    left_IR = IR_u8Read_LeftIR();    // Read left IR sensor
    right_IR = IR_u8Read_RightIR();  // Read right IR sensor

    /* Use logical AND operator to ensure both conditions are true */
    while (right_IR && left_IR) {
        /* Lane Departure Warning logic */
        /* If the car is inside the lane / No lane markings are detected on both sides */
        if (left_IR == BLACK && right_IR == BLACK) {
            Buzzer_Off(); /**< Turn off the buzzer. */
        }
        /* If the car drifts to the right / Lane markings are detected on the right side */
        else if (left_IR == BLACK && right_IR == WHITE) {
            Buzzer_ON(); /**< Turn on the buzzer. */
        }
        /* If the car drifts to the left / Lane markings are detected on the left side */
        else if (left_IR == WHITE && right_IR == BLACK) {
            Buzzer_ON(); /**< Turn on the buzzer. */
        } else {
            // Stop the car
            Buzzer_Off(); /**< Turn off the buzzer. */
        }
    }
}

// Callback function for right IR sensor interrupt
void LDW_RightIRCallBack(void) {
    /* Get readings from left and right IR sensors */
    left_IR = IR_u8Read_LeftIR();    // Read left IR sensor
    right_IR = IR_u8Read_RightIR();  // Read right IR sensor

    /* Use logical AND operator to ensure both conditions are true */
    while (right_IR && left_IR) {
        /* Lane Departure Warning logic */
        /* If the car is inside the lane / No lane markings are detected on both sides */
        if (left_IR == BLACK && right_IR == BLACK) {
            // Move the car forward
            Buzzer_Off(); /**< Turn off the buzzer. */
        }
        /* If the car drifts to the right / Lane markings are detected on the right side */
        else if (left_IR == BLACK && right_IR == WHITE) {
            Buzzer_ON(); /**< Turn on the buzzer. */
        }
        /* If the car drifts to the left / Lane markings are detected on the left side */
        else if (left_IR == WHITE && right_IR == BLACK) {
            Buzzer_ON(); /**< Turn on the buzzer. */
        } else {
            // Stop the car
            Buzzer_Off(); /**< Turn off the buzzer. */
        }
    }
}
