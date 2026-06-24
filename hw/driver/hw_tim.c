/*
 * tim.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */

#include "hw_tim.h"

volatile uint8_t ten_ms_flag = 0;

static TIM_HandleTypeDef* TIM_ch[TIM_max_ch] = {
		&htim2
};


void hw_TIM_start(uint8_t ch){
	if(ch >= TIM_max_ch)return;
	HAL_TIM_Base_Start_IT(TIM_ch[ch]);
}

void hw_TIM_stop(uint8_t ch){
	if(ch >= TIM_max_ch)return;
	HAL_TIM_Base_Stop_IT(TIM_ch[ch]);
}


//HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
//HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);


void hw_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM_ch[SW_ch]->Instance){
		ten_ms_flag++;
	}
}


