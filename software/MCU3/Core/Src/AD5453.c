/*
 * AD5453.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#include <math.h>
#include "AD5453.h"

extern SPI_HandleTypeDef hspi2;

static uint16_t AD5453_ConvertAmplitudeToRegister(double amplitude)
{
	uint16_t amplitude_reg;
	double mdac_amplitude;

	mdac_amplitude = amplitude/AD5453_GAIN;
	amplitude_reg = (uint16_t)(mdac_amplitude*pow(2,14)/AD5453_VREF);
	if(amplitude_reg > 0x3FFF)
	{
		amplitude_reg = 0x3FFF;
	}
	amplitude_reg = (uint16_t)(amplitude_reg & 0x3FFF);
	return amplitude_reg;
}

static BRD_StatusTypeDef AD5453_WriteToRegister(uint16_t value)
{
	ad5453_tx_data.word16 = value;
	BRD_StatusTypeDef spi_status;

	HAL_GPIO_WritePin(DDS_MDAC_nSYNC_GPIO_Port, DDS_MDAC_nSYNC_Pin, OFF);
	spi_status = HAL_SPI_Transmit(&hspi2, ad5453_tx_data.bytes, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(DDS_MDAC_nSYNC_GPIO_Port, DDS_MDAC_nSYNC_Pin, ON);

	return spi_status;
}

BRD_StatusTypeDef AD5453_SetVoltage(double amplitude)
{
	uint16_t amplitude_reg = AD5453_ConvertAmplitudeToRegister(amplitude);
	return AD5453_WriteToRegister( AD5453_LOAD_AND_UPDATE | amplitude_reg);
}
