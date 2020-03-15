/*
 * scpi_commands_system.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_SYSTEM_H_
#define INC_SCPI_COMMANDS_SYSTEM_H_

#include "scpi/scpi.h"

scpi_result_t SCPI_SystemCommunicateLANDHCP(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANDHCPQ(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANIPAddress(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANIPAddressQ(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANIPSmask(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANIPSmaskQ(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANGateway(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANGatewayQ(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANMAC(scpi_t * context);
scpi_result_t SCPI_SystemCommunicateLANMACQ(scpi_t * context);
scpi_result_t SCPI_SystemSecureState(scpi_t * context);
scpi_result_t SCPI_SystemSecureStateQ(scpi_t * context);
scpi_result_t SCPI_SystemTemperatureQ(scpi_t * context);
scpi_result_t SCPI_SystemTemperatureUnit(scpi_t * context);
scpi_result_t  SCPI_SystemTemperatureUnitQ(scpi_t * context);
scpi_result_t SCPI_SystemHumidityQ(scpi_t * context);
scpi_result_t SCPI_SystemServiceEEPROM(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_SYSTEM_H_ */
