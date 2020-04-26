/*
 * Relays.c
 *
 *  Created on: Apr 19, 2020
 *      Author: grzegorz
 */
#include "relay.h"

/*
void RELAY_Init(void)
{
	RELAY_9012_DisableAll();
	RELAY_HE3621_DisableAll();
	RELAY_AQY212_DisableAll();
	RELAY_TQ2SA_Control(OFF);
}

void RELAY_9012_Control(uint8_t relay, uint8_t state)
{
	uint8_t select = 0, shift = 0x01;

	for(uint8_t i = 0; i < COTO9012_REL_COUNT; i++)
	{
		select = relay & (shift << i);

		switch(select)
		{
			case SR_10CTR:	HAL_GPIO_WritePin(SR_10CTR_GPIO_Port, SR_10CTR_Pin, state); break;
			case SR_100CTR:	HAL_GPIO_WritePin(SR_100CTR_GPIO_Port, SR_100CTR_Pin, state); break;
			case SR_1KCTR:	HAL_GPIO_WritePin(SR_1KCTR_GPIO_Port, SR_1KCTR_Pin, state); break;
			case SR_10KCTR:	HAL_GPIO_WritePin(SR_10KCTR_GPIO_Port, SR_10KCTR_Pin, state); break;
		}
	}
}

void RELAY_9012_DisableAll(void)
{
	HAL_GPIO_WritePin(SR_10CTR_GPIO_Port, SR_10CTR_Pin, OFF);
	HAL_GPIO_WritePin(SR_100CTR_GPIO_Port, SR_100CTR_Pin, OFF);
	HAL_GPIO_WritePin(SR_1KCTR_GPIO_Port, SR_1KCTR_Pin, OFF);
	HAL_GPIO_WritePin(SR_10KCTR_GPIO_Port, SR_10KCTR_Pin, OFF);
}

void RELAY_HE3621_Control(uint8_t relay, uint8_t state)
{
	uint8_t select = 0, shift = 0x01;

	for(uint8_t i = 0; i < HE3621_REL_COUNT; i++)
	{
		select = relay & (shift << i);

		switch(select)
		{
			case CXN_REL1:	HAL_GPIO_WritePin(CXN_REL1_GPIO_Port, CXN_REL1_Pin, state); break;
			case CXN_REL2:	HAL_GPIO_WritePin(CXN_REL2_GPIO_Port, CXN_REL2_Pin, state); break;
			case CXN_REL3:	HAL_GPIO_WritePin(CXN_REL3_GPIO_Port, CXN_REL3_Pin, state); break;
			case CXN_REL4:	HAL_GPIO_WritePin(CXN_REL4_GPIO_Port, CXN_REL4_Pin, state); break;
			case CXN_REL5:	HAL_GPIO_WritePin(CXN_REL5_GPIO_Port, CXN_REL5_Pin, state); break;
			case CXN_REL6:	HAL_GPIO_WritePin(CXN_REL6_GPIO_Port, CXN_REL6_Pin, state); break;
		}
	}
}

void RELAY_HE3621_DisableAll(void)
{
	HAL_GPIO_WritePin(CXN_REL1_GPIO_Port, CXN_REL1_Pin, OFF);
	HAL_GPIO_WritePin(CXN_REL2_GPIO_Port, CXN_REL2_Pin, OFF);
	HAL_GPIO_WritePin(CXN_REL3_GPIO_Port, CXN_REL3_Pin, OFF);
	HAL_GPIO_WritePin(CXN_REL4_GPIO_Port, CXN_REL4_Pin, OFF);
	HAL_GPIO_WritePin(CXN_REL5_GPIO_Port, CXN_REL5_Pin, OFF);
	HAL_GPIO_WritePin(CXN_REL6_GPIO_Port, CXN_REL6_Pin, OFF);
}

void RELAY_AQY212_Control(uint32_t photo_mos, uint8_t state)
{
	uint32_t select = 0, shift = 0x00000001;

	for(uint8_t i = 0; i < AQY212_REL_COUNT; i++)
	{
		select = photo_mos & (shift << i);

		switch(select)
		{
			case PA_MOS1:		HAL_GPIO_WritePin(PA_MOS1_GPIO_Port, PA_MOS1_Pin, state); break;
			case PA_MOS2:		HAL_GPIO_WritePin(PA_MOS2_GPIO_Port, PA_MOS2_Pin, state); break;
			case PA_MOS3:		HAL_GPIO_WritePin(PA_MOS3_GPIO_Port, PA_MOS3_Pin, state); break;
			case PA_MOS4:		HAL_GPIO_WritePin(PA_MOS4_GPIO_Port, PA_MOS4_Pin, state); break;
			case PA_MOS5:		HAL_GPIO_WritePin(PA_MOS5_GPIO_Port, PA_MOS5_Pin, state); break;
			case PA_MOS6:		HAL_GPIO_WritePin(PA_MOS6_GPIO_Port, PA_MOS6_Pin, state); break;
			case PA_50MV:		HAL_GPIO_WritePin(PA_50MV_GPIO_Port, PA_50MV_Pin, state); break;
			case PA_EM:			HAL_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, state); break;
			case PA_ER:			HAL_GPIO_WritePin(PA_ER_GPIO_Port, PA_ER_Pin, state); break;
			case FB_CAP:		HAL_GPIO_WritePin(FB_CAP_GPIO_Port, FB_CAP_Pin, state); break;
			case RR_HA3_COMP:	HAL_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, state); break;
			case RR_10CTR:		HAL_GPIO_WritePin(RR_10CTR_GPIO_Port, RR_10CTR_Pin, state); break;
			case RR_100CTR:		HAL_GPIO_WritePin(RR_100CTR_GPIO_Port, RR_100CTR_Pin, state); break;
			case RR_1KCTR:		HAL_GPIO_WritePin(RR_1KCTR_GPIO_Port, RR_1KCTR_Pin, state); break;
			case RR_10KCTR:		HAL_GPIO_WritePin(RR_10KCTR_GPIO_Port, RR_10KCTR_Pin, state); break;
			case RR_100KCTR:	HAL_GPIO_WritePin(RR_100KCTR_GPIO_Port, RR_100KCTR_Pin, state); break;
		}
	}


}

void RELAY_AQY212_DisableAll(void)
{
	HAL_GPIO_WritePin(PA_MOS1_GPIO_Port, PA_MOS1_Pin, OFF);
	HAL_GPIO_WritePin(PA_MOS2_GPIO_Port, PA_MOS2_Pin, OFF);
	HAL_GPIO_WritePin(PA_MOS3_GPIO_Port, PA_MOS3_Pin, OFF);
	HAL_GPIO_WritePin(PA_MOS4_GPIO_Port, PA_MOS4_Pin, OFF);
	HAL_GPIO_WritePin(PA_MOS5_GPIO_Port, PA_MOS5_Pin, OFF);
	HAL_GPIO_WritePin(PA_MOS6_GPIO_Port, PA_MOS6_Pin, OFF);
	HAL_GPIO_WritePin(PA_50MV_GPIO_Port, PA_50MV_Pin, OFF);
	HAL_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, OFF);
	HAL_GPIO_WritePin(PA_ER_GPIO_Port, PA_ER_Pin, OFF);
	HAL_GPIO_WritePin(FB_CAP_GPIO_Port, FB_CAP_Pin, OFF);
	HAL_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, OFF);
	HAL_GPIO_WritePin(RR_10CTR_GPIO_Port, RR_10CTR_Pin, OFF);
	HAL_GPIO_WritePin(RR_100CTR_GPIO_Port, RR_100CTR_Pin, OFF);
	HAL_GPIO_WritePin(RR_1KCTR_GPIO_Port, RR_1KCTR_Pin, OFF);
	HAL_GPIO_WritePin(RR_10KCTR_GPIO_Port, RR_10KCTR_Pin, OFF);
	HAL_GPIO_WritePin(RR_100KCTR_GPIO_Port, RR_100KCTR_Pin, OFF);
}

void RELAY_TQ2SA_Control(uint8_t state)
{
	HAL_GPIO_WritePin(RR_RELAYCTR_GPIO_Port, RR_RELAYCTR_Pin, state);
}
*/
