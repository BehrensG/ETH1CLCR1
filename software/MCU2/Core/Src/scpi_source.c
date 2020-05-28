/*
 * scpi_commands_source.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#include <scpi_source.h>


/*
 * SOURce:FREQuency[:CW] <numeric_value>[HZ|KHZ]
 *
 * @INFO:
 * Sets the test signal frequency.
 *
 * @PARAMETERS:
 * 				<numeric_value> :
 *									numeric from 100 to 100000(= 100k)
 *									MINimum 100 (Hz)
 *									MAXimum 100000 (= 100k)(Hz)
 *
 */

scpi_result_t SCPI_SourceFrequencyCW(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:FREQuency[:CW]?
 *
 * @INFO:
 * Queries the test signal frequency. Response is a numeric value.
 *
 */

scpi_result_t SCPI_SourceFrequencyCWQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate][:AMPLitude] <numeric_value>[MV|V]
 *
 * @INFO:
 * Sets the test signal level.
 *
 * @PARAMETERS:
 * 				<numeric_value> :
 * 									numeric 0-10 (V)
 * 									MINimum 0 (V)
 * 									MAXimum 10 (V)
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateAmplitude(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate][:AMPLitude]?
 *
 * @INFO:
 * Queries the test signal level. Response is a numeric value.
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateAmplitudeQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate]:OFFSet <numeric_value>[MV|V]
 *
 * @INFO:
 * Sets the DC bias voltage.
 *
 * @PARAMETERS:
 * 				<numeric_value> :
 * 									numeric -10 - +10(V)
 * 									MINimum -10
 * 									MAXimum +10 (V)
 *
 * @NOTE:
 * In the current PCB desgin no DC bias voltage output is not possible.
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateOffset(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate]:OFFSet?
 *
 * @INFO:
 * Queries the DC bias voltage. Response is a numeric value.
 *
 * @NOTE:
 * In the current PCB desgin no DC bias voltage output is not possible.
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateOffsetQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate]:STATe {ON|OFF|1|0}
 *
 * @INFO:
 * Sets whether or not DC bias output is enabled.
 *
 * @PARAMETERS:
 * 				OFF or 0 :		Disable DC bias output
 * 				ON or 1	:		Enable DC bias output
 *
 * @NOTE:
 * In the current PCB desgin no DC bias voltage output is not possible.
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateState(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * SOURce:VOLTage[:LEVel][:IMMediate]:STATe?
 *
 * @INFO:
 * Queries whether or not DC bias output is enabled. Response is 0 or 1.
 *
 * @NOTE:
 * In the current PCB desgin no DC bias voltage output is not possible.
 *
 */

scpi_result_t SCPI_SourceVoltageLevelImmediateStateQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

