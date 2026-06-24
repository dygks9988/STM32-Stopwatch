/*
 * led.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */



#include "led.h"


typedef struct{
	GPIO_TypeDef* port;
	uint16_t pin_num;
	bool led_state;
}leds;


static leds led_tdl[LEDS_SIZE] = {
	{LD2_GPIO_Port,LD2_Pin,GPIO_PIN_RESET},
};


void led_init(uint8_t ch){
	if(ch >= LEDS_SIZE)return;

	HAL_GPIO_WritePin(led_tdl[ch].port, led_tdl[ch].pin_num, GPIO_PIN_RESET);
	led_tdl[ch].led_state = GPIO_PIN_RESET;
}


void led_toggle(uint8_t ch){
	if(ch >= LEDS_SIZE)return;

	HAL_GPIO_TogglePin(led_tdl[ch].port, led_tdl[ch].pin_num);
	led_tdl[ch].led_state = !led_tdl[ch].led_state;
}


void led_on(uint8_t ch){
	if(ch >= LEDS_SIZE)return;

	HAL_GPIO_WritePin(led_tdl[ch].port, led_tdl[ch].pin_num, GPIO_PIN_SET);
	led_tdl[ch].led_state = GPIO_PIN_SET;
}


void led_off(uint8_t ch){
	if(ch >= LEDS_SIZE)return;

	HAL_GPIO_WritePin(led_tdl[ch].port, led_tdl[ch].pin_num, GPIO_PIN_RESET);
	led_tdl[ch].led_state = GPIO_PIN_RESET;
}


