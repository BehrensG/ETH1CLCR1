/*
 * scpi_commands_calibration.h
 *
 *  Created on: May 23, 2020
 *      Author: grzegorz
 */

#ifndef INC_SCPI_CALIBRATION_H_
#define INC_SCPI_CALIBRATION_H_

#include <scpi/scpi.h>

scpi_result_t SCPI_CalibrationADCQ(scpi_t * context);
scpi_result_t SCPI_CalibrationAllQ(scpi_t * context);
scpi_result_t SCPI_CalibrationSecureState(scpi_t * context);
scpi_result_t SCPI_CalibrationSecureStateQ(scpi_t * context);
scpi_result_t SCPI_CalibrationStore(scpi_t * context);
scpi_result_t SCPI_CalibrationString(scpi_t * context);
scpi_result_t SCPI_CalibrationStringQ(scpi_t * context);
scpi_result_t SCPI_CalibrationValue(scpi_t * context);
scpi_result_t SCPI_CalibrationValueQ(scpi_t * context);

#endif /* INC_SCPI_CALIBRATION_H_ */
