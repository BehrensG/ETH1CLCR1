/*
 * ADC.c
 *
 *  Created on: Apr 21, 2020
 *      Author: grzegorz
 */

#include "board.h"

//extern SPI_HandleTypeDef hspi3;


void ADC_PGA103_Gain(uint8_t channel, uint8_t gain)
{
	if(channel & AINB)
	{
		switch(gain)
		{
			case 1:{
						LL_GPIO_SetOutputPin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin);
						LL_GPIO_SetOutputPin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin);
					}; break;
			case 10:{
						LL_GPIO_SetOutputPin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin);
						LL_GPIO_ResetOutputPin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin);
					}; break;
			case 100:{
						LL_GPIO_ResetOutputPin(G1A0_CTR_GPIO_Port, G1A0_CTR_Pin);
						LL_GPIO_ResetOutputPin(G1A1_CTR_GPIO_Port, G1A1_CTR_Pin);
					}; break;
		}
	}
	else if(channel & AINA)
	{
		switch(gain)
		{
			case 1:{
						LL_GPIO_SetOutputPin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin);
						LL_GPIO_SetOutputPin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin);
					}; break;
			case 10:{
						LL_GPIO_SetOutputPin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin);
						LL_GPIO_ResetOutputPin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin);
					}; break;
			case 100:{
						LL_GPIO_ResetOutputPin(G2A0_CTR_GPIO_Port, G2A0_CTR_Pin);
						LL_GPIO_ResetOutputPin(G2A1_CTR_GPIO_Port, G2A1_CTR_Pin);
					}; break;
		}
	}
}

void ADC_ADG419_Switch(uint8_t channel, uint8_t state)
{
	if(channel & AINB)
	{
		(ON == state)? LL_GPIO_SetOutputPin(ADC_NULL1_GPIO_Port, ADC_NULL1_Pin) : LL_GPIO_ResetOutputPin(ADC_NULL1_GPIO_Port, ADC_NULL1_Pin);
	}
	else if(channel & AINA)
	{
		(ON == state)? LL_GPIO_SetOutputPin(ADC_NULL2_GPIO_Port, ADC_NULL2_Pin) : LL_GPIO_ResetOutputPin(ADC_NULL2_GPIO_Port, ADC_NULL2_Pin);
	}
}

//AD7380


 BRD_StatusTypeDef ADC_AD738x_RegisterRead(uint8_t reg_addr, uint16_t *rx_data, uint32_t timeout)
{
	uint32_t start_time = 0, current_time = 0;
	volatile AD783x_reg_data tx_data;

	BRD_StatusTypeDef spi_status = BRD_OK;

	tx_data.bytes[1] = AD738X_REG_READ(reg_addr);
	tx_data.bytes[0] = 0x00;

	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

    while (!LL_SPI_IsActiveFlag_TXC(SPI3)){};

    LL_SPI_TransmitData16(SPI3, tx_data.word16);

    start_time = HAL_GetTick();
	while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
    {
        current_time = HAL_GetTick() - start_time;
        if (current_time > timeout)
        {
        	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
        	spi_status = BRD_TIMEOUT;
            break;
        }
    }

    *rx_data= LL_SPI_ReceiveData16(SPI3);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);


    while (!LL_SPI_IsActiveFlag_TXC(SPI3)){};

	LL_SPI_TransmitData16(SPI3, tx_data.word16);

    start_time = HAL_GetTick();
	while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
    {
        current_time = HAL_GetTick() - start_time;
        if (current_time > timeout)
        {
        	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
        	spi_status = BRD_TIMEOUT;
            break;
        }
    }

    *rx_data= LL_SPI_ReceiveData16(SPI3);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

	return spi_status;
}

BRD_StatusTypeDef ADC_AD738x_RegisterWrite(uint8_t reg_addr, uint16_t reg_data, uint32_t timeout)
{
	uint32_t start_time = 0, current_time = 0;
	AD783x_reg_data tx_data;
	volatile uint16_t dummy_read;

	tx_data.bytes[1] = AD738X_REG_WRITE(reg_addr) | ((reg_data & 0xF00) >> 8);
	tx_data.bytes[0] = reg_data & 0xFFF;

	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

    while (!LL_SPI_IsActiveFlag_TXC(SPI3)){};

	LL_SPI_TransmitData16(SPI3, tx_data.word16);

	start_time = HAL_GetTick();
	while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
    {
        current_time = HAL_GetTick() - start_time;
        if (current_time > timeout)
        {
        	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
        	return BRD_TIMEOUT;
        }
    }

    dummy_read = LL_SPI_ReceiveData16(SPI3);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

    while (!LL_SPI_IsActiveFlag_TXC(SPI3)){};

	LL_SPI_TransmitData16(SPI3, tx_data.word16);

	start_time = HAL_GetTick();
	while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
    {
        current_time = HAL_GetTick() - start_time;
        if (current_time > timeout)
        {
        	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
        	return BRD_TIMEOUT;
        }
    }

    dummy_read = LL_SPI_ReceiveData16(SPI3);

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

	return BRD_OK;
}


