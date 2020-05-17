/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

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
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TRIG_IN_Pin GPIO_PIN_2
#define TRIG_IN_GPIO_Port GPIOE
#define TRIG_OUT_Pin GPIO_PIN_3
#define TRIG_OUT_GPIO_Port GPIOE
#define TRIG_EN_Pin GPIO_PIN_4
#define TRIG_EN_GPIO_Port GPIOE
#define SENS_SDA_Pin GPIO_PIN_0
#define SENS_SDA_GPIO_Port GPIOF
#define SENS_SCL_Pin GPIO_PIN_1
#define SENS_SCL_GPIO_Port GPIOF
#define I2C4_WP_Pin GPIO_PIN_13
#define I2C4_WP_GPIO_Port GPIOF
#define MCU2_STATUS_Pin GPIO_PIN_7
#define MCU2_STATUS_GPIO_Port GPIOE
#define MCU2_RX_STATUS_Pin GPIO_PIN_8
#define MCU2_RX_STATUS_GPIO_Port GPIOE
#define MCU1_RX_DATA_Pin GPIO_PIN_9
#define MCU1_RX_DATA_GPIO_Port GPIOE
#define MCU1_TX_DATA_Pin GPIO_PIN_10
#define MCU1_TX_DATA_GPIO_Port GPIOE
#define MCU1_nSS_Pin GPIO_PIN_11
#define MCU1_nSS_GPIO_Port GPIOE
#define MCU1_MCLK_Pin GPIO_PIN_12
#define MCU1_MCLK_GPIO_Port GPIOE
#define MCU1_MISO_Pin GPIO_PIN_13
#define MCU1_MISO_GPIO_Port GPIOE
#define MCU1_MOSI_Pin GPIO_PIN_14
#define MCU1_MOSI_GPIO_Port GPIOE
#define LED_RED_Pin GPIO_PIN_10
#define LED_RED_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_11
#define LED_GREEN_GPIO_Port GPIOC
#define LED_BLUE_Pin GPIO_PIN_12
#define LED_BLUE_GPIO_Port GPIOC
#define MCU_DEFAULT_Pin GPIO_PIN_5
#define MCU_DEFAULT_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
