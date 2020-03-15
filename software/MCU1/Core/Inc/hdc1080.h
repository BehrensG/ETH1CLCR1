/*
 * hdc1080.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_HDC1080_H_
#define INC_HDC1080_H_

#include "stm32f7xx_hal.h"

#define HDC1080_ADDR 			0x40
#define HDC1080_TEMPERATURE 	0x00
#define HDC1080_HUMIDITY 		0x01
#define HDC1080_CONFIG 			0x02
#define HDC1080_SERIAL_ID1 		0xfb
#define HDC1080_SERIAL_ID2 		0xfc
#define HDC1080_SERIAL_ID3 		0xfd
#define HDC1080_ID_MANU 		0xfe
#define HDC1080_ID_DEV 			0xff

#define HDC1080_RH_RES_14 		0x00
#define HDC1080_RH_RES_11 		0x01
#define HDC1080_RH_RES8 		0x02

#define HDC1080_T_RES_14 		0x00
#define HDC1080_T_RES_11 		0x01


HAL_StatusTypeDef HDC1080_measure_temperature(I2C_HandleTypeDef *hi2c, double *temperature);
HAL_StatusTypeDef HDC1080_measure_humidity(I2C_HandleTypeDef *hi2c, double *humidity);

#endif /* INC_HDC1080_H_ */
