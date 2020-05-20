/*
 * scpi_commands_sense.h
 *
 *  Created on: Mar 14, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_COMMANDS_SENSE_H_
#define INC_SCPI_COMMANDS_SENSE_H_

#include "scpi/scpi.h"


scpi_result_t SCPI_SenseAverageCount(scpi_t * context);
scpi_result_t SCPI_SenseAverageCountQ(scpi_t * context);
scpi_result_t SCPI_SenseAverageState(scpi_t * context);
scpi_result_t SCPI_SenseAverageStateQ(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCkitStandard(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCkitStandardQ(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCollectAquire(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCollectAquireQ(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCollectMethod(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionCollectMethodQ(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionDataQ(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionState(scpi_t * context);
scpi_result_t SCPI_SenseCorrectionStateQ(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceAperture(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceApertureQ(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceContactVerify(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceContactVerifyQ(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceRangeAuto(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceRangeAutoQ(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceRange(scpi_t * context);
scpi_result_t SCPI_SenseFimpedanceRangeQ(scpi_t * context);
scpi_result_t SCPI_SenseFunctionOn(scpi_t * context);
scpi_result_t SCPI_SenseFunctionOnQ(scpi_t * context);

#endif /* INC_SCPI_COMMANDS_SENSE_H_ */
