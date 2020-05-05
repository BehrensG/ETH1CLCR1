/*
 * board.h
 *
 *  Created on: May 1, 2020
 *      Author: grzegorz
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_

#include "main.h"
#include "ADC.h"

struct _board_struct
{
	ad738x_dev AD7380;
}board;


#endif /* INC_BOARD_H_ */
