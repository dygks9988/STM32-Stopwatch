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



void uart_tx(uint8_t ch);

void uart_rx(uint8_t ch);


#endif /* DRIVER_UART_H_ */
