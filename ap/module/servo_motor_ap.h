/*
 * servo_motor_ap.h
 *
 *  Created on: Jul 9, 2026
 *      Author: PC
 */

#ifndef MODULE_SERVO_MOTOR_AP_H_
#define MODULE_SERVO_MOTOR_AP_H_

#include "hw_motor.h"

typedef enum{
	Servo_Stop = 0,
	Servo_Holding
}Servo_State_Type_t;

typedef enum{
	SERVO_CMD_START,
	SERVO_CMD_SET_ANGLE,
	SERVO_CMD_STOP
}Servo_Cmd_Type_t;

typedef struct{
	Servo_Cmd_Type_t servo_cmd;
	uint8_t servo_cmd_angle;
}Servo_Cmd_HandleTypeDef;

typedef struct{
	Servo_Cmd_HandleTypeDef hservo_cmd;
	Servo_State_Type_t servo_state;
	uint8_t servo_angle;
}Servo_HandleTypeDef;

void set_servo_motor_cmd(Servo_HandleTypeDef* hservo,Servo_Cmd_Type_t cmd,uint8_t angle);
void servo_motor_process(Servo_HandleTypeDef* hservo);

#endif /* MODULE_SERVO_MOTOR_AP_H_ */
