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
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx.h"
#include "stm32h7xx_ll_system.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_exti.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_cortex.h"
#include "stm32h7xx_ll_utils.h"
#include "stm32h7xx_ll_pwr.h"
#include "stm32h7xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ADC.h"
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
#define MCU3_SCLK_Pin LL_GPIO_PIN_2
#define MCU3_SCLK_GPIO_Port GPIOE
#define MCU3_nSS_Pin LL_GPIO_PIN_4
#define MCU3_nSS_GPIO_Port GPIOE
#define MCU3_MISO_Pin LL_GPIO_PIN_5
#define MCU3_MISO_GPIO_Port GPIOE
#define MCU3_MOSI_Pin LL_GPIO_PIN_6
#define MCU3_MOSI_GPIO_Port GPIOE
#define DAC_nLDAC_Pin LL_GPIO_PIN_4
#define DAC_nLDAC_GPIO_Port GPIOF
#define DAC_nCLR_Pin LL_GPIO_PIN_5
#define DAC_nCLR_GPIO_Port GPIOF
#define DAC_nSYNC_Pin LL_GPIO_PIN_6
#define DAC_nSYNC_GPIO_Port GPIOF
#define DAC_SCLK_Pin LL_GPIO_PIN_7
#define DAC_SCLK_GPIO_Port GPIOF
#define DAC_NOT_USED_Pin LL_GPIO_PIN_8
#define DAC_NOT_USED_GPIO_Port GPIOF
#define DAC_DIN_Pin LL_GPIO_PIN_9
#define DAC_DIN_GPIO_Port GPIOF
#define MCU1_nSS_Pin LL_GPIO_PIN_4
#define MCU1_nSS_GPIO_Port GPIOA
#define MCU1_SCLK_Pin LL_GPIO_PIN_5
#define MCU1_SCLK_GPIO_Port GPIOA
#define MCU1_MISO_Pin LL_GPIO_PIN_6
#define MCU1_MISO_GPIO_Port GPIOA
#define MCU1_MOSI_Pin LL_GPIO_PIN_7
#define MCU1_MOSI_GPIO_Port GPIOA
#define MCU1_TX_DATA_Pin LL_GPIO_PIN_1
#define MCU1_TX_DATA_GPIO_Port GPIOB
#define MCU1_RX_DATA_Pin LL_GPIO_PIN_2
#define MCU1_RX_DATA_GPIO_Port GPIOB
#define MCU2_RX_STATUS_Pin LL_GPIO_PIN_11
#define MCU2_RX_STATUS_GPIO_Port GPIOF
#define MCU2_STATUS_Pin LL_GPIO_PIN_12
#define MCU2_STATUS_GPIO_Port GPIOF
#define EEPROM_WP_Pin LL_GPIO_PIN_13
#define EEPROM_WP_GPIO_Port GPIOF
#define EEPROM_SCL_Pin LL_GPIO_PIN_14
#define EEPROM_SCL_GPIO_Port GPIOF
#define EEPROM_SDA_Pin LL_GPIO_PIN_15
#define EEPROM_SDA_GPIO_Port GPIOF
#define CXN_REL6_Pin LL_GPIO_PIN_0
#define CXN_REL6_GPIO_Port GPIOG
#define CXN_REL5_Pin LL_GPIO_PIN_1
#define CXN_REL5_GPIO_Port GPIOG
#define CXN_REL4_Pin LL_GPIO_PIN_7
#define CXN_REL4_GPIO_Port GPIOE
#define CXN_REL3_Pin LL_GPIO_PIN_8
#define CXN_REL3_GPIO_Port GPIOE
#define CXN_REL2_Pin LL_GPIO_PIN_9
#define CXN_REL2_GPIO_Port GPIOE
#define CXN_REL1_Pin LL_GPIO_PIN_10
#define CXN_REL1_GPIO_Port GPIOE
#define SR_10KCTR_Pin LL_GPIO_PIN_12
#define SR_10KCTR_GPIO_Port GPIOE
#define SR_100CTR_Pin LL_GPIO_PIN_13
#define SR_100CTR_GPIO_Port GPIOE
#define SR_1KCTR_Pin LL_GPIO_PIN_14
#define SR_1KCTR_GPIO_Port GPIOE
#define SR_10CTR_Pin LL_GPIO_PIN_15
#define SR_10CTR_GPIO_Port GPIOE
#define FB_CAP_Pin LL_GPIO_PIN_10
#define FB_CAP_GPIO_Port GPIOB
#define FB_nCS_Pin LL_GPIO_PIN_12
#define FB_nCS_GPIO_Port GPIOB
#define FB_CLK_Pin LL_GPIO_PIN_13
#define FB_CLK_GPIO_Port GPIOB
#define FB_SDO_Pin LL_GPIO_PIN_14
#define FB_SDO_GPIO_Port GPIOB
#define FB_SDI_Pin LL_GPIO_PIN_15
#define FB_SDI_GPIO_Port GPIOB
#define FB_RDY_Pin LL_GPIO_PIN_9
#define FB_RDY_GPIO_Port GPIOD
#define FB_nRST_Pin LL_GPIO_PIN_10
#define FB_nRST_GPIO_Port GPIOD
#define RR_RELAYCTR_Pin LL_GPIO_PIN_12
#define RR_RELAYCTR_GPIO_Port GPIOD
#define RR_HA3_COMP_Pin LL_GPIO_PIN_13
#define RR_HA3_COMP_GPIO_Port GPIOD
#define RR_10CTR_Pin LL_GPIO_PIN_14
#define RR_10CTR_GPIO_Port GPIOD
#define RR_100CTR_Pin LL_GPIO_PIN_15
#define RR_100CTR_GPIO_Port GPIOD
#define RR_1KCTR_Pin LL_GPIO_PIN_2
#define RR_1KCTR_GPIO_Port GPIOG
#define RR_10KCTR_Pin LL_GPIO_PIN_3
#define RR_10KCTR_GPIO_Port GPIOG
#define RR_100KCTR_Pin LL_GPIO_PIN_4
#define RR_100KCTR_GPIO_Port GPIOG
#define PA_MOS2_Pin LL_GPIO_PIN_6
#define PA_MOS2_GPIO_Port GPIOC
#define PA_MOS1_Pin LL_GPIO_PIN_7
#define PA_MOS1_GPIO_Port GPIOC
#define PA_MOS4_Pin LL_GPIO_PIN_8
#define PA_MOS4_GPIO_Port GPIOC
#define PA_MOS3_Pin LL_GPIO_PIN_9
#define PA_MOS3_GPIO_Port GPIOC
#define PA_MOS6_Pin LL_GPIO_PIN_8
#define PA_MOS6_GPIO_Port GPIOA
#define PA_MOS5_Pin LL_GPIO_PIN_9
#define PA_MOS5_GPIO_Port GPIOA
#define PA_ER_Pin LL_GPIO_PIN_10
#define PA_ER_GPIO_Port GPIOA
#define PA_EM_Pin LL_GPIO_PIN_11
#define PA_EM_GPIO_Port GPIOA
#define PA_50MV_Pin LL_GPIO_PIN_12
#define PA_50MV_GPIO_Port GPIOA
#define ADC_nCS_Pin LL_GPIO_PIN_15
#define ADC_nCS_GPIO_Port GPIOA
#define ADC_SCLK_Pin LL_GPIO_PIN_10
#define ADC_SCLK_GPIO_Port GPIOC
#define ADC_SDOA_Pin LL_GPIO_PIN_11
#define ADC_SDOA_GPIO_Port GPIOC
#define ADC_SDI_Pin LL_GPIO_PIN_12
#define ADC_SDI_GPIO_Port GPIOC
#define ADC_nALARM_Pin LL_GPIO_PIN_0
#define ADC_nALARM_GPIO_Port GPIOD
#define G1A1_CTR_Pin LL_GPIO_PIN_1
#define G1A1_CTR_GPIO_Port GPIOD
#define G1A0_CTR_Pin LL_GPIO_PIN_2
#define G1A0_CTR_GPIO_Port GPIOD
#define G2A1_CTR_Pin LL_GPIO_PIN_3
#define G2A1_CTR_GPIO_Port GPIOD
#define G2A0_CTR_Pin LL_GPIO_PIN_4
#define G2A0_CTR_GPIO_Port GPIOD
#define ADC_NULL1_Pin LL_GPIO_PIN_5
#define ADC_NULL1_GPIO_Port GPIOD
#define ADC_NULL2_Pin LL_GPIO_PIN_6
#define ADC_NULL2_GPIO_Port GPIOD
#define RR_SDI_Pin LL_GPIO_PIN_7
#define RR_SDI_GPIO_Port GPIOD
#define RR_SDO_Pin LL_GPIO_PIN_9
#define RR_SDO_GPIO_Port GPIOG
#define RR_nCS_Pin LL_GPIO_PIN_10
#define RR_nCS_GPIO_Port GPIOG
#define RR_CLK_Pin LL_GPIO_PIN_11
#define RR_CLK_GPIO_Port GPIOG
/* USER CODE BEGIN Private defines */


#define SPI6_BUFFOR_SIZE 128
#define SPI6_TX_MODE 1
#define SPI6_RX_MODE 2

typedef enum
{
	SPI6_MODE_NONE = 0U,
	SPI6_MODE_TX = 1U,
	SPI6_MODE_RX = 2U
}SPI6_Status;

#define ON	1U
#define OFF	0U

typedef enum
{
  BRD_OK       = 0x00U,
  BRD_ERROR    = 0x01U,
  BRD_BUSY     = 0x02U,
  BRD_TIMEOUT  = 0x03U
} BRD_StatusTypeDef;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
