/*
 * uart.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */


#include "uart.h"

#define UART_MAX 1

static UART_HandleTypeDef* uart_tbl[UART_MAX] = {
		&huart2
};

static uint8_t pData;

void uart_tx(uint8_t ch,uint8_t* pData){
	if (ch >= UART_MAX)return;
	HAL_UART_Transmit(uart_tbl[ch], pData, strlen(pData), 50);
}

void uart_rx(uint8_t ch){
	if (ch >= UART_MAX)return;
	HAL_UART_Receive_IT(uart_tbl[ch],&pData,sizeof(pData));
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == uart_tbl[UART_CMD_CH]->Instance){


		uart_rx(UART_CMD_CH);
	}

}

