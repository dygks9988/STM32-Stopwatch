/*
 * servo_test.c
 *
 *  Created on: Jul 15, 2026
 *      Author: PC
 */


#include "rtos_task.h"
#include "servo_motor.h"

void servo_test_task(void){
	Servo_HandleTypeDef hservo1;
	Servo_Cmd_PacketTypeDef pservo;

	servo_motor_init(&hservo1, SERVO_MOTOR_TIM_CH);

	pservo.servo_cmd = SERVO_CMD_START;
	pservo.servo_cmd_angle = 0;

	set_servo_motor_cmd(&hservo1, &pservo);

	servo_motor_process(&hservo1);

	vTaskDelay(1000);

	pservo.servo_cmd = SERVO_CMD_SET_ANGLE;
	pservo.servo_cmd_angle = 90;

	set_servo_motor_cmd(&hservo1, &pservo);

	servo_motor_process(&hservo1);

	vTaskDelay(1000);

	pservo.servo_cmd = SERVO_CMD_SET_ANGLE;
	pservo.servo_cmd_angle = 180;

	set_servo_motor_cmd(&hservo1, &pservo);

	servo_motor_process(&hservo1);

	vTaskDelay(1000);

	pservo.servo_cmd = SERVO_CMD_SET_ANGLE;
	pservo.servo_cmd_angle = 360;

	set_servo_motor_cmd(&hservo1, &pservo);

	servo_motor_process(&hservo1);

	vTaskDelay(1000);

	pservo.servo_cmd = SERVO_CMD_STOP;
	pservo.servo_cmd_angle = 0;

	set_servo_motor_cmd(&hservo1, &pservo);
	servo_motor_process(&hservo1);

	for(;;){
		vTaskDelay(10);
	}


}

