/*
 * AD5689.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#include "AD5689.h"

uint16_t AD5698_ConvertVoltageToRegisterB(float voltage)
{
	float tmp;
	tmp = voltage/AD5689_VOUTB_GAIN;
}

BRD_StatusTypeDef AD5698_SetVoltageB(float voltage)
{
	uint8_t reg[] = {0xFF, 0xFF, 0xFF};
	BRD_StatusTypeDef spi_status;

	return BRD_OK;
}


BRD_StatusTypeDef AD5698_SoftReset()
{
	return BRD_OK;
}

BRD_StatusTypeDef AD5698_HardReset()
{
	return BRD_OK;
}

BRD_StatusTypeDef AD5698_PowerDown(uint8_t operating_mode_A, uint8_t operating_mode_B)
{
	return BRD_OK;
}
