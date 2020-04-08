/*
 * eeprom.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eeprom.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c4;


BRD_StatusTypeDef EEPROM_WriteDefaultValues()
{
	BRD_StatusTypeDef status;
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
			if(BRD_OK != status)
			{
				return status;
			}
			HAL_Delay(5);
		}

	}

	tx_data[0] = 0xFF;
	tx_data[1] = EEPROM_WRITE_STATE;

	status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS | EEPROM_B0 | EEPROM_B1, tx_data, 2, 1000);
	if(BRD_OK != status)
	{
		return status;
	}

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	return BRD_OK;
}

BRD_StatusTypeDef EEPROM_Reset()
{
	uint8_t tx_data[17] = {[0 ... 16] = 0xFF};
	BRD_StatusTypeDef status;
	uint8_t index = 0;

	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);
	HAL_Delay(10);

	for (uint8_t i = 0; i < EEPROM_BLOCK_COUNT; i++)
	{
		index = 0;
		for (uint8_t j = 0; j < (EEPROM_BLOCK_SIZE/16); j++)
		{
			tx_data[0] = index;

			status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS+i, tx_data, 17, 1000);
			if(BRD_OK != status)
			{
				return status;
			}
			HAL_Delay(5);
			index += 16;
		}

	}

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	return status;

}

BRD_StatusTypeDef EEPROM_WriteValues()
{
	BRD_StatusTypeDef status;
	uint8_t tx_data[2] = {};
	uint16_t limit = STRUCT_SIZE;
	uint8_t blocks = (uint8_t)ceil((float)STRUCT_SIZE/(float)EEPROM_BLOCK_COUNT);

	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);
	HAL_Delay(10);

	for (uint8_t i = 0; i < blocks; i++)
	{
		limit = abs(limit - 256);
		for (uint16_t j = 0; j < limit; j++)
		{
			tx_data[0] = j;
			tx_data[1] = board.bytes[i*EEPROM_BLOCK_SIZE+j];

			status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS+i, tx_data, 2, 1000);
			if(BRD_OK != status)
			{
				return status;
			}
			HAL_Delay(5);
		}

	}

	tx_data[0] = 0xFF;
	tx_data[1] = EEPROM_WRITE_STATE;
	status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS | EEPROM_B0 | EEPROM_B1, tx_data, 2, 1000);
	if(BRD_OK != status)
	{
		return status;
	}

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	return BRD_OK;
}

BRD_StatusTypeDef EEPROM_Read(union brd_data *union_data, uint16_t size)
{
	uint8_t rx_data;
	uint8_t tx_data = 0xFF;
	BRD_StatusTypeDef status;
	uint16_t limit = size;
	uint8_t blocks = (uint8_t)ceil((float)size/(float)EEPROM_BLOCK_COUNT);

	if (size > EEPROM_SIZE)
	{
		return BRD_EEPROM_MAX_SIZE;
	}

	status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS | EEPROM_B0 | EEPROM_B1, &tx_data, 1, 100);
	if(BRD_OK != status)
	{
		return status;
	}
	status = HAL_I2C_Master_Receive(&hi2c4, EEPROM_ADDRESS | EEPROM_B0 | EEPROM_B1, &rx_data, 1, 100);
	if(BRD_OK != status)
	{
		return status;
	}

	if(EEPROM_WRITE_STATE != rx_data)
	{
		return BRD_EEPROM_EMPTY;
	}

	for (uint16_t i = 0; i < blocks; i++)
		{
			limit = abs(limit - 256);
			for (uint16_t j = 0; j < limit; j++)
			{

				status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS+i, j, 1, 100);
				if(BRD_OK != status)
				{
					return status;
				}
				status = HAL_I2C_Master_Receive(&hi2c4, EEPROM_ADDRESS+i, union_data->bytes[j], 1, 100);
				if(BRD_OK != status)
				{
					return status;
				}
				HAL_Delay(5);
			}

		}

	return BRD_OK;

}
