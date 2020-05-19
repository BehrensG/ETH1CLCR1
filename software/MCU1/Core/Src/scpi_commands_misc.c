/*
 * scpi_commands_misc.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scpi_commands_misc.h"


scpi_choice_def_t format_data_select[] =
{
 		{"ASCii", 1},
 		{"REAL", 2},
 		SCPI_CHOICE_LIST_END
};

scpi_result_t SCPI_FormatData(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_FormatDataQ(scpi_t * context)
{

	return SCPI_RES_OK;
}
