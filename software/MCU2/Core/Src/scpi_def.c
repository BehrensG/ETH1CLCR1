/*
 * scpi_def.c
 *
 *  Created on: May 9, 2020
 *      Author: grzegorz
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "main.h"
#include "scpi_def.h"

#include "scpi_calculate.h"
#include "scpi_calibration.h"
#include "scpi_measure.h"
#include "scpi_misc.h"
#include "scpi_sense.h"
#include "scpi_source.h"
#include "spi4.h"
#include "DAC8568.h"

extern uint32_t SPI6_TransmitSize;
extern __IO uint8_t SPI6_TxBuffer[];

scpi_choice_def_t boolean_select[] =
{
    {"OFF", 0},
    {"ON", 1},
	{"0", 0},
	{"1", 1},
    SCPI_CHOICE_LIST_END
};

size_t SCPI_Write(scpi_t * context, const char * data, size_t len) {
    (void) context;

    strncpy(SPI6_TxBuffer + SPI6_TransmitSize,data, len);
    SPI6_TransmitSize += (strlen(data));

    return SPI6_TransmitSize;
}


scpi_result_t SCPI_Reset(scpi_t * context) {

	(void) context;
    int8_t tx_data[SPI4_BUFFER] = {[0 ... SPI4_BUFFER - 1] = '\0'};

	snprintf(tx_data, SPI4_BUFFER, "*RST\r\n");
	SPI4_Transmit(tx_data, SPI4_BUFFER, 1000);
	HAL_Delay(10);
	NVIC_SystemReset();

    return SCPI_RES_OK;
}

static scpi_result_t TEST_TSQ(scpi_t * context)
{
	DAC8568_SetVoltage(DAC_CH_A | DAC_WR_UPD_SINGLE, 1.0);

	return SCPI_RES_OK;
}


/**
 * Reimplement IEEE488.2 *TST?
 *
 * Result should be 0 if everything is ok
 * Result should be 1 if something goes wrong
 *
 * Return SCPI_RES_OK
 */
static scpi_result_t My_CoreTstQ(scpi_t * context) {

    SCPI_ResultInt32(context, 0);

    return SCPI_RES_OK;
}