static BRD_StatusTypeDef ADC_AD738x_RegisterWriteMask(uint8_t reg_addr, uint16_t mask, uint16_t tx_data, uint32_t timeout)
{
	BRD_StatusTypeDef spi_status;
	uint16_t reg_data;

	spi_status = ADC_AD738x_RegisterRead(reg_addr, &reg_data, timeout);

	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	reg_data &= ~mask;
	reg_data |= tx_data;

	return ADC_AD738x_RegisterWrite(reg_addr, reg_data, timeout);
}



BRD_StatusTypeDef ADC_AD738x_SingleConversion(uint16_t* rx_data, uint32_t timeout)
{
	AD783x_reg_data tx_data;
	volatile uint16_t rx_tmp[2];
	uint32_t start_time, current_time;

	tx_data.bytes[1] = AD738X_REG_WRITE(AD738X_REG_NOP) | ((0x0000 & 0xF00) >> 8);
	tx_data.bytes[0] = 0x00;

	LL_GPIO_ResetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);

	start_time = HAL_GetTick();

	for (uint8_t x = 0; x < 2; x++)
	{
		while (!LL_SPI_IsActiveFlag_TXC(SPI3)){};
		LL_SPI_TransmitData16(SPI3, tx_data.word16);

		while (LL_SPI_IsActiveFlag_RXWNE(SPI3))
	    {
	        current_time = HAL_GetTick() - start_time;
	        if (current_time > timeout)
	        {
	    		LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
	        	return BRD_TIMEOUT;
	        }
	    }

	    *rx_data++ = LL_SPI_ReceiveData16(SPI3);
	}

	LL_GPIO_SetOutputPin(ADC_nCS_GPIO_Port, ADC_nCS_Pin);
	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD738x_ConversionMode(ad738x_conv_mode mode, uint32_t timeout)
{
	BRD_StatusTypeDef spi_status;

	spi_status = ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG2, AD738X_CONFIG2_SDO2_MSK, AD738X_CONFIG2_SDO2(mode), timeout);

	if(BRD_OK != spi_status)
	{
		return spi_status;
	}
	board.AD7380.conv_mode = mode;

	return BRD_OK;
}

BRD_StatusTypeDef ADC_AD738x_Reset(ad738x_reset_type reset, uint32_t timeout)
{
	uint16_t val = ((reset == HARD_RESET)? 0xFF : 0x3C);

	return ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG2, AD738X_CONFIG2_RESET_MSK, AD738X_CONFIG2_RESET(val), timeout);

}

BRD_StatusTypeDef ADC_AD738x_OversamplingConfig(ad738x_os_mode os_mode, ad738x_os_ratio os_ratio, ad738x_resolution res, uint32_t timeout)
{
	BRD_StatusTypeDef spi_status;
	uint16_t rx_data;

	spi_status = ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG1, AD738X_CONFIG1_OS_MODE_MSK, AD738X_CONFIG1_OS_MODE(os_mode), timeout);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	spi_status = ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG1, AD738X_CONFIG1_OSR_MSK, AD738X_CONFIG1_OSR(os_ratio), timeout);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	spi_status = ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG1, AD738X_CONFIG1_RES_MSK, AD738X_CONFIG1_RES(res), timeout);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	spi_status = ADC_AD738x_RegisterRead(AD738X_REG_CONFIG1, &rx_data, timeout);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	board.AD7380.resolution = (rx_data & AD738X_CONFIG1_RES_MSK) >> 2;

	return BRD_OK;
}


BRD_StatusTypeDef ADC_AD738x_ReferenceSelect(ad738x_ref_sel ref_sel, uint32_t timeout)
{
	return ADC_AD738x_RegisterWriteMask(AD738X_REG_CONFIG1, AD738X_CONFIG1_REFSEL_MSK, AD738X_CONFIG1_REFSEL(ref_sel), timeout);
}

BRD_StatusTypeDef ADC_AD7380_Init(void)
{
	BRD_StatusTypeDef spi_status;
	ad738x_init_param ad7380_init;
	ad7380_init.conv_mode = ONE_WIRE_MODE;
	ad7380_init.ref_sel = EXT_REF;

	spi_status = ADC_AD738x_ConversionMode(ad7380_init.conv_mode, AD738X_TIMEOUT_MAX);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	spi_status = ADC_AD738x_ReferenceSelect(ad7380_init.ref_sel, AD738X_TIMEOUT_MAX);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	spi_status = ADC_AD738x_OversamplingConfig(NORMAL_OS_MODE, OSR_DISABLED, RES_16_BIT, AD738X_TIMEOUT_MAX);

	if(BRD_OK != spi_status)
	{
		return BRD_TIMEOUT;
	}

	return BRD_OK;
}

BRD_StatusTypeDef ADC_OffsetCalibration(void)
{
	return BRD_OK;
}
