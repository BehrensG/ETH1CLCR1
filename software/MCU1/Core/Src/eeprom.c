/*
 * eeprom.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */


HAL_StatusTypeDef EEPROM_WriteDefaultValues()
{
	HAL_GPIO_WritePin(I2C4_WP_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);

	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_Port, I2C4_WP_Pin, 0);


}

HAL_StatusTypeDef EEPROM_Reset()
{
	HAL_GPIO_WritePin(I2C4_WP_Port, I2C4_WP_Pin, 1);
	HAL_Delay(10);



	HAL_Delay(10);
	HAL_GPIO_WritePin(I2C4_WP_Port, I2C4_WP_Pin, 0);

}
