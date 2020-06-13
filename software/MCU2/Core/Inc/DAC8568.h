/*
 * DAC8568.h
 *
 *  Created on: Apr 19, 2020
 *      Author: grzegorz
 */

#ifndef INC_DAC8568_H_
#define INC_DAC8568_H_

#define DAC_CH_A			0U
#define DAC_CH_B			(1<<20)
#define DAC_CH_C			(2<<20)
#define DAC_CH_D			(3<<20)
#define DAC_CH_E			(4<<20)
#define DAC_CH_F			(5<<20)
#define DAC_CH_G			(6<<20)
#define DAC_CH_H			(7<<20)
#define DAC_CH_ALL			(15<<20)

#define DAC_UPDATE_SINGLE	(1<<24)
#define DAC_WR_UPD_SINGLE	(3<<24)
#define DAC_WR_UPD_ALL		(1<<25)

#define DAC_CLEAR_ZERO 		(5<<24)
#define DAC_CLEAR_MID		(5<<24 | 1)
#define DAC_CLEAR_FULL		(5<<24 | 2)

#define DAC_REF				2.5000
#define DAC_REF_HALF		1.25
#define DAC_GAIN			1U
#define DAC_OPAMP_GAIN		8U
#define DAC_16BIT			65535

typedef union
{
	uint32_t word32;
	uint8_t bytes[4];
}dac_data_t;

BRD_StatusTypeDef DAC8568_SetVoltage(uint32_t param, double voltage);
BRD_StatusTypeDef DAC8568_ResetAll();

#endif /* INC_DAC8568_H_ */
