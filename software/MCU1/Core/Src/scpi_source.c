/*
 * scpi_commands_source.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#include <stdio.h>

#include "scpi_source.h"
#include "spi4.h"

extern scpi_choice_def_t boolean_select[];

 scpi_choice_def_t freq_unit_select[] =
 {
 		{"HZ", 1},
 		{"KHZ", 2},
 		SCPI_CHOICE_LIST_END
 };

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
	scpi_number_t paramFREQ;
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramFREQ, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramFREQ.special)
	{
		switch(paramFREQ.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ:CW %d\r\n", 100); SPI4_Transmit(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ:CW %d\r\n", 100000); SPI4_Transmit(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramFREQ.unit || SCPI_UNIT_UNITLESS == paramFREQ.unit)
		{
			if(paramFREQ.content.value < 100 || paramFREQ.content.value > 100000)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ:CW %d\r\n", paramFREQ.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
		else if (SCPI_UNIT_HERTZ == paramFREQ.unit)
		{
			snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ:CW %d\r\n", paramFREQ.content.value);
			SPI4_Transmit(&tx_data,1000);
			return SCPI_RES_OK;
		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SOUR:FREQ:CW?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	scpi_number_t paramVOLT;
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramVOLT, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramVOLT.special)
	{
		switch(paramVOLT.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT %f\r\n", 0); SPI4_Transmit(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT %f\r\n", 10); SPI4_Transmit(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramVOLT.unit || SCPI_UNIT_UNITLESS == paramVOLT.unit)
		{
			if(paramVOLT.content.value < 0 || paramVOLT.content.value > 10)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT %f\r\n", paramVOLT.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
		else if (SCPI_UNIT_VOLT == paramVOLT.unit)
		{
			snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT %f\r\n", paramVOLT.content.value);
			SPI4_Transmit(&tx_data,1000);
			return SCPI_RES_OK;
		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	scpi_number_t paramOFFS;
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramOFFS, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramOFFS.special)
	{
		switch(paramOFFS.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS %f\r\n", -10); SPI4_Transmit(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS %f\r\n", +10); SPI4_Transmit(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramOFFS.unit || SCPI_UNIT_UNITLESS == paramOFFS.unit)
		{
			if(paramOFFS.content.value < -10 || paramOFFS.content.value > +10)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS %f\r\n", paramOFFS.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
		else if (SCPI_UNIT_VOLT == paramOFFS.unit)
		{
			snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS %f\r\n", paramOFFS.content.value);
			SPI4_Transmit(&tx_data,1000);
			return SCPI_RES_OK;
		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:OFFS?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramSTATE;

	if(!SCPI_ParamChoice(context, boolean_select, &paramSTATE, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:STAT %d\r\n", paramSTATE.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SOUR:VOLT:STAT?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramSTATE;

	if(!SCPI_ParamChoice(context, boolean_select, &paramSTATE, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SOUR:OUT:ON %d\r\n", paramSTATE.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SOUR:OUT:ON?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

	return SCPI_RES_OK;
}
