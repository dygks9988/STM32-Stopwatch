/*
 * motor_task.c
 *
 *  Created on: Jul 9, 2026
 *      Author: PC
 */
#include "rtos_task.h"
#include "servo_motor.h"

void servo_motor_task(void){
	Servo_Cmd_PacketTypeDef pservo_cmd;
	Servo_HandleTypeDef hservo1;

	servo_motor_init(&hservo1,SERVO_MOTOR_TIM_CH);
	for(;;){
		if(xQueueReceive(Servo_Cmd_QueueHandle, &pservo_cmd, portMAX_DELAY)==pdPASS){
			set_servo_motor_cmd(&hservo1,&pservo_cmd);
			servo_motor_process(&hservo1);
		}
	}
}
