/*
 * scpi_commands_calculate.h
 *
 *  Created on: May 16, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_CALCULATE_H_
#define INC_SCPI_CALCULATE_H_

#include <scpi/scpi.h>

scpi_result_t SCPI_CalculateFormat(scpi_t * context);
scpi_result_t SCPI_CalculateFormatQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitClear(scpi_t * context);
scpi_result_t SCPI_CalculateLimitFailQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitLowerData(scpi_t * context);
scpi_result_t SCPI_CalculateLimitLowerDataQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitLowerState(scpi_t * context);
scpi_result_t SCPI_CalculateLimitLowerStateQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitState(scpi_t * context);
scpi_result_t SCPI_CalculateLimitStateQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitUpperData(scpi_t * context);
scpi_result_t SCPI_CalculateLimitUpperDataQ(scpi_t * context);
scpi_result_t SCPI_CalculateLimitUpperState(scpi_t * context);
scpi_result_t SCPI_CalculateLimitUpperStateQ(scpi_t * context);
scpi_result_t SCPI_CalculateMathExpressionCatalogQ(scpi_t * context);
scpi_result_t SCPI_CalculateMathExpressionName(scpi_t * context);
scpi_result_t SCPI_CalculateMathExpressionNameQ(scpi_t * context);
scpi_result_t SCPI_CalculateMathState(scpi_t * context);
scpi_result_t SCPI_CalculateMathStateQ(scpi_t * context);

#endif /* INC_SCPI_CALCULATE_H_ */
