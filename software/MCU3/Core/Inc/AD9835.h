/*
 * AD9835.h
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#ifndef INC_AD9835_H_
#define INC_AD9835_H_

#include "main.h"

#define AD9835_FMCLK						50000000U

#define AD9835_FREQ0 						0U
#define AD9835_FREQ1 						1U
#define AD9835_PHASE0 						0U
#define AD9835_PHASE1 						1U
#define AD9835_PHASE2 						2U
#define AD9835_PHASE3 						3U

#define AD9835_CONTROL 						0xC000U
#define AD9835_SELECT 						0x8000U
#define AD9835_SLEEP 						0x2000U
#define AD9835_RESET						0x1000U

#define AD9835_WRITE_PHASE16				0x0000U
#define AD9835_WRITE_PHASE8					0x1000U
#define AD9835_WRITE_FREQ16					0x2000U
#define AD9835_WRITE_FREQ8					0x3000U
#define AD9835_SELECT_PHASE					0x4000U
#define AD9835_SELECT_FREQ					0x5000U

#define AD9835_FREQ0_LLSB					0x0000U
#define AD9835_FREQ0_HLSB					0x0100U
#define AD9835_FREQ0_LMSB					0x0200U
#define AD9835_FREQ0_HMSB					0x0300U
#define AD9835_FREQ1_LLSB					0x0400U
#define AD9835_FREQ1_HLSB					0x0500U
#define AD9835_FREQ1_LMSB					0x0600U
#define AD9835_FREQ1_HMSB					0x0700U

#define AD9835_PHASE0_LSB					0x0800U
#define AD9835_PHASE0_MSB					0x0900U
#define AD9835_PHASE1_LSB					0x0A00U
#define AD9835_PHASE1_MSB					0x0B00U
#define AD9835_PHASE2_LSB					0x0C00U
#define AD9835_PHASE2_MSB					0x0D00U
#define AD9835_PHASE3_LSB					0x0E00U
#define AD9835_PHASE3_MSB					0x0F00U

#define AD9835_SPI_SELSRC					0x1000U
#define AD9835_GPIO_SELSRC 					0x0000U

#define AD9835_PHASE_REG_SEL 				0x4000U
#define AD9835_FREQ_REG_SEL	 				0x5000U

#define AD9835_FREQ0_SEL	 				0x0000U
#define AD9835_FREQ1_SEL	 				0x0800U

#define AD9835_PHASE0_SEL					0x0000U
#define AD9835_PHASE1_SEL					0x0200U
#define AD9835_PHASE2_SEL					0x0400U
#define AD9835_PHASE3_SEL					0x0600U

#define AD9835_SPI 							0U
#define AD9835_GPIO 						1U

#define AD9835_ON 							1U
#define AD9835_OFF 							0U

#define AD9835_PHASE_REG_MAX 				4096

union tx_union
{
	uint16_t word16;
	uint8_t bytes[2];
}tx_data;

BRD_StatusTypeDef AD9835_Output(uint8_t state);
BRD_StatusTypeDef AD9835_Init(void);
BRD_StatusTypeDef AD9835_FrequencyRegister(uint8_t freq_reg, uint32_t freq);
BRD_StatusTypeDef AD9835_PhaseRegister(void);
BRD_StatusTypeDef AD9835_SelectionType(uint8_t select);
BRD_StatusTypeDef AD9835_FrequencyRegisterSelect(uint8_t freq_reg);
BRD_StatusTypeDef AD9835_PhaseRegisterSelect(uint8_t phase_reg);
void AD9835_Test(void);

#endif /* INC_AD9835_H_ */
