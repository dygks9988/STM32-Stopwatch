/*
 * hw.c
 *
 *  Created on: Jun 16, 2026
 *      Author: PC
 */

#include "hw.h"

void hw_init(void){
	led_init(LED_CH_0);
	uart_init(UART_CMD_CH);
	hw_motor_init(SERVO_MOTOR_TIM_CH);
}
