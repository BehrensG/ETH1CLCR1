/*
 * ADC.c
 *
 *  Created on: Apr 21, 2020
 *      Author: grzegorz
 */

#include "ADC.h"

//extern SPI_HandleTypeDef hspi3;

/*
void ADC_PGA103_Gain(uint8_t channel, uint8_t gain)
{
	if(channel & AINB)
	{
		switch(gain)
		{
			case 1:{
				HAL_GPIO_WritePin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin, OFF);
			}; break;
			case 10:{
				HAL_GPIO_WritePin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin, ON);
			}; break;
			case 100:{
				HAL_GPIO_WritePin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin, ON);
			}; break;
		}
	}
	else if(channel & AINA)
	{
		switch(gain)
		{
			case 1:{
				HAL_GPIO_WritePin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin, OFF);
			}; break;
			case 10:{
				HAL_GPIO_WritePin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin, ON);
			}; break;
			case 100:{
				HAL_GPIO_WritePin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin, OFF);
				HAL_GPIO_WritePin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin, ON);
			}; break;
		}
	}
}

void ADC_ADG419_Switch(uint8_t channel, uint8_t state)
{
	if(channel & AINB)
	{
		HAL_GPIO_WritePin(ADC_NULL1_GPIO_Port, ADC_NULL1_Pin, state);
	}
	else if(channel & AINA)
	{
		HAL_GPIO_WritePin(ADC_NULL2_GPIO_Port, ADC_NULL2_Pin, state);
	}
}

//AD7380
*/

 BRD_StatusTypeDef ADC_AD7380_RegisterRead(uint16_t reg_addr, uint16_t *reg_data)
{
	BRD_StatusTypeDef spi_status;
	AD783x_reg_data tx_data;
	volatile AD783x_reg_data rx_data;
	rx_data.word16 = 0x1234;
	tx_data.word16 = reg_addr;
	uint32_t start_time = 0, stop_time = 0;

	LL_SPI_StartMasterTransfer(SPI3);
	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);


    while (!LL_SPI_IsActiveFlag_TXC(SPI3)) {};
    start_time = HAL_GetTick();
	LL_SPI_TransmitData16(SPI3, tx_data.word16);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

    while (!LL_SPI_IsActiveFlag_TXC(SPI3)) {};
	LL_SPI_TransmitData16(SPI3, tx_data.word16);
	while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
    {
        stop_time = HAL_GetTick() - start_time;
        if (stop_time > 1000)
        {
        	spi_status = BRD_TIMEOUT;
            break;
        }
    }
       rx_data.word16= LL_SPI_ReceiveData16(SPI3);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

	spi_status = BRD_OK;

	return spi_status;
}

 /*
static BRD_StatusTypeDef ADC_AD7380_RegisterWrite(uint8_t reg_addr, uint16_t reg_data)
{
	BRD_StatusTypeDef spi_status;
	AD783x_reg_data tx_data;

	tx_data.word16 = reg_addr | reg_data;

	//HAL_GPIO_WritePin(ADC_nCS_GPIO_Port, ADC_nCS_Pin, OFF);
	spi_status = HAL_SPI_Transmit_DMA(&hspi3, tx_data.bytes, 1);
	//HAL_GPIO_WritePin(ADC_nCS_GPIO_Port, ADC_nCS_Pin, ON);

	return spi_status;
}

static BRD_StatusTypeDef ADC_AD7380_RegisterWriteMask(uint8_t reg_addr, uint32_t mask, uint16_t data)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_SingleConversion(uint16_t *adc_data)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_ConversionMode(ad738x_conv_mode mode)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_Reset(ad738x_reset_type reset)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_OversamplingConfig(ad738x_os_mode os_mode, ad738x_os_ratio os_ratio, ad738x_resolution res)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_Ad7380_PowerDownMode(ad738x_pwd_mode pmode)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_ReferenceSelect(ad738x_ref_sel ref_sel)
{
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD7380_Init(ad738x_init_param init_param)
{
	return BRD_OK;
}
*/
