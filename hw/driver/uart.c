/*
 * uart.c
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */


#include "uart.h"

char tx_data[20] = "hello_world";
uint16_t buf[255];
uint16_t q_index[max_q] = {};

void uart_tx(uint8_t ch){
	sprintf(buf,);
	HAL_UART_Transmit(&huart2, pData, Size, Timeout);

}

void uart_rx(uint8_t ch);


HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart,
		const uint8_t *pData, uint16_t Size, uint32_t Timeout);



HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
