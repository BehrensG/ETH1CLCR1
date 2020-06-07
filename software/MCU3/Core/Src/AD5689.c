/*
 * AD5689.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */


#include <math.h>
#include "AD5689.h"

extern SPI_HandleTypeDef hspi5;

static BRD_StatusTypeDef AD5689_WriteToRegister(uint32_t value)
{	uint8_t tx_data[2];
	uint8_t tx_data[] = {0x00, 0x00, 0x00};
	BRD_StatusTypeDef spi_status;

	tx_data[0] = (uint8_t)(value >> 16);
	tx_data[1] = (uint8_t)(value >> 8);
	tx_data[2] = (uint8_t)(value);

	HAL_GPIO_WritePin(DDS_DAC_nSYNC_GPIO_Port, DDS_DAC_nSYNC_Pin, OFF);
	spi_status = HAL_SPI_Transmit(&hspi5, tx_data, 3, 1000);
	HAL_GPIO_WritePin(DDS_DAC_nSYNC_GPIO_Port, DDS_DAC_nSYNC_Pin, ON);

	return spi_status;
}

static uint16_t AD5689_ConvertVOUTBToRegister(double voltage)
{
	uint16_t voltage_reg;
	double dac_volt;

	dac_volt = (voltage+AD5689_VOUTB_OFFSET)/AD5689_VOUTB_GAIN;
	return voltage_reg = (uint16_t)(dac_volt*pow(2,16)/AD5689_EXT_REF);

}

BRD_StatusTypeDef AD5689_SetVOUTB(double voltage)
{
	BRD_StatusTypeDef spi_status;

	uint16_t voltage_reg = AD5689_ConvertVOUTBToRegister(voltage);

	spi_status = AD5689_WriteToRegister(AD5689_CMD_WRITE_AND_UPDATE_DAC | AD5689_ADDR_DAC_B | (uint32_t)voltage_reg);

	return spi_status;
}


BRD_StatusTypeDef AD5689_SoftReset()
{
	BRD_StatusTypeDef spi_status;

	spi_status = AD5689_WriteToRegister(AD5689_CMD_SOFWARE_RESET);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	return BRD_OK;
}

void AD5689_HardReset()
{
	HAL_GPIO_WritePin(DDS_DAC_nRESET_GPIO_Port, DDS_DAC_nRESET_Pin, OFF);
	HAL_Delay(1);
	HAL_GPIO_WritePin(DDS_DAC_nRESET_GPIO_Port, DDS_DAC_nRESET_Pin, ON);
}

void AD5689_Init()
{
	HAL_GPIO_WritePin(DDS_DAC_nRESET_GPIO_Port, DDS_DAC_nRESET_Pin, ON);
	HAL_GPIO_WritePin(DDS_DAC_nLDAC_GPIO_Port, DDS_DAC_nLDAC_Pin, OFF);
	AD5689_SetVOUTB(0.0);
}
