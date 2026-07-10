/*
 * servo_motor.c
 *
 *  Created on: Jul 9, 2026
 *      Author: PC
 */
#include "servo_motor.h"

void servo_motor_init(Servo_HandleTypeDef* hservo){
	if(hservo == NULL);
	hservo->servo_angle = 0;
	hservo->servo_state = SERVO_STOP;
}


void set_servo_motor_cmd(Servo_HandleTypeDef* hservo,Servo_CmdTypeDef cmd,uint8_t angle){
	if(hservo == NULL);
	hservo->hservo_cmd.servo_cmd = cmd;
	hservo->hservo_cmd.servo_cmd_angle = angle;
}


void servo_motor_process(Servo_HandleTypeDef* hservo){
	if(hservo == NULL);

	switch(hservo->servo_state){
		case SERVO_STOP:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_START){
				hw_motor_start(SERVO_MOTOR_TIM_CH);
				hservo->servo_state = SERVO_HOLDING;
			}
			break;
		case SERVO_HOLDING:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_STOP){
				hw_motor_stop(SERVO_MOTOR_TIM_CH);
				hservo->servo_state = SERVO_STOP;
			}
			break;
	}
	if (hservo->hservo_cmd.servo_cmd == SERVO_CMD_SET_ANGLE){
		hw_motor_set_angle(SERVO_MOTOR_TIM_CH,hservo->hservo_cmd.servo_cmd_angle);
		hservo->servo_angle = hservo->hservo_cmd.servo_cmd_angle;
	}
}
