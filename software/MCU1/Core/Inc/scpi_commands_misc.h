/*
 * scpi_commands_misc.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_MISC_H_
#define INC_SCPI_COMMANDS_MISC_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_FormatData(scpi_t * context);
scpi_result_t SCPI_FormatDataQ(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_MISC_H_ */
