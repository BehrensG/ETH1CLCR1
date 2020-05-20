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


/*
 * FORMAt[:DATA] {ASCii|REAL}
 *
 * @INFO:
 * Sets the data format for transferring numeric and array information.
 *
 * @PARAMETERS:
 *
 *			ASCii :	sets the data transfer format to ASCII.
 *			REAL :	Sets the data transfer format to IEEE 754 floating point numbers of the specified length of 64-bit.
 *
 */

scpi_result_t SCPI_FormatData(scpi_t * context)
{

	return SCPI_RES_OK;
}

/*
 * FORMAt[:DATA]?
 *
 * @INFO:
 * Query data format. Response is ASC or REAL.
 *
 */

scpi_result_t SCPI_FormatDataQ(scpi_t * context)
{

	return SCPI_RES_OK;
}
