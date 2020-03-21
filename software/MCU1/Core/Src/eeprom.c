/*
 * eeprom.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#include "eeprom.h"
#include "main.h"

HAL_StatusTypeDef EEPROM_WriteDefaultValues()
{
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	uint8_t* AddrOfStruct = NULL;
	uint16_t SizeOfStruct = 0;

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);


}

HAL_StatusTypeDef EEPROM_Reset()
{
	uint8_t tx_data[EEPROM_SIZE] = {0xFF};
	HAL_StatusTypeDef status;

	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	status = HAL_I2C_Mem_Write(I2C4, EEPROM_ADDRESS, 0x0000, EEPROM_SIZE, tx_data, EEPROM_SIZE, 5000);

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_GPIO_Port, I2C4_WP_Pin, 0);

	return status;

}

HAL_StatusTypeDef EEPROM_ReadValues()
{
	return HAL_OK;
}
