/*
 * smart_blind_task.c
 *
 *  Created on: Jul 16, 2026
 *      Author: PC
 */

#include "rtos_task.h"
#include "smart_blind.h"

void smart_blind_task(void){
	Blind_StateTypeDef blind_state;
	Blind_CmdTypeDef blind_cmd;
	Servo_Cmd_PacketTypeDef pservo_cmd;

	blind_init(&blind_state);

	for(;;){
		if(xQueueReceive(SmartBlind_Cmd_QueueHandle, &blind_cmd, portMAX_DELAY)==pdPASS){
			if(blind_process(&blind_state,blind_cmd,&pservo_cmd) == true){
				xQueueSend(Servo_Cmd_QueueHandle,&pservo_cmd,(TickType_t )10);
			};
		}
	}
}
