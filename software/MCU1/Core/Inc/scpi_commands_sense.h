/*
 * scpi_commands_sense.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_SENSE_H_
#define INC_SCPI_COMMANDS_SENSE_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_SenseAverageCount(scpi_t * context);
scpi_result_t SCPI_SenseAverageCountQ(scpi_t * context);
scpi_result_t SCPI_SenseAverageState(scpi_t * context);
scpi_result_t SCPI_SenseAverageStateQ(scpi_t * context);
scpi_result_t SCPI_SenseFunction(scpi_t * context);
scpi_result_t SCPI_SenseFunctionQ(scpi_t * context);
scpi_result_t SCPI_SenseMode(scpi_t * context);
scpi_result_t SCPI_SenseNominalValue(scpi_t * context);
scpi_result_t SCPI_SenseNominalValueQ(scpi_t * context);
scpi_result_t SCPI_SenseNominalState(scpi_t * context);
scpi_result_t SCPI_SenseNominalStateQ(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_SENSE_H_ */
