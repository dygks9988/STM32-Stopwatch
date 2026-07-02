/*
 * uart.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */


#include "uart.h"
#include "rtos_task.h"

#define UART_MAX 1

static HAL_StatusTypeDef rx_state;

static UART_HandleTypeDef* uart_tbl[UART_MAX] = {
		&huart2
};


static uint8_t rx_pData;

void uart_init(){
	uart_rx_ready(UART_CMD_CH);
}

void uart_tx(uint8_t ch, uint8_t* pData, uint16_t len){
	if (ch >= UART_MAX)return;
	HAL_UART_Transmit(uart_tbl[ch], pData, len, 50);
}

void uart_rx_ready(uint8_t ch){
	if (ch >= UART_MAX)return;
	rx_state = HAL_UART_Receive_IT(uart_tbl[ch],&rx_pData,sizeof(rx_pData));
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == uart_tbl[UART_CMD_CH]->Instance){
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;

		xQueueSendFromISR(UartRxQueueHandle, &rx_pData, &xHigherPriorityTaskWoken);

		uart_rx_ready(UART_CMD_CH);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}

