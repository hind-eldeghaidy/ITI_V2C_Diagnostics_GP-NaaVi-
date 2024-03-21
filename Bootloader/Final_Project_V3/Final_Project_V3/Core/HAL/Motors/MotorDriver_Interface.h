/*
 * MotorDriver_Program.h
 *
 *  Created on: Feb 21, 2024
 *      Author: Abdallah Essam
 */

#ifndef INC_MOTORDRIVER_INTERFACE_H_  // Header guard to prevent recursive inclusion
#define INC_MOTORDRIVER_INTERFACE_H_

#include <stdint.h>  // Include standard integer types

/* Function Prototypes */

/**
 * @brief Move the motor forward with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveForward(uint8_t DutyCycle);

/**
 * @brief Move the motor backward with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveBackward(uint8_t DutyCycle);

/**
 * @brief Move the motor right with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveRight(uint8_t DutyCycle);

/**
 * @brief Move the motor left with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveLeft(uint8_t DutyCycle);

/**
 * @brief Move the motor forward and right with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveForRight(uint8_t DutyCycle);

/**
 * @brief Move the motor forward and left with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveForLeft(uint8_t DutyCycle);

/**
 * @brief Move the motor backward and right with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveBackRight(uint8_t DutyCycle);

/**
 * @brief Move the motor backward and left with a specified duty cycle.
 * @param DutyCycle: Duty cycle value (0-100) to control motor speed.
 */
void MotorDriver_voidMoveBackLeft(uint8_t DutyCycle);

/**
 * @brief Stop the motor.
 */
void MotorDriver_voidStop(void);

#endif /* INC_MOTORDRIVER_INTERFACE_H_ */
