/*
 * eeprom.h
 *
 *  Created on: Jun 9, 2020
 *      Author: BehrensG
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32f7xx_hal.h"
#include "board.h"

#define EEPROM_ADDRESS 0xA0U
#define EEPROM_SIZE 0x3FFU
#define EEPROM_WRITE_STATE 0x44U

#define EEPROM_B0 0x02U
#define EEPROM_B1 0x04U
#define EEPROM_BLOCK_COUNT 4U
#define EEPROM_BLOCK_SIZE 256U

BRD_StatusTypeDef EEPROM_Reset(void);

#endif /* INC_EEPROM_H_ */
