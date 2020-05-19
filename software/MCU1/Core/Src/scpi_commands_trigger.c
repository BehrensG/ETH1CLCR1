/*
 * scpi_commands_trigger.c
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scpi_commands_trigger.h"


 scpi_choice_def_t trigger_source_select[] =
 {
 		{"IMMediate", 1},
 		{"EXTernal", 2},
 		{"BUS", 3},
 		SCPI_CHOICE_LIST_END
 };


scpi_result_t SCPI_TriggerDelay(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_TriggerDelayQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_TriggerImmediate(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_choice_def_t trigger_source_unit[] =
{
    {"IMM", 0},
    {"EXT", 1},
	{"BUS", 2},
    SCPI_CHOICE_LIST_END
};

scpi_result_t SCPI_TriggerSource(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_TriggerSourceQ(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_choice_def_t trigger_output_unit[] =
{
    {"OFF", 0},
    {"ON", 1},
    SCPI_CHOICE_LIST_END
};

scpi_result_t SCPI_TriggerOutput(scpi_t * context)
{

	return SCPI_RES_OK;
}

scpi_result_t SCPI_TriggerOutputQ(scpi_t * context)
{

	return SCPI_RES_OK;
}
