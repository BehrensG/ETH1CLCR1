/*
 * scpi_commands_calculate.c
 *
 *  Created on: May 16, 2020
 *      Author: grzegorz
 */

#include "scpi_commands_calculate.h"

scpi_choice_def_t calc1_format_select[] =
{
		{"REAL", 1},
		{"MLINear", 2},
		{"CP", 3},
		{"CS", 4},
		{"LP", 5},
		{"LS", 6},
		SCPI_CHOICE_LIST_END
};

scpi_choice_def_t calc2_format_select[] =
{
		{"IMAGinary", 1},
		{"PHASe", 2},
		{"D", 3},
		{"Q", 4},
		{"REAL", 5},
		{"LP", 6},
		{"RP", 7},
		{"INV", 8},
		SCPI_CHOICE_LIST_END
};
