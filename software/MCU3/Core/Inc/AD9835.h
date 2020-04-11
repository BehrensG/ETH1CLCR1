/*
 * AD9835.h
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#ifndef INC_AD9835_H_
#define INC_AD9835_H_

#include "main.h"

#define AD9835_FREQ_CONV_CONST 				0.16777216 // 2^23/50MHz
#define AD9835_FREQ0 						0U
#define AD9835_FREQ1 						1U
#define AD9835_PHASE0 						0U
#define AD9835_PHASE1 						1U
#define AD9835_PHASE2 						2U
#define AD9835_PHASE3 						3U
#define AD9835_CONTROL 						0xC0U
#define AD9835_SELECT 						0x80U
#define AD9835_SLEEP_BIT 					0x02U
#define AD9835_RESET_BIT 					0x01U
#define AD9835_SPI_SELSRC_BIT				0x01U
#define AD9835_GPIO_SELSRC_BIT 				0x00U
#define AD9835_PHASE_SEL_REG 				0x40U
#define AD9835_FREQ_SEL_REG 				0x50U
#define AD9835_PSEL0 						0x02U
#define AD9835_PSEL1 						0x04U
#define AD9835_SPI 							0U
#define AD9835_GPIO 						1U
#define AD9835_ON 							1U
#define AD9835_OFF 							0U
#define AD9835_PHASE_REG_MAX 				4096

BRD_StatusTypeDef AD9835_Output(uint8_t state);
BRD_StatusTypeDef AD9835_Init(void);
BRD_StatusTypeDef AD9835_FrequencyRegister(uint8_t freq_reg, uint32_t freq);
BRD_StatusTypeDef AD9835_PhaseRegister(void);
BRD_StatusTypeDef AD9835_SelectionType(uint8_t select);
BRD_StatusTypeDef AD9835_FrequencyRegisterSelect(uint8_t freq_reg);
BRD_StatusTypeDef AD9835_PhaseRegisterSelect(uint8_t phase_reg);

#endif /* INC_AD9835_H_ */
