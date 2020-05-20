/*
 * scpi_commands_sense.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#include "scpi_commands_sense.h"

 scpi_choice_def_t sense_function_select[] =
 {
 		{"FIMPedance", 1},
 		{"FADMittance", 2},
 		SCPI_CHOICE_LIST_END
 };

#include "scpi_commands_sense.h"


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
 * [SENSe:]CORRection:CKIT:STANdard {STAN3} <numeric_value> <numeric_value>
 *
 * @INFO:
 * Enters or queries the reference value for the LOAD correction. The reference value must be in
 * R-X (resistance-reactance) parameter form; the first <numeric value> represents R, and the
 * second <numeric value> represents X.
 *
 * @PARAMETERS:
 * 				STAN3 :				LOAD correction
 * 				<numeric_value> :	represents R
 * 				<numeric_value> :	represents X
 *
 */

scpi_result_t SCPI_SenseCorrectionCkitStandard(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:CKIT:STANdard? {STAN3}
 *
 * @INFO:
 * Query response is two numeric value.
 *
 * @PARAMETERS:
 * 				STAN3 :				LOAD correction
 *
 */

scpi_result_t SCPI_SenseCorrectionCkitStandardQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:COLLect[:ACQuire] {STAN1|STAN2|STAN3}
 *
 * @INFO:
 * Performs the OPEN, SHORT, or LOAD correction.
 *
 * @PARAMETERS:
 * 				STAN1 :				OPEN correction
 * 				STAN2 :				SHORT correction
 * 				STAN3 :				LOAD correction
 *
 */

scpi_result_t SCPI_SenseCorrectionCollectAquire(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]CORRection:COLLect:METHod] {REFL2|REFL3}
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
 * [SENSe:]CORRection:COLLect:METHod]? {REFL2|REFL3}
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
 * [SENSe:]CORRection:DATA? {STAN1|STAN2|STAN3}
 *
 * @INFO:
 * Returns the correction data. Query response is two numeric values.
 *
 * @PARAMETERS:
 * 				STAN1 :				OPEN correction
 * 				STAN2 :				SHORT correction
 * 				STAN3 :				LOAD correction
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
 * [SENSe:]FIMPedance:APERture <numeric_value> [MS|S]
 *
 * @INFO:
 * Sets measurement time mode.
 *
 * @PARAMETERS:
 * 				<numeric_value> : TBD
 *
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
 * [SENSe:]FIMPedance:RANGe:AUTO {ON|OFF|1|0}
 *
 * @INFO:
 * Enable or disable the auto range measurement mode.
 *
 * @PARAMETERS:
 * 				OFF or 0 :	disables auto range measurement mode
 * 				ON or 1 :	enables auto range measurement mode
 */

scpi_result_t SCPI_SenseFimpedanceRangeAutoQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * [SENSe:]FIMPedance:RANGe <numeric_value> [OHM|KOHM]
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

	return SCPI_RES_OK;
}


/*
 * [SENSe:]FUNCtion[:ON] {FIMPedance|FADMittance}
 *
 * @INFO:
 * Sets the specified measurement function ON.
 *
 * @PARAMETERS:
 * 				FIMPedance :	TBD
 * 				FADMittance :	TBD
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
