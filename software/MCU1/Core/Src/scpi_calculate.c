/*
 * scpi_commands_calculate.c
 *
 *  Created on: May 16, 2020
 *      Author: grzegorz
 */

#include <scpi_calculate.h>
#include "spi4.h"

extern scpi_choice_def_t boolean_select[];

scpi_choice_def_t calc1_format_select[] =
{
		{"REAL", 1},
		{"MLINear", 2},
		{"CP", 3},
		{"CS", 4},
		{"LP", 5},
		{"LS", 6},
		SCPI_CHOICE_LIST_END
};

scpi_choice_def_t calc2_format_select[] =
{
		{"IMAGinary", 7},
		{"PHASe", 8},
		{"D", 9},
		{"Q", 10},
		{"REAL", 11},
		{"LP", 12},
		{"RP", 13},
		{"INV", 14},
		SCPI_CHOICE_LIST_END
};

scpi_choice_def_t deviation_select[] =
{
		{"DEV", 1},
		{"PCNT", 2},
		SCPI_CHOICE_LIST_END
};

/*
 * CALCulate:FORMat  {1} {REAL|MLINear|CP|CS|LP|LS} or {2} {IMAGinary|PHASe|D|Q|REAL|LP|RP|INV}
 *
 * @INFO:
 * Sets the measurement parameter.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 * 				REAL :		real part of the vector
 * 				IMAGinary :	imaginary part of the vector
 * 				MLINear :	absolute value of the vector
 * 				PHASe :		phase of the impedance
 * 				CP :		equivalent parallel capacitance
 * 				CS :		equivalent series capacitance
 * 				LP :		equivalent parallel inductance
 * 				LS :		equivalent series inductance
 * 				D :			dissipation factor
 * 				RP :		equivalent parallel resistance
 * 				INV	:		1/N (reciprocal of turns ration N)
 *
 *
 * @NOTE:
 * This command works with the [SENSe]:FUNCtion[:ON] subsystem.
 * The SENSe:FUNCtion subsystem has priority over the CALCulate.
 * When setting the SENS:FUNC:ON command, the setting of the CALC:FORM command is restricted. When the settings of these two commands do not match any measurement parameter,
 * the setting of CALC:FORM is automatically changed to a measurement parameter which matches SENS:FUNC:ON.
 * When setting the CALC:FORM command, if the current setting of the SENS:FUNC:ON command does not match any measurement parameter, the CALC:FORM command is rejected, and an error occurs.
 *
 * ------------------------------------------------------------------------------------------
 * |	Measurement Parameter	|	SENS:FUNC:ON	|	CALC:FORM 1		|	CALC:FORM 2		|
 * ------------------------------------------------------------------------------------------
 * |	Z-Phase					|	FIMPedance		|	MLINear			|	PHASe			|
 * |	R-X						|					|	REAL			|	IMAGinary		|
 * ------------------------------------------------------------------------------------------
 * |	Y-Phase					|	FADMittance		|	MLINear			|	PHASe			|
 * |	G-B						|					|	REAL			|	IMAGinary		|
 * ------------------------------------------------------------------------------------------
 * |	Cp-D					|	FADMittance		|	CP				|	D				|
 * |	Cp-Q					|					|					|	Q				|
 * |	Cp-G					|					|					|	REAL			|
 * |	Cp-Rp					|					|					|	RP				|
 * ------------------------------------------------------------------------------------------
 * |	Cs-D					|	FIMPedance		|	CS				|	D				|
 * |	Cs-Q					|					|					|	Q				|
 * |	Cs-Rs					|					|					|	REAL			|
 * ------------------------------------------------------------------------------------------
 * |	Lp-D					|	FADMittance		|	LP				|	D				|
 * |	Lp-Q					|					|					|	Q				|
 * |	Lp-G					|					|					|	REAL			|
 * |	Lp-Rp					|					|					|	RP				|
 * ------------------------------------------------------------------------------------------
 * |	Ls-D					|	FIMPedance		|	LS				|	D				|
 * |	Ls-Q					|					|					|	Q				|
 * |	Ls-Rs					|					|					|	REAL			|
 * ------------------------------------------------------------------------------------------
 */

