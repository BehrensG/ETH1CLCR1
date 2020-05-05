/*
 * Relays.c
 *
 *  Created on: Apr 19, 2020
 *      Author: grzegorz
 */
#include "relay.h"

static void RELAY_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	if(PinState)
	{
		LL_GPIO_SetOutputPin(GPIOx, GPIO_Pin);
	}
	else
	{
		LL_GPIO_ResetOutputPin(GPIOx, GPIO_Pin);
	}
}

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
			case SR_10CTR:	RELAY_GPIO_WritePin(SR_10CTR_GPIO_Port, SR_10CTR_Pin, state); break;
			case SR_100CTR:	RELAY_GPIO_WritePin(SR_100CTR_GPIO_Port, SR_100CTR_Pin, state); break;
			case SR_1KCTR:	RELAY_GPIO_WritePin(SR_1KCTR_GPIO_Port, SR_1KCTR_Pin, state); break;
			case SR_10KCTR:	RELAY_GPIO_WritePin(SR_10KCTR_GPIO_Port, SR_10KCTR_Pin, state); break;
		}
	}
}

void RELAY_9012_DisableAll(void)
{
	RELAY_GPIO_WritePin(SR_10CTR_GPIO_Port, SR_10CTR_Pin, OFF);
	RELAY_GPIO_WritePin(SR_100CTR_GPIO_Port, SR_100CTR_Pin, OFF);
	RELAY_GPIO_WritePin(SR_1KCTR_GPIO_Port, SR_1KCTR_Pin, OFF);
	RELAY_GPIO_WritePin(SR_10KCTR_GPIO_Port, SR_10KCTR_Pin, OFF);
}

void RELAY_HE3621_Control(uint8_t relay, uint8_t state)
{
	uint8_t select = 0, shift = 0x01;

	for(uint8_t i = 0; i < HE3621_REL_COUNT; i++)
	{
		select = relay & (shift << i);

		switch(select)
		{
			case CXN_REL1:	RELAY_GPIO_WritePin(CXN_REL1_GPIO_Port, CXN_REL1_Pin, state); break;
			case CXN_REL2:	RELAY_GPIO_WritePin(CXN_REL2_GPIO_Port, CXN_REL2_Pin, state); break;
			case CXN_REL3:	RELAY_GPIO_WritePin(CXN_REL3_GPIO_Port, CXN_REL3_Pin, state); break;
			case CXN_REL4:	RELAY_GPIO_WritePin(CXN_REL4_GPIO_Port, CXN_REL4_Pin, state); break;
			case CXN_REL5:	RELAY_GPIO_WritePin(CXN_REL5_GPIO_Port, CXN_REL5_Pin, state); break;
			case CXN_REL6:	RELAY_GPIO_WritePin(CXN_REL6_GPIO_Port, CXN_REL6_Pin, state); break;
		}
	}
}

void RELAY_HE3621_DisableAll(void)
{
	RELAY_GPIO_WritePin(CXN_REL1_GPIO_Port, CXN_REL1_Pin, OFF);
	RELAY_GPIO_WritePin(CXN_REL2_GPIO_Port, CXN_REL2_Pin, OFF);
	RELAY_GPIO_WritePin(CXN_REL3_GPIO_Port, CXN_REL3_Pin, OFF);
	RELAY_GPIO_WritePin(CXN_REL4_GPIO_Port, CXN_REL4_Pin, OFF);
	RELAY_GPIO_WritePin(CXN_REL5_GPIO_Port, CXN_REL5_Pin, OFF);
	RELAY_GPIO_WritePin(CXN_REL6_GPIO_Port, CXN_REL6_Pin, OFF);
}

