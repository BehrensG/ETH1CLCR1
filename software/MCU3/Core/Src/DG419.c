/*
 * DG419.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 */

#include "DG419.h"

void DG419_Switch(uint8_t state)
{
	HAL_GPIO_WritePin(ANALOG_SWITCH_GPIO_Port, ANALOG_SWITCH_Pin, state);
}
