/*
 * AD5453.h
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#ifndef INC_AD5453_H_
#define INC_AD5453_H_

#include "main.h"

#define AD5453_LOAD_AND_UPDATE			0x0000U
#define AD5453_GAIN						10U
#define AD5453_VREF						0.3

union tx_union
{
	uint16_t word16;
	uint8_t bytes[2];
}tx_data;

#endif /* INC_AD5453_H_ */
