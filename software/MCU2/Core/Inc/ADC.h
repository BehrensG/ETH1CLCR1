/*
 * ADC.h
 *
 *  Created on: Apr 21, 2020
 *      Author: grzegorz
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"


#define AINA		0x01
#define AINB		0x02

/******************************************************************************/
/********************** Macros and Constants Definitions **********************/
/******************************************************************************/
/*
 * Create a contiguous bitmask starting at bit position @l and ending at
 * position @h.
 */
#define GENMASK(h, l) \
		(((~0UL) - (1UL << (l)) + 1) & (~0UL >> (31 - (h))))

#define BIT(x)	(1U << (x))

typedef union
{
	uint16_t word16;
	uint8_t bytes[2];
}AD783x_reg_data;

typedef union
{
	uint16_t word16[2];
	uint8_t bytes[4];
}AD783x_convert_data;


/*
 * AD738X registers definition
 */
#define AD738X_REG_NOP                  0x00
#define AD738X_REG_CONFIG1              0x01
#define AD738X_REG_CONFIG2              0x02
#define AD738X_REG_ALERT                0x03
#define AD738X_REG_ALERT_LOW_TH         0x04
#define AD738X_REG_ALERT_HIGH_TH        0x05

#define AD738X_TIMEOUT_MAX				10000
/*
 * AD738X_REG_CONFIG1
 */
#define AD738X_CONFIG1_OS_MODE_MSK      BIT(9)
#define AD738X_CONFIG1_OS_MODE(x)       (((x) & 0x1) << 9)
#define AD738X_CONFIG1_OSR_MSK          GENMASK(8, 6)
#define AD738X_CONFIG1_OSR(x)           (((x) & 0x7) << 6)
#define AD738X_CONFIG1_CRC_W_MSK        BIT(5)
#define AD738X_CONFIG1_CRC_W(x)         (((x) & 0x1) << 5)
#define AD738X_CONFIG1_CRC_R_MSK        BIT(4)
#define AD738X_CONFIG1_CRC_R(x)         (((x) & 0x1) << 4)
#define AD738X_CONFIG1_ALERTEN_MSK      BIT(3)
#define AD738X_CONFIG1_ALERTEN(x)       (((x) & 0x1) << 3)
#define AD738X_CONFIG1_RES_MSK          BIT(2)
#define AD738X_CONFIG1_RES(x)           (((x) & 0x1) << 2)
#define AD738X_CONFIG1_REFSEL_MSK       BIT(1)
#define AD738X_CONFIG1_REFSEL(x)        (((x) & 0x1) << 1)
#define AD738X_CONFIG1_PMODE_MSK        BIT(0)
#define AD738X_CONFIG1_PMODE(x)         (((x) & 0x1) << 0)

/*
 * AD738X_REG_CONFIG2
 */
#define AD738X_CONFIG2_SDO2_MSK         BIT(8)
#define AD738X_CONFIG2_SDO2(x)          (((x) & 0x1) << 8)
#define AD738X_CONFIG2_SDO4_MSK         GENMASK(9, 8)
#define AD738X_CONFIG2_SDO4(x)          (((x) & 0x3) << 8)
#define AD738X_CONFIG2_RESET_MSK        GENMASK(7, 0)
#define AD738X_CONFIG2_RESET(x)         (((x) & 0xFF) << 0)

/*
 * AD738X_REG_ALERT_LOW_TH
 */
#define AD738X_ALERT_LOW_MSK            GENMASK(11, 0)
#define AD738X_ALERT_LOW(x)             (((x) & 0xFFF) << 0)

/*
 * AD738X_REG_ALERT_HIGH_TH
 */
#define AD738X_ALERT_HIGH_MSK           GENMASK(11, 0)
#define AD738X_ALERT_HIGH(x)            (((x) & 0xFFF) << 0)

/* Write to register x */
#define AD738X_REG_WRITE(x)             ((1 << 7) | ((x & 0x7) << 4))
/* Read from register x */
#define AD738X_REG_READ(x)              ((x & 0x7) << 4)

/*****************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/
typedef enum {
	TWO_WIRE_MODE,
	ONE_WIRE_MODE
} ad738x_conv_mode;

typedef enum {
	NORMAL_OS_MODE,
	ROLLING_OS_MODE
} ad738x_os_mode;

typedef enum {
	OSR_DISABLED,
	OSR_X2,
	OSR_X4,
	OSR_X8,
	OSR_X16,
	OSR_X32,
} ad738x_os_ratio;

typedef enum {
	RES_16_BIT,
	RES_18_BIT
} ad738x_resolution;

typedef enum {
	SOFT_RESET,
	HARD_RESET
} ad738x_reset_type;

typedef enum {
	NORMAL_PWDM,
	FULL_PWDM
} ad738x_pwd_mode;

typedef enum {
	INT_REF,
	EXT_REF
} ad738x_ref_sel;

typedef struct {
	/* Device Settings */
	ad738x_conv_mode 	conv_mode;
	ad738x_resolution 	resolution;
} ad738x_dev;

typedef struct {
	/* Device Settings */
	ad738x_conv_mode	conv_mode;
	ad738x_ref_sel		ref_sel;
} ad738x_init_param;

#endif /* INC_ADC_H_ */
