/*
 * Stopwatch.h
 *
 *  Created on: May 29, 2026
 *      Author: PC
 */


#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "main.h"

extern volatile uint8_t ten_ms_cnt;

extern volatile uint8_t sec_cnt;
extern volatile uint8_t sec_flag;

extern volatile uint8_t min_cnt;
extern volatile uint8_t min_flag;

extern volatile uint8_t hour_cnt;
extern volatile uint8_t hour_flag;

extern TIM_HandleTypeDef* TIM_Handle;

void stopwatch_Init(TIM_HandleTypeDef *htim);
void stopwatch_counter();


#endif /* STOPWATCH_H_ */


