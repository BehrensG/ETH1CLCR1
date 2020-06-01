/*
 * scpi_commands_sense.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#include <scpi_sense.h>
#include <spi4.h>

extern scpi_choice_def_t boolean_select[];

 scpi_choice_def_t sense_function_select[] =
 {
 		{"FIMPedance", 1},
 		{"FADMittance", 2},
 		SCPI_CHOICE_LIST_END
 };

 scpi_choice_def_t sense_standard_select[] =
 {
 		{"OPEN", 1},
 		{"SHORT", 2},
 		{"LOAD", 3},
 		SCPI_CHOICE_LIST_END
 };

 scpi_choice_def_t sense_refl_select[] =
 {
 		{"REFL1", 1},
 		{"REFL2", 2},
 		SCPI_CHOICE_LIST_END
 };

 static uint8_t valid_resistor(int32_t resis_val, int32_t resis_array[], uint8_t size)
 {
	 uint8_t status = 0;
	 for(uint8_t x = 0; x < size; x++)
	 {
		 if(resis_val == resis_array[x])
		 {
			 return 1;
		 }
	 }
	 return 0;
 }

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
	scpi_number_t paramAVER;
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramAVER, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramAVER.special)
	{
		switch(paramAVER.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:COUN %d\r\n", 1); SPI4_Transmit(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:COUN %d\r\n", 256); SPI4_Transmit(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramAVER.unit || SCPI_UNIT_UNITLESS == paramAVER.unit)
		{
			if(paramAVER.content.value < 1 || paramAVER.content.value > 256)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:COUN %d\r\n", paramAVER.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
	}

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:COUNt?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramBOOL;

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:STAT %d\r\n", paramBOOL.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:AVER:STAT?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	scpi_choice_def_t paramSTAN;
	int32_t paramR;
	int32_t paramX;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamChoice(context, sense_standard_select, &paramSTAN, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(DUT_LOAD != paramSTAN.tag)
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamInt32(context, &paramR, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamInt32(context, &paramX, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:CKIT:STAN %d %f %f\r\n", paramSTAN.tag, paramR, paramX);
	SPI4_Transmit(&tx_data,1000);

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
	scpi_choice_def_t paramSTAN;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamChoice(context, sense_standard_select, &paramSTAN, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(DUT_LOAD != paramSTAN.tag)
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:CKIT:STANd? %d\r\n", paramSTAN.tag);
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	scpi_choice_def_t paramSTAN;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamChoice(context, sense_standard_select, &paramSTAN, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:COLL:ACQ %d\r\n", paramSTAN.tag);
	SPI4_Transmit(&tx_data,1000);

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
	scpi_choice_def_t paramREFL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamChoice(context, sense_refl_select, &paramREFL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:COLL:METH %d\r\n", paramREFL.tag);
	SPI4_Transmit(&tx_data,1000);

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
	scpi_choice_def_t paramREFL;
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	if(!SCPI_ParamChoice(context, sense_refl_select, &paramREFL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:COLL:METH? %d\r\n", paramREFL.tag);
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:DATA?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramBOOL;

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:STAT %d\r\n", paramBOOL.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:CORR:STAT?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:APER?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramBOOL;

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:CONT:VER %d\r\n", paramBOOL.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:CONT:VER?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramBOOL;

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG:AUTO %d\r\n", paramBOOL.tag);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG:AUTO?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	scpi_number_t paramRANG;
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER-1] = '\0'};
	int32_t valid_resistance[] = {10, 100, 1000, 10000, 100000};

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramRANG, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramRANG.special)
	{
		switch(paramRANG.content.tag)
		{
		case SCPI_NUM_MIN: snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG %d\r\n", 10); SPI4_Transmit(&tx_data,1000); break;
		case SCPI_NUM_MAX: snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG %d\r\n", 100000); SPI4_Transmit(&tx_data,1000); break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramRANG.unit || SCPI_UNIT_UNITLESS == paramRANG.unit)
		{
			if(!valid_resistor(paramRANG.content.value, valid_resistance, 5))
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG %d\r\n", paramRANG.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}
		}
		else if (SCPI_UNIT_OHM == paramRANG.unit)
		{
			if(!valid_resistor(paramRANG.content.value, valid_resistance, 5))
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG %d\r\n", paramRANG.content.value);
				SPI4_Transmit(&tx_data,1000);
				return SCPI_RES_OK;
			}

		}
		else
		{
			SCPI_ErrorPush(context, SCPI_ERROR_INVALID_SUFFIX);
			return SCPI_RES_ERR;
		}
	}

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:FIMP:RANG?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	scpi_choice_def_t paramBOOL;

	if(!SCPI_ParamChoice(context, boolean_select, &paramBOOL, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "SENS:FUNC:ON %d\r\n", paramBOOL.tag);
	SPI4_Transmit(&tx_data,1000);
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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "SENS:FUNC:ON?\r\n");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, 1000);
	SCPI_ResultCharacters(context, rx_data, SPI4_BUFFER);

	return SCPI_RES_OK;
}
