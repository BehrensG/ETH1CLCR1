/*
 * AD9835.c
 *
 *  Created on: Apr 9, 2020
 *      Author: grzegorz
 *      Software based on :  IC datasheet, AN-621 and AN-1108
 */

#include "AD9835.h"

extern SPI_HandleTypeDef hspi1;

uint8_t g_register_select;

static uint32_t AD9835_ConvertFequencyToRegister(uint32_t freq)
{
	uint32_t freq_word = 0;
	freq_word = (uint32_t)(freq/AD9835_FREQ_CONV_CONST);
	return freq_word;
}

BRD_StatusTypeDef AD9835_Output(uint8_t state)
{
	uint8_t tx_data[2];

	if(AD9835_OFF == state)
	{
		tx_data[0] = AD9835_CONTROL | AD9835_SLEEP_BIT;
		tx_data[1] = 0x00;
	}
	else if(AD9835_ON == state)
	{
		tx_data[0] = AD9835_CONTROL;
		tx_data[1] = 0x00;
	}

	return (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,tx_data, 2, 1000);
};

BRD_StatusTypeDef AD9835_Init()
{
	return BRD_OK;
}

BRD_StatusTypeDef AD9835_FrequencyRegister(uint8_t freq_reg, uint32_t freq)
{
	uint32_t freq_word32 = AD9835_ConvertFequencyToRegister(freq);
	uint8_t reg[] = {0xFF, 0xFF};
	BRD_StatusTypeDef spi_status = BRD_OK;

	if(AD9835_FREQ0 == freq_reg)
	{
		reg[0] = 0x30;
		reg[1] = (uint8_t)(freq_word32);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x21;
		reg[1] = (uint8_t)(freq_word32 >> 8);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x32;
		reg[1] = (uint8_t)(freq_word32 >> 16);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x23;
		reg[1] = (uint8_t)(freq_word32 >> 24);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

	}
	else if(AD9835_FREQ1 == freq_reg)
	{
		reg[0] = 0x34;
		reg[1] = (uint8_t)(freq_word32);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x25;
		reg[1] = (uint8_t)(freq_word32 >> 8);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x36;
		reg[1] = (uint8_t)(freq_word32 >> 16);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		reg[0] = 0x27;
		reg[1] = (uint8_t)(freq_word32 >> 24);
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1, reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

	}

	return BRD_OK;

}

static uint16_t AD9835_ConvertPhaseToRegisterValue(uint16_t phase)
{
	uint16_t reg;

	switch (phase)
	{
	case 0: reg = 0; break;
	case 90: reg = (uint16_t)(AD9835_PHASE_REG_MAX/4); break;
	case 180: reg = (uint16_t)(AD9835_PHASE_REG_MAX/2); break;
	case 270: reg= (uint16_t)(0.75*AD9835_PHASE_REG_MAX); break;
	case 360: reg = AD9835_PHASE_REG_MAX; break;
	}

	return reg;
}

// Not used
static uint8_t AD9835_ValueInArray(uint8_t val, uint8_t arr[])
{
    uint8_t i;
    for(uint8_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        if(arr[i] == val)
            return 1;
    }
    return 0;
}


