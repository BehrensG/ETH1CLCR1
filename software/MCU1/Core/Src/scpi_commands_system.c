/*
 * scpi_commands_system.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scpi/scpi.h"
#include "scpi-def.h"
#include "hdc1080.h"
#include "board.h"
#include "eeprom.h"
#include "scpi_commands_system.h"


scpi_choice_def_t LAN_state_select[] =
{
    {"CURRent", 0},
    {"STATic", 1},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t temperature_unit[] =
{
    {"C", 1},
    {"F", 2},
    {"K", 3},
    SCPI_CHOICE_LIST_END
};

static uint8_t SCPI_StringToIP4Array(const int8_t* ip_string, uint8_t* ip_array)
{

    /* A pointer to the next digit to process. */
    const int8_t* start;

    start = ip_string;
    for (uint8_t i = 0; i < 4; i++)
    {
        /* The digit being processed. */
        uint8_t c;
        /* The value of this byte. */
        uint16_t n = 0;
        while (1)
        {
            c = * start;
            start++;
            if (c >= '0' && c <= '9')
            {
                n *= 10;
                n += c - '0';
            }
            /* We insist on stopping at "." if we are still parsing
               the first, second, or third numbers. If we have reached
               the end of the numbers, we will allow any character. */
            else if ((i < 3 && c == '.') || i == 3)
            {
                break;
            }
            else
            {
                return NET_STR_WRONG_FORMAT;
            }
        }
        if (n >= 256)
        {
            return NET_STR_WRONG_NUMBER;
        }
        ip_array[i] = n;
    }

    return NET_STR_OK;
}

static uint8_t SCPI_StringToMACArray(const uint8_t* MAC_string, uint8_t* MAC_array)
{
    int32_t values[6];

    if(6 == sscanf(MAC_string, "%x:%x:%x:%x:%x:%x%*c",
    &values[0], &values[1], &values[2],
    &values[3], &values[4], &values[5]))
    {
        for (uint8_t i = 0; i < 6; i++)
        MAC_array[i] = (uint8_t)values[i];
    }
    else if (6 == sscanf(MAC_string, "%x-%x-%x-%x-%x-%x%*c",
    &values[0], &values[1], &values[2],
    &values[3], &values[4], &values[5]))
    {
        for (uint8_t i = 0; i < 6; i++)
        MAC_array[i] = (uint8_t)values[i];
    }
    else
    {}

    return NET_STR_OK;
}

scpi_result_t SCPI_SystemCommunicateLANDHCP(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANDHCPQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPAddress(scpi_t * context)
{
	uint8_t str[16] = {0};
	uint8_t numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,(char*)str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.system.ip4_current.ip[0] = numb[0];
		board.system.ip4_current.ip[1] = numb[1];
		board.system.ip4_current.ip[2] = numb[2];
		board.system.ip4_current.ip[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPAddressQ(scpi_t * context)
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_current.ip[0],board.system.ip4_current.ip[1], board.system.ip4_current.ip[2], board.system.ip4_current.ip[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_static.ip[0],board.system.ip4_static.ip[1], board.system.ip4_static.ip[2], board.system.ip4_static.ip[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPSmask(scpi_t * context)
{
	uint8_t str[16] = {0};
	uint8_t numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,(char*)str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.system.ip4_current.netmask[0] = numb[0];
		board.system.ip4_current.netmask[1] = numb[1];
		board.system.ip4_current.netmask[2] = numb[2];
		board.system.ip4_current.netmask[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPSmaskQ(scpi_t * context)
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_current.netmask[0], board.system.ip4_current.netmask[1],
									board.system.ip4_current.netmask[2], board.system.ip4_current.netmask[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_static.netmask[0], board.system.ip4_static.netmask[1],
									board.system.ip4_static.netmask[2], board.system.ip4_static.netmask[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANGateway(scpi_t * context)
{
	uint8_t gateway_str[16] = {0};
	uint8_t gateway_numb[4] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(!SCPI_ParamCopyText(context,gateway_str, 16, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToIP4Array(gateway_str, gateway_numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.system.ip4_current.gateway[0] = gateway_numb[0];
		board.system.ip4_current.gateway[1] = gateway_numb[1];
		board.system.ip4_current.gateway[2] = gateway_numb[2];
		board.system.ip4_current.gateway[3] = gateway_numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANGatewayQ(scpi_t * context)
{
	int32_t value;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_current.gateway[0], board.system.ip4_current.gateway[1],
									board.system.ip4_current.gateway[2], board.system.ip4_current.gateway[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.system.ip4_static.gateway[0], board.system.ip4_static.gateway[1],
									board.system.ip4_static.gateway[2], board.system.ip4_static.gateway[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANMAC(scpi_t * context)
{

	return SCPI_RES_OK;
}
scpi_result_t SCPI_SystemCommunicateLANMACQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemSecureState(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemSecureStateQ(scpi_t * context)
{
	SCPI_ResultUInt8(context, board.system.security.status);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureQ(scpi_t * context)
{
	double temperature;

	HDC1080_measure_temperature(I2C2, &temperature);

	switch(board.system.temperature.unit)
	{
		case 1:;break;
		case 2: temperature = (temperature*1.8)+32;break;
		case 3: temperature += 273.15;break;
	}

	SCPI_ResultDouble(context, temperature);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnit(scpi_t * context)
{
	int32_t param = 0;

    if(!SCPI_ParamChoice(context, temperature_unit, &param, TRUE))
    {
        return SCPI_RES_ERR;
    }

    board.system.temperature.unit = param;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnitQ(scpi_t * context)
{
	switch(board.system.temperature.unit)
	{
		case 1: SCPI_ResultText(context, "C");break;
		case 2: SCPI_ResultText(context, "F");break;
		case 3: SCPI_ResultText(context, "K");break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemHumidityQ(scpi_t * context)
{
	double humidity = 0.0;

	HDC1080_measure_humidity(I2C2, &humidity);
	SCPI_ResultDouble(context, humidity);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemServiceEEPROM(scpi_t * context)
{

	return SCPI_RES_OK;
}

