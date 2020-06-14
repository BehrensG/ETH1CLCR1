/*
 * scpi_commands_source.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#include "scpi_source.h"
#include "board.h"
#include "spi4.h"

extern scpi_choice_def_t boolean_select[];

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
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};
	double paramFREQ;
	BRD_StatusTypeDef status;


	if(!SCPI_ParamDouble(context, &paramFREQ, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.source.frequency = paramFREQ;


	snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ %f\r\n", (int32_t)paramFREQ);
	//SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);

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
	SCPI_ResultDouble(context, board.scpi.source.frequency);
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
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};
	double paramAMPL;

	if(!SCPI_ParamDouble(context, &paramAMPL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.source.amplitude = paramAMPL;

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT %f\r\n", paramAMPL);
	SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);

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
	SCPI_ResultDouble(context, board.scpi.source.amplitude);
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
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};
	double paramOFFS;

	if(!SCPI_ParamDouble(context, &paramOFFS, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(board.scpi.source.offset.state)
	{
		board.scpi.source.offset.value = paramOFFS;

		snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS %f\r\n", paramOFFS);
		SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);
	}

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
	SCPI_ResultDouble(context, board.scpi.source.offset.value);
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
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};
	scpi_bool_t paramBOOL;

	if(!SCPI_ParamBool(context, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.source.offset.state = paramBOOL;

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:STAT %d\r\n", paramBOOL);
	SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);

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
	SCPI_ResultBool(context, board.scpi.source.offset.state);

	return SCPI_RES_OK;
}

/*
 * SOURce:OUTput[:ON]{ON|OFF|1|0}
 *
 * @INFO:
 * Enable/disable stimulus output relay.
 *
 * @PARAMETERS:
 * 				OFF or 0 :		Disable stimulus output relay
 * 				ON or 1	:		Enable stimulus output relay
 *
 */

scpi_result_t SCPI_SourceOutputOn(scpi_t * context)
{
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};
	scpi_bool_t paramBOOL;

	if(!SCPI_ParamBool(context, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.source.output = paramBOOL;

	snprintf(tx_data, SPI4_BUFFER, "SOUR:OUT %d\r\n", paramBOOL);
	SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);

	return SCPI_RES_OK;
}

/*
 * SOURce:OUTput[:ON]?
 *
 * @INFO:
 * Query stimulus output relay status. Returns 0 or 1.
 *
 */


scpi_result_t SCPI_SourceOutputOnQ(scpi_t * context)
{
	SCPI_ResultBool(context, board.scpi.source.output);
	return SCPI_RES_OK;
}
