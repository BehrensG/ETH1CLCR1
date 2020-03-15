/*
 * eeprom.h
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32f7xx_hal.h"

#define EEPROM_SIZE 0x3FF

#define EEPROM_WRITE_STATE 0x10

#define SCPI_MANUFACTURER_STRING_LENGTH 65
#define SCPI_DEVICE_STRING_LENGTH 11
#define SCPI_SERIALNUMBER_STRING_LENGTH 65
#define SCPI_SOFTWAREVERSION_STRING_LENGTH 65
#define NET_HOSTNAME 255
#define PASSWORD_LENGTH 11
#define PASSWORD "ETH1CLCR1"

HAL_StatusTypeDef EEPROM_Reset(void);
HAL_StatusTypeDef EEPROM_WriteDefaultValues(void);

#endif /* INC_EEPROM_H_ */
