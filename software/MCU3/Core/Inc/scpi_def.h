/*
 * scpi_def.h
 *
 *  Created on: May 28, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_DEF_H_
#define INC_SCPI_DEF_H_

#include <scpi/scpi.h>

#define SCPI_INPUT_BUFFER_LENGTH 128
#define SCPI_ERROR_QUEUE_SIZE 24
#define SCPI_IDN1 "GB"
#define SCPI_IDN2 "STM32F413RGTX"
#define SCPI_IDN3 "0.01"
#define SCPI_IDN4 "01"

extern const scpi_command_t scpi_commands[];
extern scpi_interface_t scpi_interface;
extern char scpi_input_buffer[];
extern scpi_error_t scpi_error_queue_data[];
extern scpi_t scpi_context;

size_t SCPI_Write(scpi_t * context, const char * data, size_t len);
int SCPI_Error(scpi_t * context, int_fast16_t err);
scpi_result_t SCPI_Reset(scpi_t * context);

scpi_result_t SCPI_SystemCommTcpipControlQ(scpi_t * context);

#endif /* INC_SCPI_DEF_H_ */
