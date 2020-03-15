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

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPAddressQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPSmask(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemCommunicateLANIPSmaskQ(scpi_t * context)
{

	return SCPI_RES_OK;
}
scpi_result_t SCPI_SystemCommunicateLANGateway(scpi_t * context)
{

	return SCPI_RES_OK;
}
scpi_result_t SCPI_SystemCommunicateLANGatewayQ(scpi_t * context)
{

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

	return SCPI_RES_OK;
}
scpi_result_t SCPI_SystemTemperatureQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnit(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SystemTemperatureUnitQ(scpi_t * context)
{

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

