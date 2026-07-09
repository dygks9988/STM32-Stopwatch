/*
 * uart_cmd.h
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#ifndef MODULE_UART_CMD_H_
#define MODULE_UART_CMD_H_

#include "uart.h"
#define MAX_CMD_CH 1


typedef enum{
	None_Cmd_ch,
	SW_Cmd_ch
}Uart_Cmd_ch; //마지막 ch 아래에 추가

typedef struct{
	uint8_t cmd;
	Uart_Cmd_ch target_ch;
}Uart_Cmd_type;

bool uart_cmd_process(uint8_t data,Uart_Cmd_type* huart_cmd);

#endif /* MODULE_UART_CMD_H_ */
