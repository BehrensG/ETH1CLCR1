/*
 * scpi_commands_trigger.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scpi_commands_trigger.h"


 scpi_choice_def_t trigger_source_select[] =
 {
 		{"IMMediate", 1},
 		{"EXTernal", 2},
 		{"BUS", 3},
		{"MANual", 4},
 		SCPI_CHOICE_LIST_END
 };


 /*
  * TRIGger:DELay <numeric_value> [MS|S]
  *
  * @INFO:
  * Sets the trigger delay time.
  *
  * @PARAMETERS:
  * 				<numeric_value> :
  *									numeric from 0 to 1000 (s)
  *									MINimum 0 (s)
  *									MAXimum 1000 (s)
  *
  */

scpi_result_t SCPI_TriggerDelay(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:DELay?
 *
 * @INFO:
 * Query the trigger delay time. Response is a numeric value.
 *
 */

scpi_result_t SCPI_TriggerDelayQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger[:IMMediate]
 *
 * @INFO:
 * Causes the trigger to execute a measurement, regardless of the trigger state.
 *
 */

scpi_result_t SCPI_TriggerImmediate(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:SOURce {BUS|EXTernal|INTernal}
 *
 * @INFO:
 * Sets the trigger mode.
 *
 * @PARAMETERS:
 * 				BUS :		BUS trigger mode
 * 				EXTernal :	external trigger mode
 * 				INTernal :	internal trigger mode
 *
 */

scpi_result_t SCPI_TriggerSource(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:SOURce?
 *
 * @INFO:
 * Query the trigger mode. Response is BUS, EXT or INT.
 *
 */

scpi_result_t SCPI_TriggerSourceQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut {OFF|ON|0|1}
 *
 * @INFO:
 * Disable or enable the “trigger out” signal. When enabled, a TTL-compatible square waveform with the specified edge (TRIG:OUTP:SLOP command) is outputted.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables trigger output.
 * 				ON or 1 :	enables trigger output.
 *
 */

scpi_result_t SCPI_TriggerOutput(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut:SLOPe {POSitive|NEGative}
 *
 * @INFO:
 * Select a rising or falling edge for the “trigger out” signal.
 *
 * @PARAMETERS:
 * 				POSitive :	rising edge
 * 				NEGative :	falling edge
 *
 */

scpi_result_t SCPI_TriggerOutputSlope(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut:SLOPe {POSitive|NEGative}
 *
 * @INFO:
 * Query trigger output slope edge. Returns POS or NEG.
 *
 */

scpi_result_t SCPI_TriggerOutputSlopeQ(scpi_t * context)
{

	return SCPI_RES_OK;
}
