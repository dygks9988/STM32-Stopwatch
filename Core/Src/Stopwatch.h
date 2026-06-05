/*
 * Stopwatch.h
 *
 *  Created on: May 29, 2026
 *      Author: PC
 */


#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "main.h"


extern volatile uint8_t sw_flag;

typedef struct{
	volatile uint8_t ten_ms_cnt;

	volatile uint8_t sec_cnt;
	volatile uint8_t sec_flag;

	volatile uint8_t min_cnt;
	volatile uint8_t min_flag;

	volatile uint8_t hour_cnt;
	volatile uint8_t hour_flag;
}Stop_watchTypedef;


void stopwatch_Init(Stop_watchTypedef* sw);
void stopwatch_counter(Stop_watchTypedef* sw);


#endif /* STOPWATCH_H_ */


