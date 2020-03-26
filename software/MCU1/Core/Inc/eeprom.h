/*
 * eeprom.h
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32f7xx_hal.h"

#define EEPROM_ADDRESS 0xA0
#define EEPROM_SIZE 0x3FF
#define EEPROM_WRITE_STATE 0x44

#define EEPROM_B0 0x02
#define EEPROM_B1 0x04
#define EEPROM_BLOCK_COUNT 4
#define EEPROM_BLOCK_SIZE 256


HAL_StatusTypeDef EEPROM_Reset(void);
HAL_StatusTypeDef EEPROM_WriteDefaultValues(void);

void EEPROM_write_reg(uint16_t reg_addr, uint8_t value);
uint8_t  EEPROM_read_reg(uint16_t addr);
#endif /* INC_EEPROM_H_ */
