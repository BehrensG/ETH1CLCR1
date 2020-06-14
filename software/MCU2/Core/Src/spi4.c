/*
 * spi4.c
 *
 *  Created on: May 30, 2020
 *      Author: grzegorz
 */

#include "board.h"
#include "spi4.h"

BRD_StatusTypeDef SPI4_Transmit(uint8_t *pData, uint16_t size, uint32_t timeout)
{
	uint32_t start_time = 0, current_time = 0;


	LL_GPIO_ResetOutputPin(MCU3_nSS_GPIO_Port, MCU3_nSS_Pin);

    start_time = HAL_GetTick();
    for(uint16_t x = 0; x < size; x++)
    {

    	while(!LL_SPI_IsActiveFlag_TXC(SPI4))
    	{
            current_time = HAL_GetTick() - start_time;
            if (current_time > timeout)
            {
            	LL_GPIO_SetOutputPin(MCU3_nSS_GPIO_Port, MCU3_nSS_Pin);
            	return BRD_TIMEOUT;
            }
    	}
    	LL_SPI_TransmitData8(SPI4, *pData++);
    }

	LL_GPIO_SetOutputPin(MCU3_nSS_GPIO_Port, MCU3_nSS_Pin);


	return BRD_OK;
}