void RELAY_AQY212_Control(uint32_t photo_mos, uint8_t state)
{
	uint32_t select = 0, shift = 0x00000001;

	for(uint8_t i = 0; i < AQY212_REL_COUNT; i++)
	{
		select = photo_mos & (shift << i);

		switch(select)
		{
			case PA_MOS1:		RELAY_GPIO_WritePin(PA_MOS1_GPIO_Port, PA_MOS1_Pin, state); break;
			case PA_MOS2:		RELAY_GPIO_WritePin(PA_MOS2_GPIO_Port, PA_MOS2_Pin, state); break;
			case PA_MOS3:		RELAY_GPIO_WritePin(PA_MOS3_GPIO_Port, PA_MOS3_Pin, state); break;
			case PA_MOS4:		RELAY_GPIO_WritePin(PA_MOS4_GPIO_Port, PA_MOS4_Pin, state); break;
			case PA_MOS5:		RELAY_GPIO_WritePin(PA_MOS5_GPIO_Port, PA_MOS5_Pin, state); break;
			case PA_MOS6:		RELAY_GPIO_WritePin(PA_MOS6_GPIO_Port, PA_MOS6_Pin, state); break;
			case PA_50MV:		RELAY_GPIO_WritePin(PA_50MV_GPIO_Port, PA_50MV_Pin, state); break;
			case PA_EM:			RELAY_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, state); break;
			case PA_ER:			RELAY_GPIO_WritePin(PA_ER_GPIO_Port, PA_ER_Pin, state); break;
			case FB_CAP:		RELAY_GPIO_WritePin(FB_CAP_GPIO_Port, FB_CAP_Pin, state); break;
			case RR_HA3_COMP:	RELAY_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, state); break;
			case RR_10CTR:		RELAY_GPIO_WritePin(RR_10CTR_GPIO_Port, RR_10CTR_Pin, state); break;
			case RR_100CTR:		RELAY_GPIO_WritePin(RR_100CTR_GPIO_Port, RR_100CTR_Pin, state); break;
			case RR_1KCTR:		RELAY_GPIO_WritePin(RR_1KCTR_GPIO_Port, RR_1KCTR_Pin, state); break;
			case RR_10KCTR:		RELAY_GPIO_WritePin(RR_10KCTR_GPIO_Port, RR_10KCTR_Pin, state); break;
			case RR_100KCTR:	RELAY_GPIO_WritePin(RR_100KCTR_GPIO_Port, RR_100KCTR_Pin, state); break;
		}
	}


}

void RELAY_AQY212_DisableAll(void)
{
	RELAY_GPIO_WritePin(PA_MOS1_GPIO_Port, PA_MOS1_Pin, OFF);
	RELAY_GPIO_WritePin(PA_MOS2_GPIO_Port, PA_MOS2_Pin, OFF);
	RELAY_GPIO_WritePin(PA_MOS3_GPIO_Port, PA_MOS3_Pin, OFF);
	RELAY_GPIO_WritePin(PA_MOS4_GPIO_Port, PA_MOS4_Pin, OFF);
	RELAY_GPIO_WritePin(PA_MOS5_GPIO_Port, PA_MOS5_Pin, OFF);
	RELAY_GPIO_WritePin(PA_MOS6_GPIO_Port, PA_MOS6_Pin, OFF);
	RELAY_GPIO_WritePin(PA_50MV_GPIO_Port, PA_50MV_Pin, OFF);
	RELAY_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, OFF);
	RELAY_GPIO_WritePin(PA_ER_GPIO_Port, PA_ER_Pin, OFF);
	RELAY_GPIO_WritePin(FB_CAP_GPIO_Port, FB_CAP_Pin, OFF);
	RELAY_GPIO_WritePin(PA_EM_GPIO_Port, PA_EM_Pin, OFF);
	RELAY_GPIO_WritePin(RR_10CTR_GPIO_Port, RR_10CTR_Pin, OFF);
	RELAY_GPIO_WritePin(RR_100CTR_GPIO_Port, RR_100CTR_Pin, OFF);
	RELAY_GPIO_WritePin(RR_1KCTR_GPIO_Port, RR_1KCTR_Pin, OFF);
	RELAY_GPIO_WritePin(RR_10KCTR_GPIO_Port, RR_10KCTR_Pin, OFF);
	RELAY_GPIO_WritePin(RR_100KCTR_GPIO_Port, RR_100KCTR_Pin, OFF);
}

void RELAY_TQ2SA_Control(uint8_t state)
{
	RELAY_GPIO_WritePin(RR_RELAYCTR_GPIO_Port, RR_RELAYCTR_Pin, state);
}

