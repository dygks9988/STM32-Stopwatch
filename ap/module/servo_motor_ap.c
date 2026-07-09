/*
 * motor.c
 *
 *  Created on: Jul 9, 2026
 *      Author: PC
 */
#include "servo_motor_ap.h"


void set_servo_motor_cmd(Servo_HandleTypeDef* hservo,Servo_Cmd_Type_t cmd,uint8_t angle){
	hservo->hservo_cmd.servo_cmd = cmd;
	hservo->hservo_cmd.servo_cmd_angle = angle;
}
void servo_motor_process(Servo_HandleTypeDef* hservo){
	switch(hservo->servo_state){
		case Servo_Stop:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_START){
				hw_motor_start(SERVO_MOTOR_TIM_CH);
				hservo->servo_state = Servo_Holding;
			}
			break;
		case Servo_Holding:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_STOP){
				hw_motor_stop(SERVO_MOTOR_TIM_CH);
				hservo->servo_state = Servo_Stop;
			}

			break;
	}
	if (hservo->hservo_cmd.servo_cmd == SERVO_CMD_SET_ANGLE){
		hw_motor_set_angle(SERVO_MOTOR_TIM_CH,hservo->hservo_cmd.servo_cmd_angle);
		hservo->servo_angle = hservo->hservo_cmd.servo_cmd_angle;
	}
}
