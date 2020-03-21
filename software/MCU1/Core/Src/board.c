/*
 * board_init.c
 *
 *  Created on: Mar 15, 2020
 *      Author: grzegorz
 */

#include "board.h"
#include "main.h"
#include "scpi-def.h"
#include "eeprom.h"
#include "types.h"

void BOARD_CreateDefaultData()
{
	default_board.system.dhcp.enable = FALSE;

	default_board.system.ip4_current.MAC[0]= default_board.system.ip4_static.MAC[0] = MAC_0;
	default_board.system.ip4_current.MAC[1]= default_board.system.ip4_static.MAC[1] = MAC_1;
	default_board.system.ip4_current.MAC[2]= default_board.system.ip4_static.MAC[2] = MAC_2;
	default_board.system.ip4_current.MAC[3]= default_board.system.ip4_static.MAC[3] = MAC_3;
	default_board.system.ip4_current.MAC[4]= default_board.system.ip4_static.MAC[4] = MAC_4;
	default_board.system.ip4_current.MAC[5]= default_board.system.ip4_static.MAC[5] = MAC_5;

	default_board.system.ip4_current.gateway[0] = default_board.system.ip4_static.gateway[0] = GATEWAY_ADDRESS_0;
	default_board.system.ip4_current.gateway[1] = default_board.system.ip4_static.gateway[1] = GATEWAY_ADDRESS_1;
	default_board.system.ip4_current.gateway[2] = default_board.system.ip4_static.gateway[2] = GATEWAY_ADDRESS_2;
	default_board.system.ip4_current.gateway[3] = default_board.system.ip4_static.gateway[3] = GATEWAY_ADDRESS_3;

	default_board.system.ip4_current.ip[0] = default_board.system.ip4_static.ip[0] = IP_ADDRESS_0;
	default_board.system.ip4_current.ip[1] = default_board.system.ip4_static.ip[1] = IP_ADDRESS_1;
	default_board.system.ip4_current.ip[2] = default_board.system.ip4_static.ip[2] = IP_ADDRESS_2;
	default_board.system.ip4_current.ip[3] = default_board.system.ip4_static.ip[3] = IP_ADDRESS_3;

	default_board.system.ip4_current.netmask[0] = default_board.system.ip4_static.netmask[0] = NETMASK_ADDRESS_0;
	default_board.system.ip4_current.netmask[1] = default_board.system.ip4_static.netmask[1] = NETMASK_ADDRESS_1;
	default_board.system.ip4_current.netmask[2] = default_board.system.ip4_static.netmask[2] = NETMASK_ADDRESS_2;
	default_board.system.ip4_current.netmask[3] = default_board.system.ip4_static.netmask[3] = NETMASK_ADDRESS_3;

	default_board.system.ip4_current.port = default_board.system.ip4_static.port = TCPIP_DEFAULT_PORT;

	default_board.source.ampltidue = 0;
	default_board.source.frequency = 0;
	default_board.source.offset.value = 0;
	default_board.source.offset.status = 0;

	default_board.system.security.status = 1;
	strcpy(default_board.system.security.password,PASSWORD);

	default_board.system.temperature.unit = 0;

	strcpy(default_board.system.ip4_current.hostname, HOSTNAME);
	strcpy(default_board.system.ip4_static.hostname, HOSTNAME);

	strcpy(default_board.info.device, SCPI_IDN2);
	strcpy(default_board.info.manufacturer,SCPI_IDN1);
	strcpy(default_board.info.serial_number,SCPI_IDN4);
	strcpy(default_board.info.software_version,SCPI_IDN3);

	board = default_board;

}

void BOARD_DetectDefaultConfig()
{
	board.default_cfg = !HAL_GPIO_ReadPin(MCU_DEFAULT_GPIO_Port, MCU_DEFAULT_Pin);
}
