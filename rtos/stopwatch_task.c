/*
 * stopwatch_task.c
 *
 *  Created on: Jun 24, 2026
 *      Author: PC
 */



#include "FreeRTOS.h"
#include "task.h"

#include "stopwatch.h"

const TickType_t Sw_Task_Tick = 10;




void stopwatch_task(){
	stopwatch_init();
	SW_CMD_TYPE_T CMD = SW_START;

	TickType_t xLastWakeTime = xTaskGetTickCount();

	for(;;){
		stopwatch_set_cmd(CMD);
		CMD = SW_NONE;
		stopwatch_process();
		vTaskDelayUntil(&xLastWakeTime, Sw_Task_Tick);
	}
}

