/*
 * eeprom.h
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32f7xx_hal.h"

#define EEPROM_ADDRESS 0
#define EEPROM_SIZE 0x3FF
#define EEPROM_WRITE_STATE 0x10


HAL_StatusTypeDef EEPROM_Reset(void);
HAL_StatusTypeDef EEPROM_WriteDefaultValues(void);

#endif /* INC_EEPROM_H_ */
