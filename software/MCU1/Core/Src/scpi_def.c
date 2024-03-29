/*-
 * Copyright (c) 2012-2013 Jan Breuer,
 *
 * All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   scpi-def.c
 * @date   Thu Nov 15 10:58:45 UTC 2012
 *
 * @brief  SCPI parser test
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scpi_calculate.h"
#include "scpi_calibration.h"
#include "scpi_def.h"
#include "scpi_measure.h"
#include "scpi_misc.h"
#include "scpi_sense.h"
#include "scpi_source.h"
#include "scpi_system.h"
#include "scpi_trigger.h"
#include "scpi/scpi.h"
#include "board.h"
#include "main.h"
#include "spi4.h"
#include "eeprom.h"

extern I2C_HandleTypeDef hi2c4;
extern SPI_HandleTypeDef hspi4;


scpi_choice_def_t boolean_select[] =
{
    {"OFF", 0},
    {"ON", 1},
	{"0", 0},
	{"1", 1},
    SCPI_CHOICE_LIST_END
};



static scpi_result_t TEST_TSQ(scpi_t * context)
{
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	BRD_StatusTypeDef status;
	int32_t readout_size = 0;
	uint32_t param;

	if(!SCPI_ParamUInt32(context, &param, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "TS? %d", param);
	status = SPI4_Transmit(&tx_data,1000);

	if(HAL_GPIO_ReadPin(MCU2_RX_STATUS_GPIO_Port, MCU2_RX_STATUS_Pin))
	{
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);

	}
	else
	{
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
	}


	return SCPI_RES_OK;
}


/**
 * @brief
 * parses lists
 * channel numbers > 0.
 * no checks yet.
 * valid: (@1), (@3!1:1!3), ...
 * (@1!1:3!2) would be 1!1, 1!2, 2!1, 2!2, 3!1, 3!2.
 * (@3!1:1!3) would be 3!1, 3!2, 3!3, 2!1, 2!2, 2!3, ... 1!3.
 *
 * @param channel_list channel list, compare to SCPI99 Vol 1 Ch. 8.3.2
 */

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

    {.pattern = "STATus:QUEStionable[:EVENt]?", .callback = SCPI_StatusQuestionableEventQ,},
    /* {.pattern = "STATus:QUEStionable:CONDition?", .callback = scpi_stub_callback,}, */
    {.pattern = "STATus:QUEStionable:ENABle", .callback = SCPI_StatusQuestionableEnable,},
    {.pattern = "STATus:QUEStionable:ENABle?", .callback = SCPI_StatusQuestionableEnableQ,},

    {.pattern = "STATus:PRESet", .callback = SCPI_StatusPreset,},

    /* Required SCPI commands (SCPI std V1999.0 4.2.1) */
    {.pattern = "SYSTem:ERRor[:NEXT]?", .callback = SCPI_SystemErrorNextQ,},
    {.pattern = "SYSTem:ERRor:COUNt?", .callback = SCPI_SystemErrorCountQ,},
    {.pattern = "SYSTem:VERSion?", .callback = SCPI_SystemVersionQ,},

	{.pattern = "SYSTem:COMMunicate:LAN:DHCP", .callback = SCPI_SystemCommunicateLANDHCP,},
	{.pattern = "SYSTem:COMMunicate:LAN:DHCP?", .callback = SCPI_SystemCommunicateLANDHCPQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress", .callback = SCPI_SystemCommunicateLANIPAddress,},
	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress?", .callback = SCPI_SystemCommunicateLANIPAddressQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk", .callback = SCPI_SystemCommunicateLANIPSmask,},
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk?", .callback = SCPI_SystemCommunicateLANIPSmaskQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway", .callback = SCPI_SystemCommunicateLANGateway,},
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway?", .callback = SCPI_SystemCommunicateLANGatewayQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:MAC", .callback = SCPI_SystemCommunicateLANMAC,},
	{.pattern = "SYSTem:COMMunicate:LAN:MAC?", .callback = SCPI_SystemCommunicateLANMACQ,},
	{.pattern = "SYSTem:COMMunicate:LAN:PORT", .callback = SCPI_SystemCommunicateLANPort,},
	{.pattern = "SYSTem:COMMunicate:LAN:PORT?", .callback = SCPI_SystemCommunicateLANPortQ,},
	{.pattern = "SYSTem:COMMunication:LAN:UPDate", .callback = SCPI_SystemCommunicationLanUpdate,},
	{.pattern = "SYSTem:SERVice:EEPROM", .callback = SCPI_SystemServiceEEPROM,},
	{.pattern = "SYSTem:SERVice:ID", .callback = SCPI_SystemServiceID,},
	{.pattern = "SYSTem:SECure:STATe", .callback = SCPI_SystemSecureState,},
	{.pattern = "SYSTem:SECure:STATe?", .callback = SCPI_SystemSecureStateQ,},
	{.pattern = "SYSTem:TEMPerature?", .callback = SCPI_SystemTemperatureQ,},
	{.pattern = "SYSTem:TEMPerature:UNIT", .callback = SCPI_SystemTemperatureUnit,},
	{.pattern = "SYSTem:TEMPerature:UNIT?", .callback = SCPI_SystemTemperatureUnitQ,},
	{.pattern = "SYSTem:HUMIdity?", .callback = SCPI_SystemHumidityQ,},

	{.pattern = "CALibration:ADC?", .callback = SCPI_CalibrationADCQ,}, // Calibrate ADC
	{.pattern = "CALibration[:ALL]?", .callback = SCPI_CalibrationAllQ,},
	{.pattern = "CALibration:SECure:STATe", .callback = SCPI_CalibrationSecureState,}, // {OFF|ON|0|1} <code>
	{.pattern = "CALibration:SECure:STATe?", .callback = SCPI_CalibrationSecureStateQ,},
	{.pattern = "CALibration:STORe", .callback = SCPI_CalibrationStore,},
	{.pattern = "CALibration:STRing", .callback = SCPI_CalibrationString,},
	{.pattern = "CALibration:STRing?", .callback = SCPI_CalibrationStringQ,}, // "<string>"
	{.pattern = "CALibration:VALue", .callback = SCPI_CalibrationValue,}, // <value>
	{.pattern = "CALibration:VALue?", .callback = SCPI_CalibrationValueQ,},

	{.pattern = "TS?", .callback = TEST_TSQ,},

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
	{.pattern = "CALCulate:LIMit:STATe", .callback = SCPI_CalculateLimitState,},
	{.pattern = "CALCulate:LIMit:STATe?", .callback = SCPI_CalculateLimitStateQ,},
	{.pattern = "CALCulate:LIMit:UPPer[:DATA]", .callback = SCPI_CalculateLimitUpperData,},
	{.pattern = "CALCulate:LIMit:UPPer[:DATA]?", .callback = SCPI_CalculateLimitUpperDataQ,},
	{.pattern = "CALCulate:LIMit:UPPer:STATe", .callback = SCPI_CalculateLimitUpperState,},
	{.pattern = "CALCulate:LIMit:UPPer:STATe?", .callback = SCPI_CalculateLimitUpperStateQ,},
	{.pattern = "CALCulate:MATH:EXPRession:CATalog?", .callback = SCPI_CalculateMathExpressionCatalogQ,},
	{.pattern = "CALCulate:MATH:EXPRession:NAME", .callback = SCPI_CalculateMathExpressionName,},
	{.pattern = "CALCulate:MATH:EXPRession:NAME?", .callback = SCPI_CalculateMathExpressionNameQ,},
	{.pattern = "CALCulate:MATH:STATe", .callback = SCPI_CalculateMathState,},
	{.pattern = "CALCulate:MATH:STATe?", .callback = SCPI_CalculateMathStateQ,},

	{.pattern = "TRIGger:DELay", .callback = SCPI_TriggerDelay,},
	{.pattern = "TRIGger:DELay?", .callback = SCPI_TriggerDelayQ,},
	{.pattern = "TRIGger[:IMMediate]", .callback = SCPI_TriggerImmediate,},
	{.pattern = "TRIGger:SOURce", .callback = SCPI_TriggerSource,},
	{.pattern = "TRIGger:SOURce?", .callback = SCPI_TriggerSourceQ,},
	{.pattern = "TRIGger:OUTPut", .callback = SCPI_TriggerOutput,},
	{.pattern = "TRIGger:OUTPut:SLOPe", .callback = SCPI_TriggerOutputSlope,},
	{.pattern = "TRIGger:OUTPut:SLOPe?", .callback = SCPI_TriggerOutputSlopeQ,},
	{.pattern = "*TRG", .callback = SCPI_TRG,},

	SCPI_CMD_LIST_END
};

scpi_interface_t scpi_interface = {
    .error = SCPI_Error,
    .write = SCPI_Write,
    .control = SCPI_Control,
    .flush = SCPI_Flush,
    .reset = SCPI_Reset,
};

char scpi_input_buffer[SCPI_INPUT_BUFFER_LENGTH];
scpi_error_t scpi_error_queue_data[SCPI_ERROR_QUEUE_SIZE];

scpi_t scpi_context;
