/*
 * AD5453.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#include "AD5453.h"

extern SPI_HandleTypeDef hspi2;

static uint32_t AD5453_ConvertAmplitudeToRegister(double amplitude)
{
	uint16_t amplitude_reg;
	double mdac_amplitude;

	mdac_amplitude = voltage/AD5453_GAIN;
	return voltage_reg = (uint16_t)(adc_volt*pow(2,14)/AD5689_EXT_REF);
}

static BRD_StatusTypeDef AD5453_WriteToRegister(uint16_t value)
{
	tx_data.word16 = value;
	BRD_StatusTypeDef spi_status;

	HAL_GPIO_WritePin(DDS_MDAC_nSYNC_GPIO_Port, DDS_MDAC_nSYNC_Pin, OFF);
	spi_status = HAL_SPI_Transmit(&hspi2, tx_data.bytes, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(DDS_MDAC_nSYNC_GPIO_Port, DDS_MDAC_nSYNC_Pin, ON);

	return spi_status;
}

BRD_StatusTypeDef AD5453_SetVoltage(double voltage)
{
	BRD_StatusTypeDef spi_status;

	return spi_status;
}
