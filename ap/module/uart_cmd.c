/*
 * uart_cmd.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */


#include "uart_cmd.h"


#define CMD_IDX_MAX 30
#define STOPWATCH_TARGET_CMP_LEN 3
#define SERVO_TARGET_CMP_LEN 6
#define BLIND_TARGET_CMP_LEN 6

bool uart_cmd_process(uint8_t data,Uart_Cmd_type* huart_cmd){
	if(huart_cmd == NULL)return false;

	static uint8_t cmd_buf[CMD_IDX_MAX];
	static uint8_t cmd_idx = 0;

	if(data == '\r' || data == '\n')// \n 또는 \n 수신 시 하나의 명령어가 완성 된 것으로 판단
	{
		if(cmd_idx == 0)return false;

		cmd_buf[cmd_idx] = '\0';
		cmd_idx = 0;
		huart_cmd->target_ch = NONE_CMD_CH;

		if(strncmp((char *)cmd_buf, "SW_",STOPWATCH_TARGET_CMP_LEN) == 0) // 타겟 지정
		{
			huart_cmd->target_ch = SW_CMD_CH;
		}

		if(strncmp((char *)cmd_buf, "SERVO_",SERVO_TARGET_CMP_LEN) == 0)
		{
			huart_cmd->target_ch = SERVO_CMD_CH;
		}
		if(strncmp((char *)cmd_buf, "BLIND_",BLIND_TARGET_CMP_LEN) == 0)
		{
			huart_cmd->target_ch = BLIND_CMD_CH;
		}

		switch(huart_cmd->target_ch)
			{
			case NONE_CMD_CH:
				return false;
			case SW_CMD_CH:
				if(strcmp((char *)cmd_buf, "SW_START") == 0)
				{
					huart_cmd->cmd = SW_START;
					break;
				}
				else if(strcmp((char *)cmd_buf, "SW_PAUSE") == 0){
					huart_cmd->cmd = SW_PAUSE;
					break;
				}
				else if(strcmp((char *)cmd_buf, "SW_STOP") == 0){
					huart_cmd->cmd = SW_STOP;
					break;
				}
				else if(strcmp((char *)cmd_buf, "SW_GET_TIME") == 0){
					huart_cmd->cmd = SW_GET_TIME;
					break;
				}
				else{
					huart_cmd->target_ch = NONE_CMD_CH;
					return false; // 명령어가 테이블에 있지 않으면 false
				}
			case SERVO_CMD_CH:
				return false;
			case BLIND_CMD_CH:
				if(strcmp((char *)cmd_buf, "BLIND_CLOSE") == 0)
				{
				huart_cmd->cmd = BLIND_CMD_CLOSE;
				break;
				}
				else if(strcmp((char *)cmd_buf, "BLIND_HALF") == 0){
					huart_cmd->cmd = BLIND_CMD_HALF;
					break;
				}
				else if(strcmp((char *)cmd_buf, "BLIND_OPEN") == 0){
					huart_cmd->cmd = BLIND_CMD_OPEN;
					break;
				}
				else{
					huart_cmd->target_ch = NONE_CMD_CH;
					return false; // 명령어가 테이블에 있지 않으면 false
				}
			}

	}
	else{
		if(cmd_idx >= CMD_IDX_MAX -1)cmd_idx = 0;
		cmd_buf[cmd_idx++] = data;
		return false;
	}
	return true;  // 명령어가 완성 되고 테이블에 일치하는 명령어가 있으면 true
}
