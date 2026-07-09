/*
 * stopwatch_task.c
 *
 *  Created on: Jun 24, 2026
 *      Author: PC
 */



#include "rtos_task.h"
#include "stopwatch.h"

const TickType_t Sw_Task_Delay_Tick = 10;




void stopwatch_task(){
	stopwatch_init();
	Sw_Cmd_Type_t Cmd = SW_NONE;
	TickType_t xLastWakeTime = xTaskGetTickCount();

	for(;;){
		if(xQueueReceive(SW_Cmd_QueueHandle,&Cmd,0)== pdPASS){
			stopwatch_set_cmd(Cmd);
		}
		stopwatch_process();
		vTaskDelayUntil(&xLastWakeTime, Sw_Task_Delay_Tick);
	}
}

