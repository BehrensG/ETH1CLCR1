/*
 * scpi_commands_trigger.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_TRIGGER_H_
#define INC_SCPI_COMMANDS_TRIGGER_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_TriggerDelay(scpi_t * context);
scpi_result_t SCPI_TriggerDelayQ(scpi_t * context);
scpi_result_t SCPI_TriggerImmediate(scpi_t * context);
scpi_result_t SCPI_TriggerSource(scpi_t * context);
scpi_result_t SCPI_TriggerSourceQ(scpi_t * context);
scpi_result_t SCPI_TriggerOutput(scpi_t * context);
scpi_result_t SCPI_TriggerOutputQ(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_TRIGGER_H_ */
