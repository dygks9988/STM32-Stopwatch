/*
 * rtos_task.h
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#ifndef RTOS_TASK_H_
#define RTOS_TASK_H_

#include "FreeRTOS.h"
#include "queue.h"

void rtos_init(void);

void stopwatch_task(void);
void uart_cmd_task(void);

extern QueueHandle_t UartRxQueueHandle;

#endif /* RTOS_TASK_H_ */
