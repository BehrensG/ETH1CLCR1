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

static BRD_StatusTypeDef AD9835_WriteToRegister(uint16_t value)
{
	tx_data.word16 = value;
	BRD_StatusTypeDef spi_status;

	HAL_GPIO_WritePin(DDS_FGEN_nFSYNC_GPIO_Port, DDS_FGEN_nFSYNC_Pin, OFF);
	spi_status = HAL_SPI_Transmit(&hspi1, tx_data.bytes, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(DDS_FGEN_nFSYNC_GPIO_Port, DDS_FGEN_nFSYNC_Pin, ON);

	return spi_status;
}

static uint32_t AD9835_ConvertFequencyToRegister(uint32_t freq)
{
	uint32_t freq_word32 = 0;

	freq_word32 = (uint32_t)((pow(2,32)/AD9835_FMCLK)*freq);

	return freq_word32;
}

void AD9835_Test()
{
	AD9835_FrequencyRegister(AD9835_FREQ0, 100000);
	AD9835_FrequencyRegisterSelect(AD9835_FREQ0);
	AD9835_Output(AD9835_ON);
}

BRD_StatusTypeDef AD9835_Output(uint8_t state)
{
	uint8_t tx_data[2];
	BRD_StatusTypeDef spi_status;

	HAL_SPI_Init(&hspi1);

	if(AD9835_OFF == state)
	{
		spi_status = AD9835_WriteToRegister(AD9835_CONTROL | AD9835_RESET);
	}
	else if(AD9835_ON == state)
	{
		spi_status = AD9835_WriteToRegister(AD9835_CONTROL);
	}

	return spi_status;
}

BRD_StatusTypeDef AD9835_Init()
{
	BRD_StatusTypeDef spi_status;

	spi_status = AD9835_Output(AD9835_OFF);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_SelectionType(AD9835_SPI);
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_PhaseRegister();
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_FrequencyRegister(uint8_t freq_reg, uint32_t freq)
{
	uint32_t freq_word32 = AD9835_ConvertFequencyToRegister(freq);
	BRD_StatusTypeDef spi_status = BRD_OK;

	if(AD9835_FREQ0 == freq_reg)
	{
		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ8 | AD9835_FREQ0_LLSB | (uint8_t)(freq_word32));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ16 | AD9835_FREQ0_HLSB | (uint8_t)(freq_word32 >> 8));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ8 | AD9835_FREQ0_LMSB | (uint8_t)(freq_word32 >> 16));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ16 | AD9835_FREQ0_HMSB | (uint8_t)(freq_word32 >> 24));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

	}
	else if(AD9835_FREQ1 == freq_reg)
	{
		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ8 | AD9835_FREQ1_LLSB | (uint8_t)(freq_word32));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ16 | AD9835_FREQ1_HLSB | (uint8_t)(freq_word32 >> 8));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ8 | AD9835_FREQ1_LMSB | (uint8_t)(freq_word32 >> 16));
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

		spi_status = AD9835_WriteToRegister(AD9835_WRITE_FREQ16 | AD9835_FREQ1_HMSB | (uint8_t)(freq_word32 >> 24));
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


BRD_StatusTypeDef AD9835_PhaseRegister()
{
	uint16_t phase_word16;
	BRD_StatusTypeDef spi_status = BRD_OK;

	// Write 0 degree to PHASE0 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(0U);

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE8 | AD9835_PHASE0_LSB | (uint8_t)(phase_word16));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE16 | AD9835_PHASE0_MSB | (uint8_t)(phase_word16 >> 8));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 90 degree to PHASE1 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(90U);

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE8 | AD9835_PHASE1_LSB | (uint8_t)(phase_word16));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE16 | AD9835_PHASE1_MSB | (uint8_t)(phase_word16 >> 8));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 180 degree to PHASE2 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(180U);

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE8 | AD9835_PHASE2_LSB | (uint8_t)(phase_word16));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE16 | AD9835_PHASE2_MSB | (uint8_t)(phase_word16 >> 8));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	// Write 270 degree to PHASE3 register
	phase_word16 = AD9835_ConvertPhaseToRegisterValue(270U);

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE8 | AD9835_PHASE3_LSB | (uint8_t)(phase_word16));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	spi_status = AD9835_WriteToRegister(AD9835_WRITE_PHASE16 | AD9835_PHASE3_MSB | (uint8_t)(phase_word16 >> 8));
	if(BRD_OK != spi_status)
	{
		return spi_status;
	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_SelectionType(uint8_t select)
{
	BRD_StatusTypeDef spi_status = BRD_OK;

	if(AD9835_SPI == select)
	{
		g_register_select = select;

		spi_status = AD9835_WriteToRegister(AD9835_SELECT | AD9835_SPI_SELSRC);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}

	}
	else if(AD9835_GPIO == select)
	{
		g_register_select = select;

		spi_status = AD9835_WriteToRegister(AD9835_SELECT | AD9835_GPIO_SELSRC);
		if(BRD_OK != spi_status)
		{
			return spi_status;
		}
	}

	return BRD_OK;
}

BRD_StatusTypeDef AD9835_FrequencyRegisterSelect(uint8_t freq_reg)
{

	uint16_t tx_data = 0x0000;
	BRD_StatusTypeDef spi_status;

	if(AD9835_SPI == g_register_select)
	{
		switch (freq_reg)
		{
			case AD9835_FREQ0: tx_data = AD9835_FREQ_REG_SEL | AD9835_FREQ0_SEL; break;
			case AD9835_FREQ1: tx_data = AD9835_FREQ_REG_SEL | AD9835_FREQ1_SEL; break;
		}

		spi_status = AD9835_WriteToRegister(tx_data);
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
	uint16_t tx_data = 0x0000;
	BRD_StatusTypeDef spi_status;

	if(AD9835_SPI == g_register_select)
	{

		switch (phase_reg)
		{
			case AD9835_PHASE0: tx_data = AD9835_PHASE_REG_SEL | AD9835_PHASE0_SEL; break;
			case AD9835_PHASE1: tx_data = AD9835_PHASE_REG_SEL | AD9835_PHASE1_SEL; break;
			case AD9835_PHASE2: tx_data = AD9835_PHASE_REG_SEL | AD9835_PHASE2_SEL; break;
			case AD9835_PHASE3: tx_data = AD9835_PHASE_REG_SEL | AD9835_PHASE3_SEL; break;
		}

		spi_status = AD9835_WriteToRegister(tx_data);
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
