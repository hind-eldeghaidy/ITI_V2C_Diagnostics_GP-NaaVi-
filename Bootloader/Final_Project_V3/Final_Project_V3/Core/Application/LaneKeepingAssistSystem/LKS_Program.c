/*
 * LKS_Program.c
 *
 *  Created on: Feb 28, 2024
 *      Author: Abdallah Essam
 */

// Include necessary header files
#include "../HAL/IR_Sensor/IR_Interface.h"                    // Include header file for IR sensor interface
#include "../HAL/Motors/MotorDriver_Interface.h" // Include header file for MotorDriver interface
#include "../HAL/Motor_Vibrator/Motor_Vibrator_Interface.h"        // Include header file for Motor_Vibrator interface
#include "../Application/LaneDepartureWarning/LaneDepartureWarning_Interface.h"  // Include header file for LaneDepartureWarning interface
// Define global variables for IR sensor readings
//volatile uint8_t left_IR = 0, right_IR = 0;  // Commented out as these variables are presumably defined in IR_Interface.h

// Function to control Lane Keeping System (LKS) task
void APP_LKS_vTask() {
    // Read left and right IR sensor values
   /* left_IR = IR_u8Read_LeftIR();    // Read left IR sensor
    right_IR = IR_u8Read_RightIR();  // Read right IR sensor
*/
    // Control the car based on IR sensor readings
    while (1) {  // Commented out as it seems unnecessary
         //Read IR sensor values
        left_IR = IR_u8Read_LeftIR();
        right_IR = IR_u8Read_RightIR();

        // Lane Keeping System logic
        /* If the car is inside the lane / No lane markings are detected on both sides */
        if (left_IR == BLACK && right_IR == BLACK) {
            // Move the car forward
            MotorDriver_voidMoveForward(95);  // Move forward with a speed of 95
        }
        /* If the car drifts to the right / Lane markings are detected on the right side */
        else if (left_IR == BLACK && right_IR == WHITE) {
            // Steer the car to the left
            MotorDriver_voidMoveLeft(95);  // Move left with a speed of 95
            //HAL_Delay(500);
        }
        /* If the car drifts to the left / Lane markings are detected on the left side */
        else if (left_IR == WHITE && right_IR == BLACK) {
            // Steer the car to the right
            MotorDriver_voidMoveRight(95);  // Move right with a speed of 95
            //HAL_Delay(500);

        } else {
            // Stop the car
            MotorDriver_voidStop();  // Stop the car
        }
    }
}
        // Check if the LKS mode flag is disabled
        /*if (!LKS_ModeFlag) {
            break;
        }*/
   // }
//}
