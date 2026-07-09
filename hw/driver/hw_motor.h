/*
 * hw_motor.h
 *
 *  Created on: Jul 8, 2026
 *      Author: PC
 */

#ifndef DRIVER_HW_MOTOR_H_
#define DRIVER_HW_MOTOR_H_

#include "hw_tim.h"
#define SERVO_MOTOR_TIM_CH 1


void hw_motor_init(uint8_t ch);
void hw_motor_start(uint8_t ch);
void hw_motor_set_angle(uint8_t ch,uint8_t angle);
void hw_motor_stop(uint8_t ch);

#endif /* DRIVER_HW_MOTOR_H_ */
