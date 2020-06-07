/*
 * hdc1080.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */


#include <string.h>

#include "hdc1080.h"

static HAL_StatusTypeDef HDC1080_read_reg(I2C_HandleTypeDef *hi2c, uint16_t delay, uint8_t reg, uint16_t *val)
{
	uint8_t buf[2];
	HAL_StatusTypeDef  error;

	// Check argument
	if ((reg != HDC1080_TEMPERATURE) &
		  (reg != HDC1080_HUMIDITY) &
		  (reg != HDC1080_CONFIG) &
		  (reg != HDC1080_SERIAL_ID1) &
		  (reg != HDC1080_SERIAL_ID2) &
		  (reg != HDC1080_SERIAL_ID3) &
		  (reg != HDC1080_ID_MANU) &
	    (reg != HDC1080_ID_DEV) )
		return HAL_ERROR;

	buf[0] = reg;
	/* Read register */
	/* Send the read followed by address */
	error = HAL_I2C_Master_Transmit(hi2c,HDC1080_ADDR<<1,buf,1,100);
	if (error != HAL_OK)
		return error;

	HAL_Delay(delay);

	/* Receive a 2-byte result */
	error = HAL_I2C_Master_Receive(hi2c, HDC1080_ADDR<<1 | 0x01, buf, 2, 1000);
	if (error != HAL_OK)
		return error;

	/* Result */
	*val = buf[0]*256+buf[1];

	return HAL_OK;  /* Success */

}

static HAL_StatusTypeDef HDC1080_write_reg(I2C_HandleTypeDef *hi2c, uint8_t reg, uint16_t val)
{
	uint8_t buf[3];
	HAL_StatusTypeDef  error;

		// Check argument
	if ((reg != HDC1080_TEMPERATURE) &  // dummy write to adr 0 ... trigger measurement
		  (reg != HDC1080_CONFIG) )       // config is "writable"
		return HAL_ERROR;

	buf[0] = reg;
	buf[1] = (uint8_t)((val >> 8) & 0xff);  // msb
	buf[2] = (uint8_t)(val & 0xff); 				// lsb
	/* Write the register */
	/* Send the command and data */
	error = HAL_I2C_Master_Transmit(hi2c,HDC1080_ADDR<<1,buf,3,100);
	if (error != HAL_OK)
		return error;
  else
	  return HAL_OK;  /* Success */
}

HAL_StatusTypeDef HDC1080_measure_temperature(I2C_HandleTypeDef *hi2c, double *temperature)
{
	HAL_StatusTypeDef error;
	double tmp = 0.0;
	uint16_t readout = 0x00;

	error = HDC1080_read_reg(hi2c, 150, HDC1080_TEMPERATURE, &readout);
	if (error != HAL_OK) return error;

	tmp = (double)readout;
	tmp = (tmp / 65536.0) * 165.0 - 40.0;
	*temperature = tmp;  // °C

	return HAL_OK;
}

HAL_StatusTypeDef HDC1080_measure_humidity(I2C_HandleTypeDef *hi2c, double *humidity)
{
	HAL_StatusTypeDef error;
	double tmp = 0.0;
	uint16_t readout = 0x00;


	error = HDC1080_read_reg(hi2c, 150, HDC1080_HUMIDITY, &readout);
	if (error != HAL_OK) return error;

	tmp = (double)readout;
	tmp = (tmp / 65536.0) * 100.0;
	if (tmp>100.0) tmp = 100.0;
	if (tmp<0) tmp = 0.0;
	*humidity = tmp;

	return HAL_OK;
}
