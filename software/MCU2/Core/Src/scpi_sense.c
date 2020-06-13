/*
 * scpi_commands_sense.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#include "scpi_sense.h"
#include "board.h"
#include "relay.h"

 /*
  * [SENSe:]AVERage:COUNt <numeric_value>
  *
  * @INFO:
  * Sets the averaging rate.
  *
  * @PARAMETERS:
  * 				<numeric_value> :
  *									numeric 1 to 256
  *									MINimum 1
  *									MAXimum 256
  *
  */

scpi_result_t SCPI_SenseAverageCount(scpi_t * context)
{
	uint32_t count;

	if(!SCPI_ParamUInt32(context, &count, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.sense.average.count = count;

    return SCPI_RES_OK;
}

/*
 * [SENSe:]AVERage:COUNt? <numeric_value>
 *
 * @INFO:
 * Query the averaging rate. Query response is a numeric value.
 *
 */

scpi_result_t SCPI_SenseAverageCountQ(scpi_t * context)
{

	SCPI_ResultUInt32(context, board.scpi.sense.average.count);

	return SCPI_RES_OK;
}

/*
 * [SENSe:]AVERage[:STATe] {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable averaging.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables averaging
 * 				ON or 1 :	enables averaging
 *
 */

scpi_result_t SCPI_SenseAverageState(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]AVERage[:STATe]?
 *
 * @INFO:
 * Queries if averaging is enabled. Response can be 0 or 1.
 *
 */

scpi_result_t SCPI_SenseAverageStateQ(scpi_t * context)
{

	return SCPI_RES_OK;
}


/*
 * [SENSe:]CORRection:CKIT:STANdard {LOAD} <numeric_value> <numeric_value>
 *
 * @INFO:
 * Enters or queries the reference value for the LOAD correction. The reference value must be in
 * R-X (resistance-reactance) parameter form; the first <numeric value> represents R, and the
 * second <numeric value> represents X.
 *
 * @PARAMETERS:
 * 				LOAD :				LOAD correction
 * 				<numeric_value> :	represents R
 * 				<numeric_value> :	represents X
 *
 */

scpi_result_t SCPI_SenseCorrectionCkitStandard(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:CKIT:STANdard? {LOAD}
 *
 * @INFO:
 * Query response is two numeric value.
 *
 * @PARAMETERS:
 * 				LOAD :				LOAD correction
 *
 */

scpi_result_t SCPI_SenseCorrectionCkitStandardQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:COLLect[:ACQuire] {OPEN|SHORT|LOAD}
 *
 * @INFO:
 * Performs the OPEN, SHORT, or LOAD correction.
 *
 * @PARAMETERS:
 * 				OPEN :				OPEN correction
 * 				SHORT :				SHORT correction
 * 				LOAD :				LOAD correction
 *
 */

scpi_result_t SCPI_SenseCorrectionCollectAquire(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:COLLect:METHod {REFL2|REFL3}
 *
 * @INFO:
 * Sets the measurement error correction method
 *
 * @PARAMETERS:
 * 				REFL2 :				OPEN/SHORT
 * 				REFL3 :				OPEN/SHORT/LOAD
 *
 */

scpi_result_t SCPI_SenseCorrectionCollectMethod(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:COLLect:METHod? {REFL2|REFL3}
 *
 * @INFO:
 * Query the measurement error correction method. Respons with REFL2 or REFL3.
 *
 */

scpi_result_t SCPI_SenseCorrectionCollectMethodQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:DATA?
 *
 * @INFO:
 * Returns the correction data. Query response is two numeric values.
 *
 */

scpi_result_t SCPI_SenseCorrectionDataQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:STATe {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable the measurement error correction function.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables correction function
 * 				ON or 1 :	enables correction function
 *
 */

scpi_result_t SCPI_SenseCorrectionState(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:STATe?
 *
 * @INFO:
 * Query the measurement error correction function status. Returns 0 or 1.
 *
 */

scpi_result_t SCPI_SenseCorrectionStateQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:APERture <numeric_value>[MS|S]
 *
 * @INFO:
 * Sets measurement time mode.
 *
 * @PARAMETERS:
 * 				<numeric_value> : 	TBD
 *				MINimum :			TBD
 * 				MAXimum :			TBD
 */

scpi_result_t SCPI_SenseFimpedanceAperture(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:APERture?
 *
 * @INFO:
 * Queries measurement time mode. Result is a numeric value.
 *
 */

scpi_result_t SCPI_SenseFimpedanceApertureQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:CONTact:VERify {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable the contact check function.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables contact check function
 * 				ON or 1 :	enables contact check function
 *
 */

scpi_result_t SCPI_SenseFimpedanceContactVerify(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:CONTact:VERify?
 *
 * @INFO:
 * Queries if the contact check function is enabled. Response is 0 or 1.
 *
 */

scpi_result_t SCPI_SenseFimpedanceContactVerifyQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:RANGe:AUTO {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable the auto range measurement mode.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables auto range measurement mode
 * 				ON or 1 :	enables auto range measurement mode
 */

scpi_result_t SCPI_SenseFimpedanceRangeAuto(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:RANGe:AUTO?
 *
 * @INFO:
 * Query range measurement mode. Result cant be 0 or 1.
 *
 */

scpi_result_t SCPI_SenseFimpedanceRangeAutoQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:RANGe <numeric_value>[OHM|KOHM]
 *
 * @INFO:
 * Set the measurement range.
 *
 * @PARAMETERS:
 * 				<numeric_value> :	valid values 10, 100, 1000 (=1k), 10000 (=10k), 100000 (=100k)
 *
 */

scpi_result_t SCPI_SenseFimpedanceRange(scpi_t * context)
{
	int32_t paramRANG;

	if(!SCPI_ParamInt32(context, &paramRANG, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.sense.fimp.range = paramRANG;

	RELAY_9012_Control(SR_10CTR | SR_100CTR | SR_1KCTR | SR_10KCTR, RELAY_OFF);
	RELAY_AQY212_Control(RR_10CTR | RR_100CTR | RR_1KCTR | RR_10KCTR | RR_100KCTR, RELAY_OFF);
	RELAY_TQ2SA_Control(RELAY_OFF);

	switch(paramRANG)
	{
		case 10: 		RELAY_AQY212_Control(RR_10CTR, RELAY_ON);
						RELAY_9012_Control(SR_10CTR, RELAY_ON);
						RELAY_TQ2SA_Control(RELAY_ON); break;

		case 100: 		RELAY_AQY212_Control(RR_100CTR, RELAY_ON);
						RELAY_9012_Control(SR_100CTR, RELAY_ON);
						RELAY_TQ2SA_Control(RELAY_ON); break;

		case 1000:  	RELAY_AQY212_Control(RR_1KCTR, RELAY_ON);
						RELAY_9012_Control(SR_1KCTR, RELAY_ON);
						RELAY_TQ2SA_Control(RELAY_ON); break;

		case 10000: 	RELAY_AQY212_Control(RR_10KCTR, RELAY_ON);
						RELAY_9012_Control(SR_10KCTR, RELAY_ON);
						RELAY_TQ2SA_Control(RELAY_ON); break;

		case 100000:	RELAY_AQY212_Control(RR_100KCTR, RELAY_ON); RELAY_TQ2SA_Control(RELAY_ON); break;
	}

	return SCPI_RES_OK;

}

/*
 * [SENSe:]FIMPedance:RANGe?
 *
 * @INFO:
 * Query the measurement range. Response is a numeric value.
 *
 */

scpi_result_t SCPI_SenseFimpedanceRangeQ(scpi_t * context)
{
	SCPI_ResultInt32(context, board.scpi.sense.fimp.range);
	return SCPI_RES_OK;
}


/*
 * [SENSe:]FUNCtion[:ON] {FIMPedance|FADMittance}
 *
 * @INFO:
 * Sets the specified measurement function ON.
 *
 * @PARAMETERS:
 * 				FIMPedance :	Impedance measurement (series circuit)
 * 				FADMittance :	Admittance measurement (parallel circuit)
 *
 */

scpi_result_t SCPI_SenseFunctionOn(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FUNCtion[:ON]?
 *
 * @INFO:
 * Query sensor function. Responds with FIMP or FADM.
 *
 */

scpi_result_t SCPI_SenseFunctionOnQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]OUTput[:ON] {ON|OFF|1|0}
 *
 * @INFO:
 * Enable/disable device output relay.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	Disables output relay
 * 				ON or 1 :	Enables output relay
 *
 */

scpi_result_t SCPI_SenseOutputOn(scpi_t * context)
{
	scpi_bool_t paramBOOL;

	if(!SCPI_ParamBool(context, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.sense.output = paramBOOL;
	RELAY_HE3621_Control(CXN_REL1 | CXN_REL2 | CXN_REL5 | CXN_REL6, paramBOOL);

	return SCPI_RES_OK;
}

/*
 * [SENSe:]OUTput[:ON]?
 *
 * @INFO:
 * Query device output relay status. Returns 0 or 1.
 *
 */

scpi_result_t SCPI_SenseOutputOnQ(scpi_t * context)
{
	SCPI_ResultBool(context, board.scpi.sense.output);
	return SCPI_RES_OK;
}

/*
 * [SENSe:]GUARD[:ON] {ON|OFF|1|0}
 *
 * @INFO:
 * Enable/disable device guard relay.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	Disables guard relay
 * 				ON or 1 :	Enables guard relay
 *
 */

scpi_result_t SCPI_SenseGuardOn(scpi_t * context)
{
	scpi_bool_t paramBOOL;

	if(!SCPI_ParamBool(context, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.scpi.sense.guard = paramBOOL;
	RELAY_HE3621_Control(CXN_REL3 | CXN_REL4, paramBOOL);

	return SCPI_RES_OK;
}

/*
 * [SENSe:]GUARD[:ON]?
 *
 * @INFO:
 * Query device guard relay. Returns 0 or 1.
 *
 */

scpi_result_t SCPI_SenseGuardOnQ(scpi_t * context)
{
	SCPI_ResultBool(context, board.scpi.sense.guard);
	return SCPI_RES_OK;
}
