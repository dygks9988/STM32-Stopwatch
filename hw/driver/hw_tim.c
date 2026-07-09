/*
 * tim.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */

#include "hw_tim.h"

volatile uint8_t ten_ms_flag = 0;

static TIM_HandleTypeDef* TIM_ch[HW_TIM_MAX_CH] = {
		&htim2,
		&htim3
};


void hw_TIM_start(uint8_t ch){
	if(ch >= HW_TIM_MAX_CH)return;
	HAL_TIM_Base_Start_IT(TIM_ch[ch]);
}

void hw_TIM_stop(uint8_t ch){
	if(ch >= HW_TIM_MAX_CH)return;
	HAL_TIM_Base_Stop_IT(TIM_ch[ch]);
}
void hw_TIM_pwm_start(uint8_t ch){
	if(ch >= HW_TIM_MAX_CH)return;
	HAL_TIM_PWM_Start(TIM_ch[ch], TIM_CHANNEL_1);
}
void hw_TIM_pwm_stop(uint8_t ch){
	if(ch >= HW_TIM_MAX_CH)return;
	HAL_TIM_PWM_Start(TIM_ch[ch], TIM_CHANNEL_1);
}
void hw_TIM_pwm_set_ccr(uint8_t ch,uint16_t ccr){
	__HAL_TIM_SET_COMPARE(TIM_ch[ch],TIM_CHANNEL_1,ccr);
}

//HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
//HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);


void hw_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM_ch[SW_TIM_CH]->Instance){
		ten_ms_flag++;
	}
}


