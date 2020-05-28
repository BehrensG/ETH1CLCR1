/*
 * scpi_commands_source.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_SOURCE_H_
#define INC_SCPI_SOURCE_H_

#include <scpi/scpi.h>

#define HZ 1
#define KHZ 2

scpi_result_t SCPI_SourceFrequencyCW(scpi_t * context);
scpi_result_t SCPI_SourceFrequencyCWQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateAmplitude(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateAmplitudeQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateOffset(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateOffsetQ(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateState(scpi_t * context);
scpi_result_t SCPI_SourceVoltageLevelImmediateStateQ(scpi_t * context);

#endif /* INC_SCPI_SOURCE_H_ */
