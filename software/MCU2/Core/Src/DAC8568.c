/*
 * DAC8568.c
 *
 *  Created on: Apr 19, 2020
 *      Author: grzegorz
 */

#include "main.h"
#include "board.h"
#include "DAC8568.h"

static uint16_t DAC8568_ConvertVoltageToData16(double voltage)
{
	uint16_t data = 0x0000;
	double volt_tmp = 0.0;

	volt_tmp = voltage/(double)DAC_OPAMP_GAIN;
	volt_tmp += DAC_REF_HALF;

	data = (volt_tmp*DAC_16BIT)/(DAC_REF*DAC_GAIN);

	return data;
}

BRD_StatusTypeDef DAC8568_SetVoltage(uint32_t param, double voltage)
{
	uint16_t volt_data = 0x0000;
	dac_data_t tx_data;

	volt_data = DAC8568_ConvertVoltageToData16(voltage);
	tx_data.word32 = param | (volt_data << 4);

	return BRD_OK;
}

BRD_StatusTypeDef DAC8568_ResetAll()
{
	// TBD
	return BRD_OK;
}
