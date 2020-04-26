/*
 * Relays.h
 *
 *  Created on: Apr 19, 2020
 *      Author: grzegorz
 */

#ifndef INC_RELAY_H_
#define INC_RELAY_H_

#include "main.h"

#define HE3621_REL_COUNT	6

#define CXN_REL1 			0x01
#define CXN_REL2			0x02
#define CXN_REL3			0x04
#define	CXN_REL4			0x08
#define	CXN_REL5			0x10
#define CXN_REL6			0x20

#define COTO9012_REL_COUNT	4

#define SR_10CTR			0x01
#define SR_100CTR			0x02
#define SR_1KCTR			0x04
#define SR_10KCTR			0x08

#define AQY212_REL_COUNT	16

#define PA_MOS1				0x00000001
#define PA_MOS2				0x00000002
#define PA_MOS3				0x00000004
#define PA_MOS4				0x00000008
#define PA_MOS5				0x00000010
#define PA_MOS6				0x00000020
#define	PA_50MV				0x00000040
#define PA_EM				0x00000080
#define PA_ER				0x00000100
#define	FB_CAP				0x00000200
#define RR_HA3_COMP			0x00000400
#define RR_10CTR			0x00000800
#define RR_100CTR			0x00001000
#define RR_1KCTR			0x00002000
#define RR_10KCTR			0x00004000
#define RR_100KCTR			0x00008000

void RELAY_Init(void);
void RELAY_9012_Control(uint8_t relay, uint8_t state);
void RELAY_9012_DisableAll(void);
void RELAY_HE3621_Control(uint8_t relay, uint8_t state);
void RELAY_HE3621_DisableAll(void);
void RELAY_AQY212_Control(uint32_t photo_mos, uint8_t state);
void RELAY_AQY212_DisableAll(void);
void RELAY_TQ2SA_Control(uint8_t state);

#endif /* INC_RELAY_H_ */
