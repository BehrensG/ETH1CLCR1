/*
 * board_def.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_

#include "stm32f7xx_hal.h"

#define SCPI_MANUFACTURER_STRING_LENGTH 49
#define SCPI_DEVICE_STRING_LENGTH 49
#define SCPI_SERIALNUMBER_STRING_LENGTH 49
#define SCPI_SOFTWAREVERSION_STRING_LENGTH 49
#define HOSTNAME_LENGTH 20
#define PASSWORD_LENGTH 49
#define PASSWORD "ETH1CLCR1"

#define IP_ADDRESS_0 192
#define IP_ADDRESS_1 168
#define IP_ADDRESS_2 0
#define IP_ADDRESS_3 123

#define NETMASK_ADDRESS_0 255
#define NETMASK_ADDRESS_1 255
#define NETMASK_ADDRESS_2 255
#define NETMASK_ADDRESS_3 0

#define GATEWAY_ADDRESS_0 192
#define GATEWAY_ADDRESS_1 168
#define GATEWAY_ADDRESS_2 0
#define GATEWAY_ADDRESS_3 1

#define MAC_0 0x00
#define MAC_1 0x80
#define MAC_2 0xE1
#define MAC_3 0x00
#define MAC_4 0x00
#define MAC_5 0x00

#define HOSTNAME "ETH1CLCR1"

#define TCPIP_DEFAULT_PORT 2000

#define MCU_DEFAULT_OFF 0
#define MCU_DEFAULT_ON 1

#define MCU_SERVICE_SECURITY_OFF 0
#define MCU_SERVICE_SECURITY_ON 1
#define STRUCT_SIZE 350

#pragma pack(push, 1)

struct brd_scpi_info
{
	int8_t manufacturer[SCPI_MANUFACTURER_STRING_LENGTH];
	int8_t device[SCPI_DEVICE_STRING_LENGTH];
	int8_t serial_number[SCPI_SERIALNUMBER_STRING_LENGTH];
	int8_t software_version[SCPI_SOFTWAREVERSION_STRING_LENGTH];

};

struct brd_dhcp
{
	uint8_t enable;
};

typedef struct brd_dhcp brd_dhcp_t;

struct brd_ip4_lan
{
	uint8_t ip[4];
	uint8_t netmask[4];
	uint8_t gateway[4];
	uint8_t MAC[6];
	int8_t hostname[HOSTNAME_LENGTH];
	uint16_t port;
};

struct brd_security
{
	uint8_t status;
	int8_t password[PASSWORD_LENGTH];
};

struct brd_average
{
	uint16_t count;
	uint8_t status;
};

typedef struct brd_average brd_average_t;

struct brd_sense
{
	brd_average_t average;
	uint8_t function;
	uint8_t mode;
	uint8_t nominal_val_enable;
};

struct brd_offset
{
	double value;
	uint8_t status;
};

typedef struct brd_offset brd_offset_t;

struct brd_source
{
	uint32_t frequency;
	double ampltidue;
	brd_offset_t offset;
};

struct brd_temperature
{
	uint8_t unit;
};

typedef struct brd_ip4_lan brd_ip4_lan_t;
typedef struct brd_spi_module brd_spi_module_t;
typedef struct brd_scpi_info brd_scpi_info_t;
typedef struct brd_security brd_security_t;
typedef struct brd_source brd_source_t;
typedef struct brd_temperature brd_temperature_t;

struct brd_system
{
	brd_dhcp_t dhcp;
	brd_ip4_lan_t ip4_current;
	brd_ip4_lan_t ip4_static;
	brd_security_t security;
	brd_temperature_t temperature;
};

typedef struct brd_system brd_system_t;

union brd_data
{
	struct data
	{
		brd_scpi_info_t info;
		brd_system_t system;
		brd_source_t source;
		uint8_t default_cfg;

	}structure;
	uint8_t bytes[STRUCT_SIZE];
}board, default_board;

#pragma pack(pop)

typedef enum
{
  BRD_OK       = 0x00U,
  BRD_ERROR    = 0x01U,
  BRD_BUSY = 0x02U,
  BRD_TIMEOUT  = 0x03U,
  BRD_EEPROM_EMPTY = 0x04U,
  BRD_EEPROM_MAX_SIZE = 0x05U
} BRD_StatusTypeDef;


#endif /* INC_BOARD_H_ */
