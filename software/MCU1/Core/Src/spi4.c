/*
 * spi4.c
 *
 *  Created on: May 20, 2020
 *      Author: grzegorz
 */

#include <string.h>
#include <stdlib.h>

#include "board.h"
#include "spi4.h"
#include "main.h"

extern SPI_HandleTypeDef hspi4;

static void remove_chars(int8_t* str, int8_t c, uint32_t size) {
    int8_t *pr = str, *pw = str;
    for (uint32_t x = 0; x < size; x++)
    {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\0';
}

static int32_t find_chars(int8_t* str, int8_t c, uint32_t size) {

    int8_t *pw = str;
    int32_t index = 0;

    for (uint32_t x = 0; x < size; x++)
    {
    	if(*pw == c)
    	{
    		return index;
    	}
    	*pw++;
    	index++;

    }
    return 0;
}

BRD_StatusTypeDef SPI4_Transmit(const int8_t str[], uint32_t timeout)
{
	BRD_StatusTypeDef status;
	int8_t tx_data[SPI4_BUFFER]= {[0 ... SPI4_BUFFER-1] = '\0'};
	uint32_t start_time = 0, current_time = 0;

	snprintf(tx_data, SPI4_BUFFER, "%s\r\n",str);

	HAL_GPIO_WritePin(MCU1_RX_DATA_GPIO_Port, MCU1_RX_DATA_Pin, 0);
	start_time = HAL_GetTick();
	while(HAL_GPIO_ReadPin(MCU2_RX_STATUS_GPIO_Port, MCU2_RX_STATUS_Pin))
	{
		current_time = HAL_GetTick() - start_time;
		if(current_time > timeout)
		{
			return BRD_MCU2_TIMEOUT;
		}
	}

	HAL_GPIO_WritePin(MCU1_TX_DATA_GPIO_Port, MCU1_TX_DATA_Pin, 1);
	status = HAL_SPI_Transmit(&hspi4, tx_data, SPI4_BUFFER, 10000);


	return status;

}

BRD_StatusTypeDef SPI4_Receive(int8_t* str, int32_t* readout_size, uint32_t timeout)
{
	BRD_StatusTypeDef status;
	int8_t rx_data[SPI4_BUFFER]= {[0 ... SPI4_BUFFER-1] = '\0'};
	int32_t index = 0;

	uint32_t start_time = 0, current_time = 0;

	HAL_GPIO_WritePin(MCU1_TX_DATA_GPIO_Port, MCU1_TX_DATA_Pin, 0);
	HAL_GPIO_WritePin(MCU1_RX_DATA_GPIO_Port, MCU1_RX_DATA_Pin, 1);

	start_time = HAL_GetTick();

	while(!HAL_GPIO_ReadPin(MCU2_RX_STATUS_GPIO_Port, MCU2_RX_STATUS_Pin))
	{
		current_time = HAL_GetTick() - start_time;
		if(current_time > timeout)
		{
			return BRD_MCU2_TIMEOUT;
		}

	}

	status = HAL_SPI_Receive(&hspi4, rx_data, SPI4_BUFFER, 10000);


	if(BRD_OK == status)
	{
		remove_chars(&rx_data,'\0', SPI4_BUFFER);
		index = find_chars(&rx_data,'\n', SPI4_BUFFER);
		rx_data[index+1] = '\0';
		strncpy(str, rx_data, index+1);
		*readout_size = index;

	}
	else
	{}

	return status;

}

