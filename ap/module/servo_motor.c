/*
 * servo_motor.c
 *
 *  Created on: Jul 9, 2026
 *      Author: PC
 */
#include "servo_motor.h"

void servo_motor_init(Servo_HandleTypeDef* hservo,uint8_t tim_ch){
	if(hservo == NULL)return;

	hservo->servo_angle = 0;
	hservo->servo_state = SERVO_STOP;
	hservo->servo_tim_ch = tim_ch;
}


void set_servo_motor_cmd(Servo_HandleTypeDef* hservo,Servo_Cmd_PacketTypeDef* pservo_cmd){
	if(hservo == NULL || pservo_cmd == NULL)return;

	hservo->hservo_cmd.servo_cmd = pservo_cmd->servo_cmd;
	hservo->hservo_cmd.servo_cmd_angle = pservo_cmd->servo_cmd_angle;
}

/*
 * servo_motor_process
 * - Queue에서 받은 Command를 1회성 이벤트로 처리한다.
 * - Queuerecive를 트리거로 실행되는 process이기에 별도의 Command 초기화 로직을 수행하지 않는다.
 *
 */
void servo_motor_process(Servo_HandleTypeDef* hservo){
	if(hservo == NULL)return;

	switch(hservo->servo_state){
		case SERVO_STOP:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_START){
				hw_motor_start(hservo->servo_tim_ch);
				hservo->servo_state = SERVO_HOLDING;
				hw_motor_set_angle(hservo->servo_tim_ch,hservo->hservo_cmd.servo_cmd_angle);
				hservo->servo_angle = hservo->hservo_cmd.servo_cmd_angle;
			}
			break;
		case SERVO_HOLDING:
			if(hservo->hservo_cmd.servo_cmd == SERVO_CMD_STOP){
				hw_motor_stop(hservo->servo_tim_ch);
				hservo->servo_state = SERVO_STOP;
			}
			break;
	}
	if (hservo->hservo_cmd.servo_cmd == SERVO_CMD_SET_ANGLE){
		hw_motor_set_angle(hservo->servo_tim_ch,hservo->hservo_cmd.servo_cmd_angle);
		hservo->servo_angle = hservo->hservo_cmd.servo_cmd_angle;
	}
}
