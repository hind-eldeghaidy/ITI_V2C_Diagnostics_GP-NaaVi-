/*
 * main.h
 *
 *  Created on: Date
 *      Author: Author
 */

#ifndef __MAIN_H  // Header guard to prevent recursive inclusion
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"  // Include HAL library for STM32

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);  // Function prototype for error handler

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Motor_Vibrator_Pin GPIO_PIN_13       // Define pin for motor vibrator
#define Motor_Vibrator_GPIO_Port GPIOC       // Define port for motor vibrator
#define Buzzer_Pin_Pin GPIO_PIN_14           // Define pin for buzzer
#define Buzzer_Pin_GPIO_Port GPIOC           // Define port for buzzer
#define IR_Left_Pin GPIO_PIN_2               // Define pin for left IR sensor
#define IR_Left_GPIO_Port GPIOB              // Define port for left IR sensor
#define IR_Right_Pin GPIO_PIN_1              // Define pin for right IR sensor
#define IR_Right_GPIO_Port GPIOB             // Define port for right IR sensor
#define TRIG4_PIN_Pin GPIO_PIN_10            // Define pin for trigger 4
#define TRIG4_PIN_GPIO_Port GPIOB            // Define port for trigger 4
#define TRIG3_PIN_Pin GPIO_PIN_12            // Define pin for trigger 3
#define TRIG3_PIN_GPIO_Port GPIOB            // Define port for trigger 3
#define LED_Pin GPIO_PIN_13                  // Define pin for LED
#define LED_GPIO_Port GPIOB                  // Define port for LED
#define TRIG2_PIN_Pin GPIO_PIN_14            // Define pin for trigger 2
#define TRIG2_PIN_GPIO_Port GPIOB            // Define port for trigger 2
#define TRIG1_PIN_Pin GPIO_PIN_15            // Define pin for trigger 1
#define TRIG1_PIN_GPIO_Port GPIOB            // Define port for trigger 1
#define LDR_Sensor_Pin GPIO_PIN_12           // Define pin for LDR sensor
#define LDR_Sensor_GPIO_Port GPIOA           // Define port for LDR sensor

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
