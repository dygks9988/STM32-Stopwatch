/*
 * communication.h
 *
 *  Created on: Jun 2, 2026
 *      Author: PC
 */

#ifndef SRC_COMMUNICATION_H_
#define SRC_COMMUNICATION_H_

#include "main.h"


extern volatile uint8_t RX_buf[50];
extern uint8_t RX_data;
extern volatile uint8_t Command_flag;

void UART_RX_flag();
void UART_RX_stopwatch_Init(UART_HandleTypeDef*);
void Command_execute();





#endif /* SRC_COMMUNICATION_H_ */
