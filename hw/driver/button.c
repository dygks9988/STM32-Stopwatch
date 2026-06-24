/*
 * button.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */


#include "button.h"

#define input_Max 1
#define bt0 GPIO_PIN_13


static volatile uint8_t bt0_pressed_falg = 0;

static uint16_t inputs[input_Max] = {bt0};

bool Bt_get_pressed(void){
	if(bt0_pressed_falg == 1){
		bt0_pressed_falg = 0;
		return true;
	}
	else
		return false;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == inputs[0]){
		bt0_pressed_falg = 1;
	}
}
