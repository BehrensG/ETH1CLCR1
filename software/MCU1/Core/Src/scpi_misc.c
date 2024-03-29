/*
 * scpi_commands_misc.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scpi_misc.h"
#include "spi4.h"

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int32_t paramFORMAT;

	if(!SCPI_ParamChoice(context, format_data_select, &paramFORMAT, TRUE))
	{
		return SCPI_RES_ERR;
	}

	snprintf(tx_data, SPI4_BUFFER, "FORM:DATA %d", paramFORMAT);
	SPI4_Transmit(&tx_data,1000);

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
	int8_t tx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int8_t rx_data[SPI4_BUFFER] ={[0 ... SPI4_BUFFER-1] = '\0'};
	int32_t readout_size = 0;

	snprintf(tx_data, SPI4_BUFFER, "FORM:DATA?");
	SPI4_Transmit(&tx_data,1000);

	SPI4_Receive(&rx_data, &readout_size, 1000);
	SCPI_ResultCharacters(context, rx_data, readout_size);

	return SCPI_RES_OK;
}
