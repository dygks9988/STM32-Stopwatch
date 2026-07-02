/*
 * rtos_task.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#include "rtos_task.h"
#include "main.h"

#define UART_RX_QUEUE_LENGTH  30

QueueHandle_t UartRxQueueHandle;

void rtos_init(void)
{
	UartRxQueueHandle = xQueueCreate(UART_RX_QUEUE_LENGTH,sizeof(uint8_t));
}
