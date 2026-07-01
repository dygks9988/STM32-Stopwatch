/*
 * Uart_Cmd_task.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */
#include "FreeRTOS.h"
#include "task.h"

#include "uart_cmd.h"

void uart_cmd_task(){
	uint8_t cmd_state;
	uint8_t byte_data[20] = {'S','W','_','S','T','O','P','\r'};

	for(int i=0; i < 8; i++){
	uart_cmd_process(byte_data[i],&cmd_state,SW_ch);
	}
	while(1){
	vTaskDelay(10);
	}
}
