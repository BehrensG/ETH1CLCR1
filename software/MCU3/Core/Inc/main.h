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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

#define ON 1U
#define OFF 0U

typedef enum
{
  BRD_OK       = 0x00U,
  BRD_ERROR    = 0x01U,
  BRD_BUSY     = 0x02U,
  BRD_TIMEOUT  = 0x03U,
  BRD_INVALID_PHASE = 0x04U,
  BRD_INVALID_VOLTAGE = 0x05U
} BRD_StatusTypeDef;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DDS_FGEN_FSELECT_Pin GPIO_PIN_3
#define DDS_FGEN_FSELECT_GPIO_Port GPIOA
#define DDS_FGEN_nFSYNC_Pin GPIO_PIN_4
#define DDS_FGEN_nFSYNC_GPIO_Port GPIOA
#define DDS_FGEN_SCLK_Pin GPIO_PIN_5
#define DDS_FGEN_SCLK_GPIO_Port GPIOA
#define DDS_FGEN_SDATA_Pin GPIO_PIN_7
#define DDS_FGEN_SDATA_GPIO_Port GPIOA
#define DDS_FGEN_PSEL0_Pin GPIO_PIN_4
#define DDS_FGEN_PSEL0_GPIO_Port GPIOC
#define DDS_FGEN_PSEL1_Pin GPIO_PIN_5
#define DDS_FGEN_PSEL1_GPIO_Port GPIOC
#define DDS_DAC_SCLK_Pin GPIO_PIN_0
#define DDS_DAC_SCLK_GPIO_Port GPIOB
#define DDS_DAC_nSYNC_Pin GPIO_PIN_1
#define DDS_DAC_nSYNC_GPIO_Port GPIOB
#define DDS_DAC_nLDAC_Pin GPIO_PIN_2
#define DDS_DAC_nLDAC_GPIO_Port GPIOB
#define ANALOG_SWITCH_Pin GPIO_PIN_10
#define ANALOG_SWITCH_GPIO_Port GPIOB
#define DDS_MDAC_nSYNC_Pin GPIO_PIN_12
#define DDS_MDAC_nSYNC_GPIO_Port GPIOB
#define DDS_MDAC_SCLK_Pin GPIO_PIN_13
#define DDS_MDAC_SCLK_GPIO_Port GPIOB
#define DDS_MDAC_DIN_Pin GPIO_PIN_15
#define DDS_MDAC_DIN_GPIO_Port GPIOB
#define DDS_DAC_RSTSEL_Pin GPIO_PIN_8
#define DDS_DAC_RSTSEL_GPIO_Port GPIOA
#define DDS_DAC_nRESET_Pin GPIO_PIN_9
#define DDS_DAC_nRESET_GPIO_Port GPIOA
#define DDS_DAC_SDIN_Pin GPIO_PIN_10
#define DDS_DAC_SDIN_GPIO_Port GPIOA
#define DDS_DAC_SDO_Pin GPIO_PIN_12
#define DDS_DAC_SDO_GPIO_Port GPIOA
#define MCU3_NSS_Pin GPIO_PIN_15
#define MCU3_NSS_GPIO_Port GPIOA
#define MCU3_SCLK_Pin GPIO_PIN_10
#define MCU3_SCLK_GPIO_Port GPIOC
#define MCU3_MISO_Pin GPIO_PIN_11
#define MCU3_MISO_GPIO_Port GPIOC
#define MCU3_MOSI_Pin GPIO_PIN_12
#define MCU3_MOSI_GPIO_Port GPIOC
#define EEPROM_WP_Pin GPIO_PIN_4
#define EEPROM_WP_GPIO_Port GPIOB
#define EEPROM_SCL_Pin GPIO_PIN_6
#define EEPROM_SCL_GPIO_Port GPIOB
#define EEPROM_SDA_Pin GPIO_PIN_7
#define EEPROM_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* Size of buffer */
#define BUFFERSIZE	64U


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
