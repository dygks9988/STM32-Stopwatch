/*
 * smart_blind.c
 *
 *  Created on: Jul 16, 2026
 *      Author: PC
 */

#include "smart_blind.h"

#define BLIND_OPEN_ANGLE  0
#define BLIND_HALF_ANGLE  45
#define BLIND_CLOSE_ANGLE 90



void blind_init(Blind_StateTypeDef* blind_state){
	if(blind_state == NULL)return;
	*blind_state = BLIND_NONE;
}

/*
 * blind_process
 * blind_task에서 받은 명령을 수행한다.
 *
 *
 */

bool blind_process(
Blind_StateTypeDef* blind_state,
Blind_CmdTypeDef blind_cmd,
Servo_Cmd_PacketTypeDef* pservo_cmd
){
	if(blind_state == NULL || pservo_cmd == NULL)return false;

	switch (blind_cmd) {
		case BLIND_CMD_NONE:
			return false;
	    case BLIND_CMD_OPEN:
	        if (*blind_state == BLIND_OPEN)return false;

	        pservo_cmd->servo_cmd = SERVO_CMD_SET_ANGLE;
	        pservo_cmd->servo_cmd_angle = BLIND_OPEN_ANGLE;
	        *blind_state = BLIND_OPEN;
	        return true;

	    case BLIND_CMD_HALF:
	        if (*blind_state == BLIND_HALF)return false;

	        pservo_cmd->servo_cmd = SERVO_CMD_SET_ANGLE;
	        pservo_cmd->servo_cmd_angle = BLIND_HALF_ANGLE;
	        *blind_state = BLIND_HALF;
	        return true;

	    case BLIND_CMD_CLOSE:
	        if (*blind_state == BLIND_CLOSE)return false;

	        pservo_cmd->servo_cmd = SERVO_CMD_SET_ANGLE;
	        pservo_cmd->servo_cmd_angle = BLIND_CLOSE_ANGLE;
	        *blind_state = BLIND_CLOSE;
	        return true;

	    default:
	        return false;
	    }
}

