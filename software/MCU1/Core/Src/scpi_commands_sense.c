/*
 * scpi_commands_sense.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

 scpi_choice_def_t sense_function_select[] =
 {
 		{"FIMPedance", 1},
 		{"FADMittance", 2},
 		SCPI_CHOICE_LIST_END
 };

#include "scpi_commands_sense.h"

scpi_result_t SCPI_SenseAverageCount(scpi_t * context)
{
    return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseAverageCountQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseAverageState(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseAverageStateQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseFunction(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseFunctionQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseMode(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseNominalValue(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseNominalValueQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseNominalState(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_SenseNominalStateQ(scpi_t * context)
{

	return SCPI_RES_OK;
}


