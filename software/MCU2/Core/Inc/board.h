/*
 * board.h
 *
 *  Created on: May 1, 2020
 *      Author: grzegorz
 */

#ifndef INC_BOARD_H_
#define INC_BOARD_H_

#include "main.h"
#include "ADC.h"
#include "scpi/scpi.h"



enum e_scpi_calculate_format
{
	FORMAT1_REAL = 1,
	FORMAT1_MLIN,
	FORMAT1_CP,
	FORMAT1_CS,
	FORMAT1_LP,
	FORMAT1_LS,
	FORMAT2_IMAG,
	FORMAT2_PHAS,
	FORMAT2_D,
	FORMAT2_Q,
	FORMAT2_REAL,
	FORMAT2_LP,
	FORMAT2_RP,
	FORMAT2_INV
};


enum e_scpi_data_format
{
	DATA_ASCII = 1,
	DATA_REAL
};


enum e_scpi_correction_acquire
{
	CORRECT_OPEN = 1,
	CORRECT_SHORT,
	CORRECT_LOAD
};

enum e_scpi_correction_method
{
	CORRECT_REFL2 = 1,
	CORRECT_REFL3
};


struct _scpi_calculate_limit
{
	double value;
	scpi_bool_t state;
};

typedef struct _scpi_calculate_limit scpi_calculate_limit_t;

struct _scpi_calculate
{
	uint8_t format;
	uint8_t select;
	uint8_t math_state;
	scpi_calculate_limit_t low;
	scpi_calculate_limit_t high;
	uint8_t expression;
};

typedef struct _scpi_calculate scpi_calculate_t;

// *************************************************************************************

struct _scpi_sense_average
{
	uint32_t count;
	scpi_bool_t state;

};

typedef struct _scpi_sense_average scpi_sense_average_t;

struct _scpi_sense_fimp
{
	double aperture;
	uint8_t contact_verify;
	uint8_t auto_range;
	uint16_t range_value;
};

typedef struct _scpi_sense_fimp scpi_sense_fimp_t;

struct _scpi_sense
{

	scpi_sense_average_t average;
	scpi_sense_fimp_t fimp;
	uint8_t function;
};

typedef struct _scpi_sense scpi_sense_t;

// *************************************************************************************


struct _scpi_source_offset
{
	double value;
	scpi_bool_t state;
};

typedef struct _scpi_source_offset scpi_source_offset_t;

struct _scpi_source
{
	double frequency;
	double amplitude;
	scpi_source_offset_t offset;
};

typedef struct _scpi_source scpi_source_t;

// *************************************************************************************

struct _scpi_board
{
	scpi_calculate_t calculate[2];
	scpi_sense_t sense;
	scpi_source_t source;
	uint8_t data_format;

};

typedef struct _scpi_board scpi_board_t;

struct _board_struct
{
	ad738x_dev AD7380;
	scpi_board_t scpi;

}board;


#endif /* INC_BOARD_H_ */