const scpi_command_t scpi_commands[] = {
    /* IEEE Mandated Commands (SCPI std V1999.0 4.1.1) */
    { .pattern = "*CLS", .callback = SCPI_CoreCls,},
    { .pattern = "*ESE", .callback = SCPI_CoreEse,},
    { .pattern = "*ESE?", .callback = SCPI_CoreEseQ,},
    { .pattern = "*ESR?", .callback = SCPI_CoreEsrQ,},
    { .pattern = "*IDN?", .callback = SCPI_CoreIdnQ,},
    { .pattern = "*OPC", .callback = SCPI_CoreOpc,},
    { .pattern = "*OPC?", .callback = SCPI_CoreOpcQ,},
    { .pattern = "*RST", .callback = SCPI_CoreRst,},
    { .pattern = "*SRE", .callback = SCPI_CoreSre,},
    { .pattern = "*SRE?", .callback = SCPI_CoreSreQ,},
    { .pattern = "*STB?", .callback = SCPI_CoreStbQ,},
    { .pattern = "*TST?", .callback = My_CoreTstQ,},
    { .pattern = "*WAI", .callback = SCPI_CoreWai,},

    /* Required SCPI commands (SCPI std V1999.0 4.2.1) */
    {.pattern = "SYSTem:ERRor[:NEXT]?", .callback = SCPI_SystemErrorNextQ,},
    {.pattern = "SYSTem:ERRor:COUNt?", .callback = SCPI_SystemErrorCountQ,},
    {.pattern = "SYSTem:VERSion?", .callback = SCPI_SystemVersionQ,},

	{.pattern = "CALibration:ADC?", .callback = SCPI_CalibrationADCQ,},
	{.pattern = "CALibration[:ALL]?", .callback = SCPI_CalibrationAllQ,},
	{.pattern = "CALibration:SECure:STATe", .callback = SCPI_CalibrationSecureState,},
	{.pattern = "CALibration:SECure:STATe?", .callback = SCPI_CalibrationSecureStateQ,},
	{.pattern = "CALibration:STORe", .callback = SCPI_CalibrationStore,},
	{.pattern = "CALibration:STRing", .callback = SCPI_CalibrationString,},
	{.pattern = "CALibration:STRing?", .callback = SCPI_CalibrationStringQ,},
	{.pattern = "CALibration:VALue", .callback = SCPI_CalibrationValue,},
	{.pattern = "CALibration:VALue?", .callback = SCPI_CalibrationValueQ,},

	{.pattern = "FORMAt[:DATA]", .callback = SCPI_FormatData,},
	{.pattern = "FORMAt[:DATA]?", .callback = SCPI_FormatDataQ,},

	{.pattern = "SOURce:FREQuency[:CW]", .callback = SCPI_SourceFrequencyCW,},
	{.pattern = "SOURce:FREQuency[:CW]?", .callback = SCPI_SourceFrequencyCWQ,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate][:AMPLitude]", .callback = SCPI_SourceVoltageLevelImmediateAmplitude,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate][:AMPLitude]?", .callback = SCPI_SourceVoltageLevelImmediateAmplitudeQ,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate]:OFFSet", .callback = SCPI_SourceVoltageLevelImmediateOffset,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate]:OFFSet?", .callback = SCPI_SourceVoltageLevelImmediateOffsetQ,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate]:STATe", .callback = SCPI_SourceVoltageLevelImmediateState,},
	{.pattern = "SOURce:VOLTage[:LEVel][:IMMediate]:STATe?", .callback = SCPI_SourceVoltageLevelImmediateStateQ,},
	{.pattern = "SOURce:OUTput[:ON]", .callback = SCPI_SourceOutputOn,},
	{.pattern = "SOURce:OUTput[:ON]?", .callback = SCPI_SourceOutputOnQ,},

	{.pattern = "FETCh?", .callback = SCPI_FetchQ,},

	{.pattern = "INITiate[:IMMediate]", .callback = SCPI_InitiateImmediate,},
	{.pattern = "INITiate:CONTinuous", .callback = SCPI_InitiateContinuous,},
	{.pattern = "INITiate:CONTinuous?", .callback = SCPI_InitiateContinuousQ,},

	{.pattern = "[SENSe:]AVERage:COUNt", .callback = SCPI_SenseAverageCount,},
	{.pattern = "[SENSe:]AVERage:COUNt?", .callback = SCPI_SenseAverageCountQ,},
	{.pattern = "[SENSe:]AVERage[:STATe]", .callback = SCPI_SenseAverageState,},
	{.pattern = "[SENSe:]AVERage[:STATe]?", .callback = SCPI_SenseAverageStateQ,},
	{.pattern = "[SENSe:]CORRection:CKIT:STANdard", .callback = SCPI_SenseCorrectionCkitStandard,},
	{.pattern = "[SENSe:]CORRection:CKIT:STANdard?", .callback = SCPI_SenseCorrectionCkitStandardQ,},
	{.pattern = "[SENSe:]CORRection:COLLect[:ACQuire]", .callback = SCPI_SenseCorrectionCollectAquire,},
	{.pattern = "[SENSe:]CORRection:COLLect:METHod", .callback = SCPI_SenseCorrectionCollectMethod,},
	{.pattern = "[SENSe:]CORRection:COLLect:METHod?", .callback = SCPI_SenseCorrectionCollectMethodQ,},
	{.pattern = "[SENSe:]CORRection:DATA?", .callback = SCPI_SenseCorrectionDataQ,},
	{.pattern = "[SENSe:]CORRection:STATe", .callback = SCPI_SenseCorrectionState,},
	{.pattern = "[SENSe:]CORRection:STATe?", .callback = SCPI_SenseCorrectionStateQ,},
	{.pattern = "[SENSe:]FIMPedance:APERture", .callback = SCPI_SenseFimpedanceAperture,},
	{.pattern = "[SENSe:]FIMPedance:APERture?", .callback = SCPI_SenseFimpedanceApertureQ,},
	{.pattern = "[SENSe:]FIMPedance:CONTact:VERify", .callback = SCPI_SenseFimpedanceContactVerify,},
	{.pattern = "[SENSe:]FIMPedance:CONTact:VERify?", .callback = SCPI_SenseFimpedanceContactVerifyQ,},
	{.pattern = "[SENSe:]FIMPedance:RANGe:AUTO", .callback = SCPI_SenseFimpedanceRangeAuto,},
	{.pattern = "[SENSe:]FIMPedance:RANGe:AUTO?", .callback = SCPI_SenseFimpedanceRangeAutoQ,},
	{.pattern = "[SENSe:]FIMPedance:RANGe", .callback = SCPI_SenseFimpedanceRange,},
	{.pattern = "[SENSe:]FIMPedance:RANGe?", .callback = SCPI_SenseFimpedanceRangeQ,},
	{.pattern = "[SENSe:]FUNCtion[:ON]", .callback = SCPI_SenseFunctionOn,},
	{.pattern = "[SENSe:]FUNCtion[:ON]?", .callback = SCPI_SenseFunctionOnQ,},
	{.pattern = "[SENSe:]OUTput[:ON]", .callback = SCPI_SenseOutputOn,},
	{.pattern = "[SENSe:]OUTput[:ON]?", .callback = SCPI_SenseOutputOnQ,},
	{.pattern = "[SENSe:]GUARD[:ON]", .callback = SCPI_SenseGuardOn,},
	{.pattern = "[SENSe:]GUARD[:ON]?", .callback = SCPI_SenseGuardOnQ,},

	{.pattern = "CALCulate:FORMat", .callback = SCPI_CalculateFormat,},
	{.pattern = "CALCulate:FORMat?", .callback = SCPI_CalculateFormatQ,},
	{.pattern = "CALCulate:LIMit:CLEar", .callback = SCPI_CalculateLimitClear,},
	{.pattern = "CALCulate:LIMit:FAIL?", .callback = SCPI_CalculateLimitFailQ,},
	{.pattern = "CALCulate:LIMit:LOWer[:DATA]", .callback = SCPI_CalculateLimitLowerData,},
	{.pattern = "CALCulate:LIMit:LOWer[:DATA]?", .callback = SCPI_CalculateLimitLowerDataQ,},
	{.pattern = "CALCulate:LIMit:LOWer:STATe", .callback = SCPI_CalculateLimitLowerState,},
	{.pattern = "CALCulate:LIMit:LOWer:STATe?", .callback = SCPI_CalculateLimitLowerStateQ,},
	{.pattern = "CALCulate:LIMit:UPPer[:DATA]", .callback = SCPI_CalculateLimitUpperData,},
	{.pattern = "CALCulate:LIMit:UPPer[:DATA]?", .callback = SCPI_CalculateLimitUpperDataQ,},
	{.pattern = "CALCulate:LIMit:UPPer:STATe", .callback = SCPI_CalculateLimitUpperState,},
	{.pattern = "CALCulate:LIMit:UPPer:STATe?", .callback = SCPI_CalculateLimitUpperStateQ,},
	{.pattern = "CALCulate:MATH:EXPRession:CATalog?", .callback = SCPI_CalculateMathExpressionCatalogQ,},
	{.pattern = "CALCulate:MATH:EXPRession:NAME", .callback = SCPI_CalculateMathExpressionName,},
	{.pattern = "CALCulate:MATH:EXPRession:NAME?", .callback = SCPI_CalculateMathExpressionNameQ,},
	{.pattern = "CALCulate:MATH:STATe", .callback = SCPI_CalculateMathState,},
	{.pattern = "CALCulate:MATH:STATe?", .callback = SCPI_CalculateMathStateQ,},

	{.pattern = "TS?", .callback = TEST_TSQ,},


	SCPI_CMD_LIST_END
};

scpi_interface_t scpi_interface = {
    .error = NULL,
    .write = SCPI_Write,
    .control = NULL,
    .flush = NULL,
    .reset = SCPI_Reset,
};

char scpi_input_buffer[SCPI_INPUT_BUFFER_LENGTH];
scpi_error_t scpi_error_queue_data[SCPI_ERROR_QUEUE_SIZE];

scpi_t scpi_context;

