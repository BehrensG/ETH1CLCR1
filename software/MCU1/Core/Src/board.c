/*
 * board_init.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#include "main.h"
#include "board_def.h"
#include "scpi-def.h"

void BOARD_CreateDefaultData()
{
	default_board.scpi_info.manufacturer = (int8_t)malloc(SCPI_MANUFACTURER_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.device = (int8_t)malloc(SCPI_DEVICE_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.serial_number = (int8_t)malloc(SCPI_SERIALNUMBER_STRING_LENGTH*sizeof(int8_t));
	default_board.scpi_info.software_version = (int8_t)malloc(SCPI_SOFTWAREVERSION_STRING_LENGTH*sizeof(int8_t));
	default_board.security.password = (int8_t)malloc(PASSWORD_LENGTH*sizeof(int8_t));
	default_board.ip4_current.hostname = (int8_t)malloc(NET_HOSTNAME*sizeof(int8_t));
	default_board.ip4_static.hostname = (int8_t)malloc(NET_HOSTNAME*sizeof(int8_t));

	default_board.scpi_info.manufacturer = SCPI_IDN1;
	default_board.scpi_info.device = SCPI_IDN2;
	default_board.scpi_info.serial_number = SCPI_IDN3;
	default_board.scpi_info.software_version = SCPI_IDN4;

	default_board.security.state = SECURITY_ON;
	default_board.security.password = PASSWORD;

	default_board.ip4_static.hostname = default_board.ip4_current.hostname = SCPI_IDN2;
	default_board.ip4_static.ip[0] = default_board.ip4_current.ip[0] = IP_ADDRESS_0;
	default_board.ip4_static.ip[1] = default_board.ip4_current.ip[1] = IP_ADDRESS_1;
	default_board.ip4_static.ip[2] = default_board.ip4_current.ip[2] = IP_ADDRESS_2;
	default_board.ip4_static.ip[3] = default_board.ip4_current.ip[3] = IP_ADDRESS_3;

	default_board.ip4_static.netmask[0] = default_board.ip4_current.netmask[0] = NETMASK_ADDRESS_0;
	default_board.ip4_static.netmask[1] = default_board.ip4_current.netmask[1] = NETMASK_ADDRESS_1;
	default_board.ip4_static.netmask[2] = default_board.ip4_current.netmask[2] = NETMASK_ADDRESS_2;
	default_board.ip4_static.netmask[3] = default_board.ip4_current.netmask[3] = NETMASK_ADDRESS_3;

	default_board.ip4_static.gateway[0] = default_board.ip4_current.gateway[0] = GATEWAY_ADDRESS_0;
	default_board.ip4_static.gateway[1] = default_board.ip4_current.gateway[1] = GATEWAY_ADDRESS_1;
	default_board.ip4_static.gateway[2] = default_board.ip4_current.gateway[2] = GATEWAY_ADDRESS_2;
	default_board.ip4_static.gateway[3] = default_board.ip4_current.gateway[3] = GATEWAY_ADDRESS_3;

	default_board.ip4_static.port = default_board.ip4_current.port = TCPIP_PORT;

	default_board.ip4_static.MAC[0] = default_board.ip4_current.MAC[0] = MAC_0;
	default_board.ip4_static.MAC[1] = default_board.ip4_current.MAC[1] = MAC_1;
	default_board.ip4_static.MAC[2] = default_board.ip4_current.MAC[2] = MAC_2;
	default_board.ip4_static.MAC[3] = default_board.ip4_current.MAC[3] = MAC_3;
	default_board.ip4_static.MAC[4] = default_board.ip4_current.MAC[4] = MAC_4;
	default_board.ip4_static.MAC[5] = default_board.ip4_current.MAC[5] = MAC_5;

	default_board.default_config = DEFAULT_OFF;

	board = default_board;

}

void BOARD_DetectDefaultConfig()
{
	board.default_cfg = !HAL_GPIO_ReadPin(MCU_DEFAULT_GPIO_Port, MCU_DEFAULT_Pin);
}
