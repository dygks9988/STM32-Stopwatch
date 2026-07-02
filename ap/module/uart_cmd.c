/*
 * uart_cmd.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */


#include "uart_cmd.h"
#include "stopwatch.h"

#define CMD_IDX_MAX 30


bool uart_cmd_process(uint8_t data,uint8_t* cmd,uint8_t cmd_ch){
	if(cmd == NULL || MAX_CMD_CH <= cmd_ch)return false;

	static uint8_t cmd_buf[CMD_IDX_MAX];
	static uint8_t cmd_idx = 0;

	if(data == '\r' || data == '\n')// \n 또는 \n 수신 시 하나의 명령어가 완성 된 것으로 판단
	{
		if(cmd_idx == 0)return false;

		cmd_buf[cmd_idx] = '\0';
		cmd_idx = 0;

		switch(cmd_ch){
			case SW_ch:
				if(strcmp((char *)cmd_buf, "SW_START") == 0)
					*cmd = SW_START;
				else if(strcmp((char *)cmd_buf, "SW_PAUSE") == 0)
					*cmd = SW_PAUSE;
				else if(strcmp((char *)cmd_buf, "SW_STOP") == 0)
					*cmd = SW_STOP;
				else if(strcmp((char *)cmd_buf, "SW_GET_TIME") == 0)
					*cmd = SW_GET_TIME;
				else
					return false; // 명령어가 테이블에 있지 않으면 false
				break;
			}

	}
	else{
		if(cmd_idx >= CMD_IDX_MAX -1)cmd_idx = 0;
		cmd_buf[cmd_idx++] = data;
		return false;
	}
	return true;  // 명령어가 완성 되고 테이블에 일치하는 명령어가 있으면 true
}
