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

#include <scpi_def.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scpi/scpi.h"
#include "board.h"
#include "main.h"

#include "scpi_commands_calibration.h"
#include "scpi_commands_measure.h"
#include "scpi_commands_misc.h"
#include "scpi_commands_sense.h"
#include "scpi_commands_source.h"
#include "scpi_commands_system.h"
#include "scpi_commands_trigger.h"
#include "scpi_commands_calculate.h"

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
	scpi_bool_t  enable = FALSE;
	if (!SCPI_ParamBool(context, &enable, TRUE))
	{
		return SCPI_RES_ERR;
	}

	BRD_StatusTypeDef status;
	uint8_t tx_data[]="*IDN?\n\r";
	uint8_t tx_dummy[64] ={[0 ... 63] = '\0'};
	uint8_t rx_data[64] ={[0 ... 63] = '\0'};

	if(!enable)
	{
		SPI4_SendDataToMCU2("*IDN?",1000);

	}
	else
	{
		SPI4_ReadDataFromMCU2(&rx_data, 1000);
		SCPI_ResultCharacters(context, rx_data, 64);
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

	{.pattern = "SYSTem:COMMunicate:LAN:DHCP", .callback = SCPI_SystemCommunicateLANDHCP,}, // {ON|OFF|1|0} Enabled DHCP
	{.pattern = "SYSTem:COMMunicate:LAN:DHCP?", .callback = SCPI_SystemCommunicateLANDHCPQ,}, // Get DHCP status
	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress", .callback = SCPI_SystemCommunicateLANIPAddress,}, // "<IP address>" static IP address
	{.pattern = "SYSTem:COMMunicate:LAN:IPADdress?", .callback = SCPI_SystemCommunicateLANIPAddressQ,}, // Static IP address readout
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk", .callback = SCPI_SystemCommunicateLANIPSmask,}, // "<mask>" Subnet mask
	{.pattern = "SYSTem:COMMunicate:LAN:SMASk?", .callback = SCPI_SystemCommunicateLANIPSmaskQ,}, // Read subnet mask
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway", .callback = SCPI_SystemCommunicateLANGateway,}, // "<address>" default gateway
	{.pattern = "SYSTem:COMMunicate:LAN:GATEway?", .callback = SCPI_SystemCommunicateLANGatewayQ,}, // Read default gateway
	{.pattern = "SYSTem:COMMunicate:LAN:MAC", .callback = SCPI_SystemCommunicateLANMAC,}, // "<MAC address>"
	{.pattern = "SYSTem:COMMunicate:LAN:MAC?", .callback = SCPI_SystemCommunicateLANMACQ,}, // Read MAC device
	{.pattern = "SYSTem:COMMunicate:LAN:PORT", .callback = SCPI_SystemCommunicateLANPort,},
	{.pattern = "SYSTem:COMMunicate:LAN:PORT?", .callback = SCPI_SystemCommunicateLANPortQ,},
	{.pattern = "SYSTem:COMMunication:LAN:UPDate", .callback = SCPI_SystemCommunicationLanUpdate,},
	{.pattern = "SYSTem:SERVice:EEPROM", .callback = SCPI_SystemServiceEEPROM,}, // {RESET|DEFault}
	{.pattern = "SYSTem:SERVice:ID", .callback = SCPI_SystemServiceID,}, // manufacturer model SW serial
	{.pattern = "SYSTem:SECure:STATe", .callback = SCPI_SystemSecureState,}, // {OFF|ON|0|1} <code>
	{.pattern = "SYSTem:SECure:STATe?", .callback = SCPI_SystemSecureStateQ,},
	{.pattern = "SYSTem:TEMPerature?", .callback = SCPI_SystemTemperatureQ,}, // Read the temperature of the PCB, default readout is in celsius
	{.pattern = "SYSTem:TEMPerature:UNIT", .callback = SCPI_SystemTemperatureUnit,}, // {C|F|K}
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

	{.pattern = "FETCh?", .callback = SCPI_FetchQ,},

	{.pattern = "INITiate[:IMMediate]", .callback = SCPI_InitiateImmediate,},
	{.pattern = "INITiate:CONTinuous", .callback = SCPI_InitiateContinuous,},
	{.pattern = "INITiate:CONTinuous?", .callback = SCPI_InitiateContinuousQ,},

	{.pattern = "[SENSe:]AVERage:COUNt", .callback = SCPI_SenseAverageCount,}, // <numeric value> MIN 1 MAX 256, set the averaging rate
	{.pattern = "[SENSe:]AVERage:COUNt?", .callback = SCPI_SenseAverageCountQ,}, // Read the averaging rate
	{.pattern = "[SENSe:]AVERage[:STATe]", .callback = SCPI_SenseAverageState,}, // {ON|OFF|1|0}, enable averaging
	{.pattern = "[SENSe:]AVERage[:STATe]?", .callback = SCPI_SenseAverageStateQ,}, // Read averaging state, return 1 or 0
	{.pattern = "[SENSe:]CORRection:CKIT:STANdard", .callback = SCPI_SenseCorrectionCkitStandard,}, //{STAN3}{<numeric_value>,<numeric_value>}, Enters the reference value for the LOAD correction.
	{.pattern = "[SENSe:]CORRection:CKIT:STANdard?", .callback = SCPI_SenseCorrectionCkitStandardQ,}, //{STAN3}
	{.pattern = "[SENSe:]CORRection:COLLect[:ACQuire]", .callback = SCPI_SenseCorrectionCollectAquire,}, //{STAN1|STAN2|STAN3}
	{.pattern = "[SENSe:]CORRection:COLLect:METHod", .callback = SCPI_SenseCorrectionCollectMethod,}, //{REFL2|REFL3}, Sets the measurement error correction method.
	{.pattern = "[SENSe:]CORRection:COLLect:METHod?", .callback = SCPI_SenseCorrectionCollectMethodQ,},
	{.pattern = "[SENSe:]CORRection:DATA?", .callback = SCPI_SenseCorrectionDataQ,}, //{STAN1|STAN2|STAN3}
	{.pattern = "[SENSe:]CORRection:STATe", .callback = SCPI_SenseCorrectionState,}, //{ON|OFF|1|0}, Set the measurement error correction.
	{.pattern = "[SENSe:]CORRection:STATe?", .callback = SCPI_SenseCorrectionStateQ,}, // Queries the measurement error correction status.
	{.pattern = "[SENSe:]FIMPedance:APERture", .callback = SCPI_SenseFimpedanceAperture,}, // <numeric_value> {[MS|S]}
	{.pattern = "[SENSe:]FIMPedance:APERture?", .callback = SCPI_SenseFimpedanceApertureQ,}, // <numeric_value> {[MS|S]}
	{.pattern = "[SENSe:]FIMPedance:CONTact:VERify", .callback = SCPI_SenseFimpedanceContactVerify,}, //{ON|OFF|1|0}
	{.pattern = "[SENSe:]FIMPedance:CONTact:VERify?", .callback = SCPI_SenseFimpedanceContactVerifyQ,},
	{.pattern = "[SENSe:]FIMPedance:RANGe:AUTO", .callback = SCPI_SenseFimpedanceRangeAuto,}, //{ON|OFF|1|0}
	{.pattern = "[SENSe:]FIMPedance:RANGe:AUTO?", .callback = SCPI_SenseFimpedanceRangeAutoQ,},
	{.pattern = "[SENSe:]FIMPedance:RANGe", .callback = SCPI_SenseFimpedanceRange,}, // {<numeric_value> (valid: 10, 100, 1000, 10000, 100000)}{[OHM|KOHM]}
	{.pattern = "[SENSe:]FIMPedance:RANGe?", .callback = SCPI_SenseFimpedanceRangeQ,},
	{.pattern = "[SENSe:]FUNCtion[:ON]", .callback = SCPI_SenseFunctionOn,}, // {FIMPedance|FADMittance}
	{.pattern = "[SENSe:]FUNCtion[:ON]?", .callback = SCPI_SenseFunctionOnQ,},

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
