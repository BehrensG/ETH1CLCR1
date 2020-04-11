/*
 * scpi_commands_system.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#include "scpi/scpi.h"
#include "scpi-def.h"
#include "hdc1080.h"
#include "board.h"
#include "eeprom.h"
#include "scpi_commands_system.h"

extern I2C_HandleTypeDef hi2c2;

scpi_choice_def_t LAN_state_select[] =
{
    {"CURRent", 0},
    {"STATic", 1},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t temperature_unit[] =
{
    {"C", 0},
    {"F", 1},
    {"K", 2},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t security_state_select[] =
{
    {"OFF", 0},
    {"ON", 1},
    SCPI_CHOICE_LIST_END
};

scpi_choice_def_t EEPROM_state_select[] =
{
    {"RESET", 0},
    {"DEFault", 1},
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
	scpi_bool_t  enable = FALSE;
	if (!SCPI_ParamBool(context, &enable, TRUE))
	{
		return SCPI_RES_ERR;
	}

	board.structure.system.dhcp.enable = (uint8_t)enable;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANDHCPQ(scpi_t * context)
{

	SCPI_ResultBool(context, (scpi_bool_t)board.structure.system.dhcp.enable);

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
		board.structure.system.ip4_current.ip[0] = numb[0];
		board.structure.system.ip4_current.ip[1] = numb[1];
		board.structure.system.ip4_current.ip[2] = numb[2];
		board.structure.system.ip4_current.ip[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPAddressQ(scpi_t * context)
{
	int32_t value = 0;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_current.ip[0],board.structure.system.ip4_current.ip[1], board.structure.system.ip4_current.ip[2], board.structure.system.ip4_current.ip[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_static.ip[0],board.structure.system.ip4_static.ip[1], board.structure.system.ip4_static.ip[2], board.structure.system.ip4_static.ip[3]);
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
		board.structure.system.ip4_current.netmask[0] = numb[0];
		board.structure.system.ip4_current.netmask[1] = numb[1];
		board.structure.system.ip4_current.netmask[2] = numb[2];
		board.structure.system.ip4_current.netmask[3] = numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPSmaskQ(scpi_t * context)
{
	int32_t value = 0;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_current.netmask[0], board.structure.system.ip4_current.netmask[1],
									board.structure.system.ip4_current.netmask[2], board.structure.system.ip4_current.netmask[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_static.netmask[0], board.structure.system.ip4_static.netmask[1],
									board.structure.system.ip4_static.netmask[2], board.structure.system.ip4_static.netmask[3]);
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
		board.structure.system.ip4_current.gateway[0] = gateway_numb[0];
		board.structure.system.ip4_current.gateway[1] = gateway_numb[1];
		board.structure.system.ip4_current.gateway[2] = gateway_numb[2];
		board.structure.system.ip4_current.gateway[3] = gateway_numb[3];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANGatewayQ(scpi_t * context)
{
	int32_t value = 0;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}
	if(CURRENT == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_current.gateway[0], board.structure.system.ip4_current.gateway[1],
									board.structure.system.ip4_current.gateway[2], board.structure.system.ip4_current.gateway[3]);
	}
	else if(STATIC == value)
	{
		sprintf(str, "%d.%d.%d.%d", board.structure.system.ip4_static.gateway[0], board.structure.system.ip4_static.gateway[1],
									board.structure.system.ip4_static.gateway[2], board.structure.system.ip4_static.gateway[3]);
	}
	SCPI_ResultMnemonic(context, (char*)str);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANMAC(scpi_t * context)
{
	uint8_t str[18] = {0};
	uint8_t numb[6] = {0};
	size_t len = 0;
	uint8_t conv_result = 0;

	if(board.structure.system.security.status)
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_MODE_SECURE);
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context,(char*)str, 18, &len, TRUE))
	{
		return SCPI_RES_ERR;
	}

	conv_result = SCPI_StringToMACArray(str, numb);

	switch(conv_result)
	{
	case NET_STR_OK:
	{
		board.structure.system.ip4_current.MAC[0] = numb[0];
		board.structure.system.ip4_current.MAC[1] = numb[1];
		board.structure.system.ip4_current.MAC[2] = numb[2];
		board.structure.system.ip4_current.MAC[3] = numb[3];
		board.structure.system.ip4_current.MAC[4] = numb[4];
		board.structure.system.ip4_current.MAC[5] = numb[5];
	}break;
	case NET_STR_WRONG_FORMAT: SCPI_ErrorPush(context, SCPI_ERROR_DATA_TYPE_ERROR); break;
	case NET_STR_WRONG_NUMBER: SCPI_ErrorPush(context, SCPI_ERROR_NUMERIC_DATA_NOT_ALLOWED); break;
	default: return SCPI_RES_ERR; break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANMACQ(scpi_t * context)
{
	uint8_t str[18] = {0};

	if(!board.structure.default_cfg)
	{
		sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", board.structure.system.ip4_current.MAC[0], board.structure.system.ip4_current.MAC[1],
														board.structure.system.ip4_current.MAC[2], board.structure.system.ip4_current.MAC[3],
														board.structure.system.ip4_current.MAC[4], board.structure.system.ip4_current.MAC[5]);
	}
	else
	{
		sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", board.structure.system.ip4_static.MAC[0], board.structure.system.ip4_static.MAC[1],
														board.structure.system.ip4_static.MAC[2], board.structure.system.ip4_static.MAC[3],
														board.structure.system.ip4_static.MAC[4], board.structure.system.ip4_static.MAC[5]);
	}

	SCPI_ResultMnemonic(context, (char*)str);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANPort(scpi_t * context)
{
    uint32_t port = 0;

    if(!SCPI_ParamUInt32(context, &port, TRUE))
    {
        return SCPI_RES_ERR;
    }

    if (port > ETH_PORT_MAX_VAL)
    {
        SCPI_ErrorPush(context, SCPI_ERROR_TOO_MANY_DIGITS);
        return SCPI_RES_OK;
    }

    board.structure.system.ip4_current.port = (uint16_t)port;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANPortQ(scpi_t * context)
{
	int32_t value = 0;
	uint8_t str[16] = {0};

	if(!SCPI_ParamChoice(context, LAN_state_select, &value, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(CURRENT == value)
	{
		SCPI_ResultUInt16(context,board.structure.system.ip4_current.port);
	}
	else if(STATIC == value)
	{
		SCPI_ResultUInt16(context,board.structure.system.ip4_static.port);
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicationLanUpdate(scpi_t * context)
{

	if(board.structure.system.security.status)
	{
		return SCPI_ERROR_SERVICE_MODE_SECURE;
	}

	EEPROM_WriteValues();

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemSecureState(scpi_t * context)
{
	int32_t state = 0;
	int8_t password_read[PASSWORD_LENGTH] = {0};
	size_t length = 0;
	int8_t* password_reference = board.structure.system.security.password;

	if(!SCPI_ParamChoice(context, security_state_select, &state, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!SCPI_ParamCopyText(context, (char*)password_read, PASSWORD_LENGTH, &length, TRUE))
	{
		return SCPI_RES_ERR;
	}

	if(!strcmp((const char*)password_read, (const char*)password_reference))
	{
		board.structure.system.security.status = SECURITY_OFF;
		return SCPI_RES_ERR;
	}
	else
	{
		SCPI_ErrorPush(context, SCPI_ERROR_SERVICE_INVALID_PASSWORD);
		return SCPI_RES_ERR;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemSecureStateQ(scpi_t * context)
{
	SCPI_ResultUInt8(context, board.structure.system.security.status);
	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureQ(scpi_t * context)
{
	double temperature = 0.0;

	HDC1080_measure_temperature(&hi2c2, &temperature);

	switch(board.structure.system.temperature.unit)
	{
		case 0:;break;
		case 1: temperature = (temperature*1.8)+32;break;
		case 2: temperature += 273.15;break;
	}

	SCPI_ResultUInt8(context, (uint8_t)temperature);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnit(scpi_t * context)
{
	int32_t param = 0;

    if(!SCPI_ParamChoice(context, temperature_unit, &param, TRUE))
    {
        return SCPI_RES_ERR;
    }

    board.structure.system.temperature.unit = param;

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnitQ(scpi_t * context)
{
	switch(board.structure.system.temperature.unit)
	{
		case 0: SCPI_ResultText(context, "C");break;
		case 1: SCPI_ResultText(context, "F");break;
		case 2: SCPI_ResultText(context, "K");break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemHumidityQ(scpi_t * context)
{
	double humidity = 0.0;

	HDC1080_measure_humidity(&hi2c2, &humidity);
	SCPI_ResultUInt8(context,(uint8_t)humidity);

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemServiceEEPROM(scpi_t * context)
{
	int32_t param = 0;
	if(!SCPI_ParamChoice(context, EEPROM_state_select, &param, TRUE))
	{
        return SCPI_RES_ERR;
	}

	if(board.structure.system.security.status)
	{
		return SCPI_ERROR_SERVICE_MODE_SECURE;
	}

	switch(param)
	{
		case 0:EEPROM_Reset();break;
		case 1:EEPROM_WriteDefaultValues();break;
	}

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemServiceID(scpi_t * context)
{
	uint8_t buffer[256];
	size_t len;

	if(!SCPI_ParamCopyText(context, buffer, SCPI_MANUFACTURER_STRING_LENGTH, len, TRUE))
	{
		buffer[0]='\0';
		return SCPI_RES_ERR;
	}
	strncpy(board.structure.info.manufacturer,buffer,SCPI_MANUFACTURER_STRING_LENGTH);

	if(!SCPI_ParamCopyText(context, buffer, SCPI_DEVICE_STRING_LENGTH, len, TRUE))
	{
		buffer[0]='\0';
		return SCPI_RES_ERR;
	}
	strncpy(board.structure.info.device,buffer,SCPI_DEVICE_STRING_LENGTH);

	if(!SCPI_ParamCopyText(context, buffer, SCPI_SOFTWAREVERSION_STRING_LENGTH, len, TRUE))
	{
		buffer[0]='\0';
		return SCPI_RES_ERR;
	}
	strncpy(board.structure.info.software_version,buffer,SCPI_SOFTWAREVERSION_STRING_LENGTH);

	if(!SCPI_ParamCopyText(context, buffer, SCPI_SERIALNUMBER_STRING_LENGTH, len, TRUE))
	{
		buffer[0]='\0';
		return SCPI_RES_ERR;
	}
	strncpy(board.structure.info.serial_number,buffer,SCPI_SERIALNUMBER_STRING_LENGTH);


}
