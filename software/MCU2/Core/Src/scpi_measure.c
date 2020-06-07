/*
 * scpi_command_measure.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#include "scpi_measure.h"

/*
 * FETCh?
 *
 * @INFO:
 * Retrieves the measurements taken by the INITiate subsystem commands and places them into the device output buffer.
 * Query response is: <stat>,<data1>,<data2>,<comp1>,<comp2>
 *
 * @RESULTS:
 *
 *			<stat> :	measurement status: 0 (Normal), 1 (Overload), 2 (No-Contact)
 *			<data1> :	measurement data of the primary parameter
 *			<data2> :	measurement data of the secondary parameter
 *			<comp1> : 	comparison result of the primary parameter (no output when comparator is OFF) : 1 (In), 2 (High), 3 (Low), 8 (No-Contact)
 *			<comp2> : 	comparison result of the primary parameter (no output when comparator is OFF) : 1 (In), 2 (High), 3 (Low), 8 (No-Contact)
 *
 * @NOTE:
 * Data format is specifed by FORMat subsystem.
 *
 */

scpi_result_t SCPI_FetchQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * INITiate[:IMMediate]
 *
 * @INFO:
 * This command causes the trigger system to initiate and complete one full trigger cycle, returning to Idle state on completion.
 *
 * @NOTE:
 * Data format is specifed by FORMat subsystem.
 *
 */

scpi_result_t SCPI_InitiateImmediate(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * INITiate:CONTinuous {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable whether the trigger system is continuously initiated or not.
 *
 * @PARAMETERS:
 * 				OFF or 0 :		does not initiate the trigger system continuously
 * 				ON or 1	:		initiates the trigger system continuously
 *
 * @NOTE:
 * In the current PCB desgin no DC bias voltage output is not possible.
 *
 */

scpi_result_t SCPI_InitiateContinuous(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * INITiate:CONTinuous?
 *
 * @INFO:
 * Queries whether the trigger system is continuously initiated or not. Result can be 0 or 1.
 *
 */

scpi_result_t SCPI_InitiateContinuousQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

