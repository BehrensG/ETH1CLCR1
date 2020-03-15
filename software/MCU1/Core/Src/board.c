/*
 * board_init.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#include "board.h"
#include "main.h"
#include "scpi-def.h"
#include "eeprom.h"

void BOARD_CreateDefaultData()
{


}

void BOARD_DetectDefaultConfig()
{
	board.default_cfg = !HAL_GPIO_ReadPin(MCU_DEFAULT_GPIO_Port, MCU_DEFAULT_Pin);
}
