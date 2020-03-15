/*
 * scpi_commands_measure.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_MEASURE_H_
#define INC_SCPI_COMMANDS_MEASURE_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_FetchQ(scpi_t * context);
scpi_result_t SCPI_InitiateImmediate(scpi_t * context);
scpi_result_t SCPI_InitiateContinuous(scpi_t * context);
scpi_result_t SCPI_InitiateContinuousQ(scpi_t * context);


#endif /* INC_SCPI_COMMANDS_MEASURE_H_ */
