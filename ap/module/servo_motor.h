/*
 * servo_motor.h
 *
 *  Created on: Jul 10, 2026
 *      Author: PC
 */

#ifndef MODULE_SERVO_MOTOR_H_
#define MODULE_SERVO_MOTOR_H_

#include "hw_motor.h"



typedef enum{
	SERVO_STOP = 0,
	SERVO_HOLDING
}Servo_StateTypeDef;

typedef enum{
	SERVO_CMD_STOP,
	SERVO_CMD_START,
	SERVO_CMD_SET_ANGLE,
}Servo_CmdTypeDef;

typedef struct{
	Servo_CmdTypeDef servo_cmd;
	uint8_t servo_cmd_angle;
}Servo_Cmd_HandleTypeDef;

typedef struct{
	Servo_Cmd_HandleTypeDef hservo_cmd;
	Servo_StateTypeDef servo_state;
	uint8_t servo_angle;
}Servo_HandleTypeDef;

void servo_motor_init(Servo_HandleTypeDef* hservo);
void set_servo_motor_cmd(Servo_HandleTypeDef* hservo,Servo_CmdTypeDef cmd,uint8_t angle);
void servo_motor_process(Servo_HandleTypeDef* hservo);



#endif /* MODULE_SERVO_MOTOR_H_ */
