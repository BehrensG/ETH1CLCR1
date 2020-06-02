/*
 * scpi_source.c
 *
 *  Created on: 02.06.2020
 *      Author: BehrensG
 */

#include "AD9835.h"
#include "AD5453.h"


scpi_result_t SCPI_SourceFrequencyCW(scpi_t * context)
{
	uint32_t paramFREQ;
	if(!SCPI_ParamUInt32(context, &paramFREQ, TRUE))
	{
		return SCPI_RES_ERR;
	}

	AD9835_FrequencyRegister(AD9835_FREQ0, paramFREQ);
	AD9835_FrequencyRegisterSelect(AD9835_FREQ0);
	AD9835_Output(AD9835_ON);

	return SCPI_RES_OK;
}

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


// Not used for PCB V1.2
scpi_result_t SCPI_SourceVoltageLevelImmediateOffset(scpi_t * context)
{

	return SCPI_RES_OK;
}


// Not used for PCB V1.2
scpi_result_t SCPI_SourceVoltageLevelImmediateState(scpi_t * context)
{

	return SCPI_RES_OK;
}

