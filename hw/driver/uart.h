/*
 * uart.h
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */

#ifndef DRIVER_UART_H_
#define DRIVER_UART_H_

#include "usart.h"

#define UART_CMD_CH 0


void uart_init();
void uart_tx(uint8_t ch, uint8_t* pData, uint16_t len);
void uart_rx_ready(uint8_t ch);


#endif /* DRIVER_UART_H_ */
