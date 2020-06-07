/*
 * scpi_source.c
 *
 *  Created on: Jun 6, 2020
 *      Author: grzegorz
 */

#include <scpi_source.h>
#include "AD9835.h"
#include "DG419.h"
#include "AD5453.h"

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
	double paramFREQ;

	if(!SCPI_ParamDouble(context, &paramFREQ, TRUE))
	{
		return SCPI_RES_ERR;
	}

	AD9835_FrequencyRegister(AD9835_FREQ0, paramFREQ);
	AD9835_FrequencyRegisterSelect(AD9835_FREQ0);
	AD9835_Output(AD9835_ON);

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
	double paramAMPL;

	if(!SCPI_ParamDouble(context, &paramAMPL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	AD5453_SetVoltage(paramAMPL);
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
	//TBD
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
	//TBD
	return SCPI_RES_OK;
}


/*
 * SOURce:OUTput[:ON] {ON|OFF|1|0}
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
	scpi_bool_t paramBOOL;

	if(!SCPI_ParamBool(context, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	DG419_Switch(paramBOOL);
	return SCPI_RES_OK;
}
