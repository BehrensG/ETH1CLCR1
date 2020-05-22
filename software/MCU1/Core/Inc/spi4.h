/*
 * spi4.h
 *
 *  Created on: May 20, 2020
 *      Author: grzegorz
 */

#ifndef INC_SPI4_H_
#define INC_SPI4_H_

#include "board.h"

#define MCU2_IDLE	0U
#define MCU2_BUSY	1U

#define SPI4_BUFFER 64

BRD_StatusTypeDef SPI4_SendDataToMCU2(const int8_t* str, uint32_t timeout);
BRD_StatusTypeDef SPI4_ReadDataFromMCU2(int8_t* str, uint32_t timeout);

#endif /* INC_SPI4_H_ */