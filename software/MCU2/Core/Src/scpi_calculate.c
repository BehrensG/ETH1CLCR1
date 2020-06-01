/*
 * scpi_commands_calculate.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#include <scpi_calculate.h>


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

    return SCPI_RES_OK;
}
