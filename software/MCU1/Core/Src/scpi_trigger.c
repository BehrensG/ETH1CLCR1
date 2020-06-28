/*
 * scpi_commands_trigger.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */



#include <stdio.h>

#include "main.h"
#include "board.h"
#include "spi4.h"
#include "scpi_trigger.h"

extern scpi_choice_def_t boolean_select[];

 scpi_choice_def_t trigger_source_select[] =
 {
 		{"IMMediate", 1},
 		{"EXTernal", 2},
 		{"BUS", 3},
		{"OUTput", 4},
 		SCPI_CHOICE_LIST_END
 };

 scpi_choice_def_t trigger_slope_select[] =
 {
		 {"POSitive", 1},
		 {"NEGative", 2},
		 SCPI_CHOICE_LIST_END
 };

 /*
  * TRIGger:DELay <numeric_value> [MS|S]
  *
  * @INFO:
  * Sets the trigger delay time.
  *
  * @PARAMETERS:
  * 				<numeric_value> :
  *									numeric from 0 to 1000 (s)
  *									MINimum 0 (s)
  *									MAXimum 1000 (s)
  *
  * @NOTE:
  * Min. resolution is 1ms.
  */

scpi_result_t SCPI_TriggerDelay(scpi_t* context)
{
	scpi_number_t paramDELAY;

	if(!SCPI_ParamNumber(context, scpi_special_numbers_def, &paramDELAY, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(paramDELAY.special)
	{
		switch(paramDELAY.content.tag)
		{
		case SCPI_NUM_MIN: board.structure.trigger.delay = 0; break;
		case SCPI_NUM_MAX: board.structure.trigger.delay = 1000; break;
		default: SCPI_ErrorPush(context, SCPI_ERROR_ILLEGAL_PARAMETER_VALUE); return SCPI_RES_ERR;
		}
	}
	else
	{
		if(SCPI_UNIT_NONE == paramDELAY.unit || SCPI_UNIT_UNITLESS == paramDELAY.unit)
		{
			if(paramDELAY.content.value < 0 || paramDELAY.content.value > 1000)
			{
				SCPI_ErrorPush(context, SCPI_ERROR_DATA_OUT_OF_RANGE);
				return SCPI_RES_ERR;
			}
			else
			{
				board.structure.trigger.delay = paramDELAY.content.value;
				return SCPI_RES_OK;
			}
		}
		else if (SCPI_UNIT_SECOND == paramDELAY.unit)
		{
			board.structure.trigger.delay = paramDELAY.content.value;
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
 * TRIGger:DELay?
 *
 * @INFO:
 * Query the trigger delay time. Response is a numeric value.
 *
 */

scpi_result_t SCPI_TriggerDelayQ(scpi_t* context)
{
	SCPI_ResultDouble(context, board.structure.trigger.delay);
	return SCPI_RES_OK;
}

/*
 * TRIGger[:IMMediate]
 *
 * @INFO:
 * Causes the trigger to execute a measurement, regardless of the trigger state.
 *
 */

scpi_result_t SCPI_TriggerImmediate(scpi_t* context)
{
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};

	if(TRIG_OUT != board.structure.trigger.source)
	{
			snprintf(tx_data, SPI4_BUFFER, "IMM");
			SPI4_Transmit(&tx_data,1000);
	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_TRIGGER_IGNORED);
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

/*
 * TRIGger:SOURce {BUS|EXTernal|INTernal|OUTput}
 *
 * @INFO:
 * Sets the trigger mode.
 *
 * @PARAMETERS:
 * 				BUS :		BUS trigger mode
 * 				EXTernal :	external trigger mode
 * 				INTernal :	internal trigger mode
 * 				OUTput :	the board outputs a trigger pulse
 *
 */

scpi_result_t SCPI_TriggerSource(scpi_t* context)
{
	int32_t paramTRIG;

	if(!SCPI_ParamChoice(context, trigger_source_select, &paramTRIG, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.structure.trigger.source = paramTRIG;

	if(TRIG_OUT == paramTRIG)
	{
		HAL_GPIO_WritePin(TRIG_EN_GPIO_Port, TRIG_EN_Pin, 1);
	}
	else
	{
		HAL_GPIO_WritePin(TRIG_EN_GPIO_Port, TRIG_EN_Pin, 0);
	}

	return SCPI_RES_OK;
}

/*
 * TRIGger:SOURce?
 *
 * @INFO:
 * Query the trigger mode. Response is BUS, EXT, IMM or OUT.
 *
 */

scpi_result_t SCPI_TriggerSourceQ(scpi_t* context)
{

	switch(board.structure.trigger.source)
	{
		case TRIG_BUS: SCPI_ResultCharacters(context, "BUS", 3); break;
		case TRIG_EXT: SCPI_ResultCharacters(context, "EXT", 3); break;
		case TRIG_IMM: SCPI_ResultCharacters(context, "IMM", 3); break;
		case TRIG_OUT: SCPI_ResultCharacters(context, "OUT", 3); break;
	}
	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut
 *
 * @INFO:
 * Output a TTL-compatible square pulse with the specified edge (TRIG:OUTP:SLOP command) is to output. The trigger pulse time is 5ms.
 *
 *
 */

scpi_result_t SCPI_TriggerOutput(scpi_t* context)
{

	if(TRIG_OUT != board.structure.trigger.source)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_TRIGGER_IGNORED);
		return SCPI_RES_ERR;
	}

	HAL_GPIO_TogglePin(TRIG_OUT_GPIO_Port, TRIG_OUT_Pin);
	osDelay(5);
	HAL_GPIO_TogglePin(TRIG_OUT_GPIO_Port, TRIG_OUT_Pin);

	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut:SLOPe {POSitive|NEGative}
 *
 * @INFO:
 * Select a rising or falling edge for the “trigger out” signal.
 *
 * @PARAMETERS:
 * 				POSitive :	rising edge
 * 				NEGative :	falling edge
 *
 */

scpi_result_t SCPI_TriggerOutputSlope(scpi_t* context)
{
	int32_t paramSLOPE;

	if(!SCPI_ParamChoice(context, trigger_slope_select, &paramSLOPE, TRUE))
	{
		return SCPI_RES_ERR;
	}

	switch(paramSLOPE)
	{
		case SLOPE_POS: HAL_GPIO_WritePin(TRIG_OUT_GPIO_Port, TRIG_OUT_Pin, 0); break;
		case SLOPE_NEG: HAL_GPIO_WritePin(TRIG_OUT_GPIO_Port, TRIG_OUT_Pin, 1); break;
	}

	board.structure.trigger.slope = paramSLOPE;

	return SCPI_RES_OK;
}

/*
 * TRIGger:OUTPut:SLOPe?
 *
 * @INFO:
 * Query trigger output slope edge. Returns POS or NEG.
 *
 */

scpi_result_t SCPI_TriggerOutputSlopeQ(scpi_t* context)
{

	switch(board.structure.trigger.slope)
	{
		case SLOPE_POS: SCPI_ResultCharacters(context, "POS", 3); break;
		case SLOPE_NEG: SCPI_ResultCharacters(context, "NEG", 3); break;
	}

	return SCPI_RES_OK;
}

/*
 * *TRG
 *
 * @INFO:
 * This command triggers the device if the trigger source is set to Bus.
 *
 */

scpi_result_t SCPI_TRG(scpi_t* context)
{
	int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};

	if(TRIG_BUS != board.structure.trigger.source)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_TRIGGER_IGNORED);
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "IMM");
	SPI4_Transmit(&tx_data,1000);
}
