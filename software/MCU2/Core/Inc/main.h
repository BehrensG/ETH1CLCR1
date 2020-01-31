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
#include "stm32h7xx_hal.h"

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
#define MCU1_GPIO_OUT1_Pin GPIO_PIN_13
#define MCU1_GPIO_OUT1_GPIO_Port GPIOC
#define MCU1_GPIO_OUT2_Pin GPIO_PIN_14
#define MCU1_GPIO_OUT2_GPIO_Port GPIOC
#define MCU1_STATUS_IN_Pin GPIO_PIN_15
#define MCU1_STATUS_IN_GPIO_Port GPIOC
#define DAC_nCLR_Pin GPIO_PIN_4
#define DAC_nCLR_GPIO_Port GPIOF
#define DAC_nLDAC_Pin GPIO_PIN_5
#define DAC_nLDAC_GPIO_Port GPIOF
#define RR_RDY_Pin GPIO_PIN_0
#define RR_RDY_GPIO_Port GPIOC
#define RR_nRST_Pin GPIO_PIN_3
#define RR_nRST_GPIO_Port GPIOC
#define ADC_nALARM_Pin GPIO_PIN_3
#define ADC_nALARM_GPIO_Port GPIOA
#define CXN_REL1_Pin GPIO_PIN_4
#define CXN_REL1_GPIO_Port GPIOC
#define CXN_REL2_Pin GPIO_PIN_5
#define CXN_REL2_GPIO_Port GPIOC
#define EEPROM_WP_Pin GPIO_PIN_13
#define EEPROM_WP_GPIO_Port GPIOF
#define PA_NULL_Pin GPIO_PIN_7
#define PA_NULL_GPIO_Port GPIOE
#define PA_EM_Pin GPIO_PIN_8
#define PA_EM_GPIO_Port GPIOE
#define PA_50MV_Pin GPIO_PIN_9
#define PA_50MV_GPIO_Port GPIOE
#define RR_10CRT_Pin GPIO_PIN_9
#define RR_10CRT_GPIO_Port GPIOD
#define RR_100CRT_Pin GPIO_PIN_10
#define RR_100CRT_GPIO_Port GPIOD
#define RR_1KCRT_Pin GPIO_PIN_11
#define RR_1KCRT_GPIO_Port GPIOD
#define RR_10KCRT_Pin GPIO_PIN_12
#define RR_10KCRT_GPIO_Port GPIOD
#define RR_100KCRT_Pin GPIO_PIN_13
#define RR_100KCRT_GPIO_Port GPIOD
#define RR_RELAYCRT_Pin GPIO_PIN_14
#define RR_RELAYCRT_GPIO_Port GPIOD
#define RR_HA3_COMP_Pin GPIO_PIN_15
#define RR_HA3_COMP_GPIO_Port GPIOD
#define CXN_REL1G2_Pin GPIO_PIN_2
#define CXN_REL1G2_GPIO_Port GPIOG
#define CXN_REL2G3_Pin GPIO_PIN_3
#define CXN_REL2G3_GPIO_Port GPIOG
#define CXN_REL3_Pin GPIO_PIN_4
#define CXN_REL3_GPIO_Port GPIOG
#define CXN_REL4_Pin GPIO_PIN_5
#define CXN_REL4_GPIO_Port GPIOG
#define CXN_REL5_Pin GPIO_PIN_6
#define CXN_REL5_GPIO_Port GPIOG
#define CXN_REL6_Pin GPIO_PIN_7
#define CXN_REL6_GPIO_Port GPIOG
#define SR_10KCTR_Pin GPIO_PIN_4
#define SR_10KCTR_GPIO_Port GPIOD
#define SR_1KCRT_Pin GPIO_PIN_5
#define SR_1KCRT_GPIO_Port GPIOD
#define SR_100CRT_Pin GPIO_PIN_6
#define SR_100CRT_GPIO_Port GPIOD
#define SR_10CRT_Pin GPIO_PIN_7
#define SR_10CRT_GPIO_Port GPIOD
#define FB_CAP_Pin GPIO_PIN_9
#define FB_CAP_GPIO_Port GPIOG
#define FB_RDY_Pin GPIO_PIN_10
#define FB_RDY_GPIO_Port GPIOG
#define FB_nRST_Pin GPIO_PIN_11
#define FB_nRST_GPIO_Port GPIOG
#define G1A1_CTR_Pin GPIO_PIN_4
#define G1A1_CTR_GPIO_Port GPIOB
#define G1A0_CTR_Pin GPIO_PIN_5
#define G1A0_CTR_GPIO_Port GPIOB
#define G2A1_CTR_Pin GPIO_PIN_6
#define G2A1_CTR_GPIO_Port GPIOB
#define G2A0_CTR_Pin GPIO_PIN_7
#define G2A0_CTR_GPIO_Port GPIOB
#define ADC_NULL2_Pin GPIO_PIN_8
#define ADC_NULL2_GPIO_Port GPIOB
#define ADC_NULL1_Pin GPIO_PIN_9
#define ADC_NULL1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
