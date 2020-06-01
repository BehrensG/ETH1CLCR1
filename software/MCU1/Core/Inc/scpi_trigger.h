/*
 * scpi_commands_trigger.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_TRIGGER_H_
#define INC_SCPI_TRIGGER_H_

#include <scpi/scpi.h>

#define SLOPE_POS 1
#define SLOPE_NEG 2

enum e_trigger_source
{
	TRIG_IMM = 1,
	TRIG_EXT,
	TRIG_BUS,
	TRIG_OUT
};

scpi_result_t SCPI_TriggerDelay(scpi_t* context);
scpi_result_t SCPI_TriggerDelayQ(scpi_t* context);
scpi_result_t SCPI_TriggerImmediate(scpi_t* context);
scpi_result_t SCPI_TriggerSource(scpi_t* context);
scpi_result_t SCPI_TriggerSourceQ(scpi_t* context);
scpi_result_t SCPI_TriggerOutput(scpi_t* context);
scpi_result_t SCPI_TriggerOutputSlope(scpi_t* context);
scpi_result_t SCPI_TriggerOutputSlopeQ(scpi_t* context);
scpi_result_t SCPI_TRG(scpi_t* context);

#endif /* INC_SCPI_TRIGGER_H_ */
