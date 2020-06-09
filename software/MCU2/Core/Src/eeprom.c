/*
 * eeprom.c
 *
 *  Created on: Jun 9, 2020
 *      Author: BehrensG
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eeprom.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c4;

BRD_StatusTypeDef EEPROM_Reset()
{
	uint8_t tx_data[17] = {[0 ... 16] = 0xFF};
	BRD_StatusTypeDef i2c_status;
	uint8_t index = 0;

	LL_GPIO_ResetOutputPin(EEPROM_WP_GPIO_Port, EEPROM_WP_Pin);
	HAL_Delay(10);

	for (uint8_t i = 0; i < EEPROM_BLOCK_COUNT; i++)
	{
		index = 0;
		for (uint8_t j = 0; j < (EEPROM_BLOCK_SIZE/16); j++)
		{
			tx_data[0] = index;

			i2c_status = HAL_I2C_Master_Transmit(&hi2c4, EEPROM_ADDRESS+i, tx_data, 17, 1000);
			if(BRD_OK != i2c_status)
			{
				return i2c_status;
			}
			HAL_Delay(5);
			index += 16;
		}

	}

	HAL_Delay(10);
	LL_GPIO_SetOutputPin(EEPROM_WP_GPIO_Port, EEPROM_WP_Pin);
	HAL_Delay(10);

	return i2c_status;

}
