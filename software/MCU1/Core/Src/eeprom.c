/*
 * eeprom.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#include "eeprom.h"
#include "main.h"
#include "board.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern I2C_HandleTypeDef hi2c4;


HAL_StatusTypeDef EEPROM_WriteDefaultValues()
{
	HAL_StatusTypeDef status;
	uint8_t tx_data[2] = {};
	uint16_t limit = STRUCT_SIZE;

	uint8_t blocks = (uint8_t)ceil((float)STRUCT_SIZE/(float)EEPROM_BLOCK_COUNT);

	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);
	HAL_Delay(10);

	for (uint16_t i = 0; i < blocks; i++)
	{
		limit = abs(limit - 256);
		for (uint16_t j = 0; j < limit; j++)
		{
			tx_data[0] = j;
			tx_data[1] = default_board.bytes[i*EEPROM_BLOCK_SIZE+j];

			status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS+i, tx_data, 2, 1000);
			if(HAL_OK != status)
			{
				return status;
			}
			HAL_Delay(5);
		}

	}

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	return HAL_OK;

}

HAL_StatusTypeDef EEPROM_Reset()
{
	uint8_t tx_data[256] = {};
	HAL_StatusTypeDef status;

	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);
	HAL_Delay(10);

	for (uint8_t i = 0; i < 256; i++)
	{
		status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS, tx_data, 256, 1000);
		if (status != HAL_OK)
		{
			HAL_Delay(10);
			HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
			return status;
		}
	}

	for (uint8_t i = 0; i < 256; i++)
	{
		status = HAL_I2C_Master_Transmit(&hi2c4, (EEPROM_ADDRESS | EEPROM_B0), tx_data, 256, 1000);
		if (status != HAL_OK)
		{
			HAL_Delay(10);
			HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
			return status;
		}
	}

	for (uint8_t i = 0; i < 256; i++)
	{
		status = HAL_I2C_Master_Transmit(&hi2c4, (EEPROM_ADDRESS | EEPROM_B1), tx_data, 256, 1000);
		if (status != HAL_OK)
		{
			HAL_Delay(10);
			HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
			return status;
		}
	}

	for (uint8_t i = 0; i < 256; i++)
	{
		status = HAL_I2C_Master_Transmit(&hi2c4, (EEPROM_ADDRESS | EEPROM_B0 | EEPROM_B1), tx_data, 256, 1000);
		if (status != HAL_OK)
		{
			HAL_Delay(10);
			HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
			return status;
		}
	}

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	return status;

}

HAL_StatusTypeDef EEPROM_ReadValues()
{
	return HAL_OK;
}
