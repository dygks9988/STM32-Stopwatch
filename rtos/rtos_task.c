/*
 * rtos_task.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#include "rtos_task.h"
#include "main.h"

#define UART_RX_QUEUE_LENGTH  30
#define SW_CMD_QUEUE_LENGTH 10

QueueHandle_t UartRxQueueHandle;
QueueHandle_t SW_Cmd_QueueHandle;


void rtos_init(void)
{
	UartRxQueueHandle = xQueueCreate(UART_RX_QUEUE_LENGTH,sizeof(uint8_t));
	if(UartRxQueueHandle == NULL){
		Error_Handler();
	}
	SW_Cmd_QueueHandle = xQueueCreate(SW_CMD_QUEUE_LENGTH,sizeof(uint8_t));
	if(SW_Cmd_QueueHandle == NULL){
			Error_Handler();
		}

}