BRD_StatusTypeDef AD9835_PhaseRegister()
{
	uint16_t phase_word16;
	uint8_t reg[] = {0xFF, 0xFF};
	BRD_StatusTypeDef spi_status = BRD_OK;

	// Write 0 degree to PHASE0 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(0U);
	reg[0] = 0x18;
	reg[1] = (uint8_t)(phase_word16);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}
	reg[0] = 0x09;
	reg[1] = (uint8_t)(phase_word16>>8);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 90 degree to PHASE1 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(90U);
	reg[0] = 0x1A;
	reg[1] = (uint8_t)(phase_word16);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}
	reg[0] = 0x0B;
	reg[1] = (uint8_t)(phase_word16>>8);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 180 degree to PHASE2 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(180U);
	reg[0] = 0x1C;
	reg[1] = (uint8_t)(phase_word16);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}
	reg[0] = 0x0D;
	reg[1] = (uint8_t)(phase_word16>>8);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 270 degree to PHASE3 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(270U);
	reg[0] = 0x1E;
	reg[1] = (uint8_t)(phase_word16);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}
	reg[0] = 0x0F;
	reg[1] = (uint8_t)(phase_word16>>8);
	spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_SelectionType(uint8_t select)
{
	uint8_t reg[] = {0xFF, 0xFF};
	BRD_StatusTypeDef spi_status;

	if(AD9835_SPI == select)
	{
		g_register_select = select;
		reg[0] = AD9835_SELECT | AD9835_SPI_SELSRC_BIT;
		reg[1] = 0x00;
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}
	}
	else if(AD9835_GPIO == select)
	{
		g_register_select = select;
		reg[0] = AD9835_SELECT | AD9835_GPIO_SELSRC_BIT;
		reg[1] = 0x00;
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}
	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_FrequencyRegisterSelect(uint8_t freq_reg)
{
	uint8_t reg[] = {0x00, 0x00};
	BRD_StatusTypeDef spi_status;

	if(AD9835_SPI == g_register_select)
	{
		switch (freq_reg)
		{
			case AD9835_FREQ0: reg[0] = AD9835_FREQ_SEL_REG | 0x00; break;
			case AD9835_FREQ1: reg[0] = AD9835_FREQ_SEL_REG | 0x80; break;
		}
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}
	}
	else if(AD9835_GPIO == g_register_select)
	{
		HAL_GPIO_WritePin(DDS_FGEN_FSELECT_GPIO_Port, DDS_FGEN_FSELECT_Pin, freq_reg);

	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_PhaseRegisterSelect(uint8_t phase_reg)
{
	uint8_t reg[] = {0x00, 0x00};
	BRD_StatusTypeDef spi_status;

	if(AD9835_SPI == g_register_select)
	{
		switch (phase_reg)
		{
			case AD9835_PHASE0: reg[0] = AD9835_PHASE_SEL_REG; break;
			case AD9835_PHASE1: reg[0] = AD9835_PHASE_SEL_REG | AD9835_PSEL0; break;
			case AD9835_PHASE2: reg[0] = AD9835_PHASE_SEL_REG | AD9835_PSEL1; break;
			case AD9835_PHASE3: reg[0] = AD9835_PHASE_SEL_REG | AD9835_PSEL1 | AD9835_PSEL0; break;
		}
		spi_status = (BRD_StatusTypeDef)HAL_SPI_Transmit(&hspi1,reg, 2, 1000);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}
	}
	else if(AD9835_GPIO == g_register_select)
	{
		switch (phase_reg)
		{
			case AD9835_PHASE0: {HAL_GPIO_WritePin(DDS_FGEN_PSEL1_GPIO_Port, DDS_FGEN_PSEL1_Pin, 0); HAL_GPIO_WritePin(DDS_FGEN_PSEL0_GPIO_Port, DDS_FGEN_PSEL0_Pin, 0);}; break;
			case AD9835_PHASE1: {HAL_GPIO_WritePin(DDS_FGEN_PSEL1_GPIO_Port, DDS_FGEN_PSEL1_Pin, 0); HAL_GPIO_WritePin(DDS_FGEN_PSEL0_GPIO_Port, DDS_FGEN_PSEL0_Pin, 1);}; break;
			case AD9835_PHASE2: {HAL_GPIO_WritePin(DDS_FGEN_PSEL1_GPIO_Port, DDS_FGEN_PSEL1_Pin, 1); HAL_GPIO_WritePin(DDS_FGEN_PSEL0_GPIO_Port, DDS_FGEN_PSEL0_Pin, 0);}; break;
			case AD9835_PHASE3: {HAL_GPIO_WritePin(DDS_FGEN_PSEL1_GPIO_Port, DDS_FGEN_PSEL1_Pin, 1); HAL_GPIO_WritePin(DDS_FGEN_PSEL0_GPIO_Port, DDS_FGEN_PSEL0_Pin, 1);}; break;
		}
	}

	return BRD_OK;
}