scpi_result_t SCPI_CalculateFormat(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramCALC1, paramCALC2;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};


	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	if(1 == paramSEL)
	{
		if(!SCPI_ParamChoice(context, calc1_format_select, &paramCALC1, TRUE))
		{
			return SCPI_RES_ERR;
		}

		snprintf(tx_data, SPI4_BUFFER, "CALC:FORM %d %d\r\n", paramSEL, paramCALC1.tag);
		SPI4_SendDataToMCU2(&tx_data,1000);
	}

	if(2 == paramSEL)
	{
		if(!SCPI_ParamChoice(context, calc2_format_select, &paramCALC2, TRUE))
		{
			return SCPI_RES_ERR;
		}

		snprintf(tx_data, SPI4_BUFFER, "CALC:FORM %d %d\r\n", paramSEL, paramCALC2.tag);
		SPI4_SendDataToMCU2(&tx_data,1000);
	}

    return SCPI_RES_OK;
}

/*
 * CALCulate:FORMat? {1|2}
 *
 * @INFO:
 *  Queries the measurement parameter. Return value string: "REAL", "IMAG", MLIN", "PHAS", "CP", "CS", "LP", "LS", "D", "RP", "INV".
 *
 */

scpi_result_t SCPI_CalculateFormatQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:FORM? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:CLEar {1|2}
 *
 * @INFO:
 * Clears the data which is reported by CALCulate:LIMit:FAIL? command.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateLimitClear(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:CLE %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:FAIL? {1|2}
 *
 * @INFO:
 * Returns the comparison result of the selected parameter
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 * @RESULTS:
 * 				0 :			comparison result is PASS.
 *				1 :			comparison result is FAIL.
 */

scpi_result_t SCPI_CalculateLimitFailQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:FAIL? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:LOWer[:DATA] {1|2} <numeric_value>
 *
 * @INFO:
 * Set the lower limit value of the selected parameter.
 *
 * @PARAMETERS:
 * 				1 :					select calculate option 1
 * 				2 :					select calculate option 2
 *				<numeric_value> :
 *									numeric -2147483647 - +2147483647
 *									MINimum -2147483647
 *									MAXimum +2147483647
 *
 */

scpi_result_t SCPI_CalculateLimitLowerData(scpi_t * context)
{
	int32_t paramSEL;
	scpi_number_t paramNUM;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramNUM, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramNUM.special)
	{
		switch(paramNUM.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:DATA %d %d\r\n", paramSEL, INT32_MIN); SPI4_SendDataToMCU2(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:DATA %d %d\r\n", paramSEL, INT32_MAX); SPI4_SendDataToMCU2(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramNUM.unit || SCPI_UNIT_UNITLESS == paramNUM.unit)
		{
			if(paramNUM.content.value < INT32_MIN || paramNUM.content.value > INT32_MAX)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:DATA %d %f\r\n", paramSEL, paramNUM.content.value);
				SPI4_SendDataToMCU2(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
	}

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:LOWer[:DATA]? {1|2}
 *
 * @INFO:
 * Query the lower limit value of the selected parameter. Numeric result.
 *
 * @PARAMETERS:
 * 				1 :					select calculate option 1
 * 				2 :					select calculate option 2

 *
 */

scpi_result_t SCPI_CalculateLimitLowerDataQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:DATA? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:LOWer:STATe {1|2} {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable  the lower limit of the selected parameter.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *				OFF or 0 :	disables the lower limit.
 *				ON or 1 :	enables the lower limit.
 *
 */

scpi_result_t SCPI_CalculateLimitLowerState(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramBOOL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:STAT %d %d\r\n", paramSEL, paramBOOL.tag);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:LOWer:STATe? {1|2}
 *
 * @INFO:
 * Query if the lower limit value of the selected parameter.  Return value can be 0 (disabled) or 1 (enabled).
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateLimitLowerStateQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:LOW:STAT? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:STATe {1|2} {ON|OFF|1|0}
 *
 * @INFO:
 * Set lower limit value of the selected parameter.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *				OFF or 0 :	sets the comparator function OFF
 *				ON or 1 :	sets the comparator function ON
 *
 */

scpi_result_t SCPI_CalculateLimitState(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramBOOL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:STAT %d %d\r\n", paramSEL, paramBOOL.tag);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:STATe? {1|2}
 *
 * @INFO:
 * Query lower limit value of the selected parameter. Return value can be 0 (disabled) or 1 (enabled).
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateLimitStateQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:STAT? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:UPPer[:DATA] {1|2} <numeric_value>
 *
 * @INFO:
 * Set the upper limit value of the selected parameter.
 *
 * @PARAMETERS:
 * 				1 :					select calculate option 1
 * 				2 :					select calculate option 2
 *				<numeric_value> :
 *									numeric -2147483647 - +2147483647
 *									MINimum -2147483647
 *									MAXimum +2147483647
 *
 */

scpi_result_t SCPI_CalculateLimitUpperData(scpi_t * context)
{
	int32_t paramSEL;
	scpi_number_t paramNUM;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramNUM, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramNUM.special)
	{
		switch(paramNUM.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:UPP:DATA %d %d\r\n", paramSEL, INT32_MIN); SPI4_SendDataToMCU2(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:UPP:DATA %d %d\r\n", paramSEL, INT32_MAX); SPI4_SendDataToMCU2(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramNUM.unit || SCPI_UNIT_UNITLESS == paramNUM.unit)
		{
			if(paramNUM.content.value < INT32_MIN || paramNUM.content.value > INT32_MAX)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:UPP:DATA %d %f\r\n", paramSEL, paramNUM.content.value);
				SPI4_SendDataToMCU2(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
	}

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:UPPer[:DATA]? {1|2}
 *
 * @INFO:
 * Query the upper upper value of the selected parameter. Numeric result.
 *
 * @PARAMETERS:
 * 				1 :					select calculate option 1
 * 				2 :					select calculate option 2

 *
 */

scpi_result_t SCPI_CalculateLimitUpperDataQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:UPP:DATA? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:UPPer:STATe {1|2} {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable  the lower limit of the selected parameter.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *				OFF or 0 :	disables the upper limit.
 *				ON or 1 :	enables the upper limit.
 *
 */


scpi_result_t SCPI_CalculateLimitUpperState(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramBOOL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:MATH:STAT %d %d\r\n", paramSEL, paramBOOL.tag);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:LIMit:UPPer:STATe? {1|2}
 *
 * @INFO:
 * Query if the lower upper value of the selected parameter.  Return value can be 0 (disabled) or 1 (enabled).
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateLimitUpperStateQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:LIM:UPP:STAT? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:MATH:EXPRession:CATalog? {1|2}
 *
 * @INFO:
 * Returns available parameters which can be used with the CALCulate:MATH:EXPRession:NAME command. Query response is always DEV,PCNT.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateMathExpressionCatalogQ(scpi_t * context)
{
	const int8_t string[SPI4_BUFFER] ="DEV,PCNT";
	SCPI_ResultCharacters(context, string, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:MATH:EXPRession:NAME {1|2} {DEV|PCNT}
 *
 * @INFO:
 * Defines the expression used for the deviation measurement, which is enabled by CALCulate:MATH:STATe. The reference value is depened using the DATA[:DATA] command.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *				DEV :		absolute value of deviation
 *				PCNT:		percentage of deviation
 */

scpi_result_t SCPI_CalculateMathExpressionName(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramDEVI;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamChoice(context, deviation_select, &paramDEVI, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:MATH:EXPR:NAME %d %d\r\n", paramSEL, paramDEVI.tag);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:MATH:EXPRession:NAME? {1|2}
 *
 * @INFO:
 * Query the expression used for the deviation measurement, which is enabled by CALCulate:MATH:STATe. Query response is DEV or PCNT.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateMathExpressionNameQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:MATH:EXPR:NAME? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}

/*
 * CALCulate:MATH:STATe {1|2} {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable the math processing defined by the CALCulate:MATH:EXPRession:NAME.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *				OFF or 0 :	disables math processing
 *				ON or 1 :	enables math processing
 *
 */

scpi_result_t SCPI_CalculateMathState(scpi_t * context)
{
	int32_t paramSEL;
	scpi_choice_def_t paramBOOL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:MATH:STAT %d %d\r\n", paramSEL, paramBOOL.tag);
	SPI4_SendDataToMCU2(&tx_data,1000);

    return SCPI_RES_OK;
}

/*
 * CALCulate:MATH:STATe? {1|2}
 *
 * @INFO:
 * Queries if math processing defined by the :CALCulate{1|2}:MATH:EXPRession:NAME is enabled or not. Query response is 0 or 1.
 *
 * @PARAMETERS:
 * 				1 :			select calculate option 1
 * 				2 :			select calculate option 2
 *
 */

scpi_result_t SCPI_CalculateMathStateQ(scpi_t * context)
{
	int32_t paramSEL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamInt32(context, &paramSEL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if((1 != paramSEL) || (2 != paramSEL))
	{
		SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "CALC:MATH:STAT? %d\r\n", paramSEL);
	SPI4_SendDataToMCU2(&tx_data,1000);

	SPI4_ReadDataFromMCU2(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

    return SCPI_RES_OK;
}
