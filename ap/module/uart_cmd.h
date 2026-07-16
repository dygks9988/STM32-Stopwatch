/*
 * uart_cmd.h
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#ifndef MODULE_UART_CMD_H_
#define MODULE_UART_CMD_H_

#include "uart.h"
#include "stopwatch.h"
#include "servo_motor.h"
#include "smart_blind.h"

#define MAX_CMD_CH 1


typedef enum{
	NONE_CMD_CH,
	SW_CMD_CH,
	SERVO_CMD_CH,
	BLIND_CMD_CH
}Uart_Cmd_ch; //

typedef struct{
	Uart_Cmd_ch target_ch;
	uint8_t cmd;
	uint8_t value;
}Uart_Cmd_type;

bool uart_cmd_process(uint8_t data,Uart_Cmd_type* huart_cmd);

#endif /* MODULE_UART_CMD_H_ */
