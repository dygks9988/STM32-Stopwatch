/*
 * uart_cmd.h
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */

#ifndef MODULE_UART_CMD_H_
#define MODULE_UART_CMD_H_

#include "uart.h"

typedef enum{
	SW_ch = 0,
	Max_Cmd_ch
}Uart_Cmd_ch; //마지막 ch 아래에 추가하는 방식



bool uart_cmd_process(uint8_t data,uint8_t* cmd,uint8_t cmd_ch);

#endif /* MODULE_UART_CMD_H_ */
