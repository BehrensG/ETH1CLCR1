/*
 * scpi_commands_source.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_SOURCE_H_
#define INC_SCPI_COMMANDS_SOURCE_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_FrequencyCW(scpi_t * context);
scpi_result_t SCPI_FrequencyCWQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageAmplitude(scpi_t * context);
scpi_result_t SCPI_SourceVoltageAmplitudeQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageOffset(scpi_t * context);
scpi_result_t SCPI_SourceVoltageOffsetQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageOffsetState(scpi_t * context);
scpi_result_t SCPI_SourceVoltageOffsetStateQ(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_SOURCE_H_ */
