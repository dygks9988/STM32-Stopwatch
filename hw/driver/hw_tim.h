/*
 * tim.h
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */

#ifndef DRIVER_HW_TIM_H_
#define DRIVER_HW_TIM_H_

#include "tim.h"

#define TIM_max_ch 1
#define SW_ch 0

volatile extern uint8_t ten_ms_flag;

void hw_TIM_start(uint8_t ch);
void hw_TIM_stop(uint8_t ch);

void hw_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* DRIVER_HW_TIM_H_ */
