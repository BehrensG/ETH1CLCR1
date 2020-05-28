/*
 * scpi_commands_misc.c
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */


#include <scpi_misc.h>


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
