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
void servo_motor_task(void);
void servo_test_task();

extern QueueHandle_t UartRxQueueHandle;
extern QueueHandle_t SW_Cmd_QueueHandle;
extern QueueHandle_t Servo_Cmd_QueueHandle;


#endif /* RTOS_TASK_H_ */
