/*
 * Uart_Cmd_task.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */
#include "rtos_task.h"

#include "uart_cmd.h"

typedef struct{
	uint8_t cmd;
	Uart_Cmd_ch target_ch;
}Uart_Cmd_type;



void uart_cmd_task(){
	static Uart_Cmd_type huart_cmd;
	uint8_t Uart_rx_data;

	huart_cmd.target_ch = SW_ch;

	for (;;){
		if(xQueueReceive(UartRxQueueHandle, &Uart_rx_data, portMAX_DELAY)==pdPASS)
		{
			if(uart_cmd_process(Uart_rx_data, &huart_cmd.cmd, huart_cmd.target_ch))
			{
				switch(huart_cmd.target_ch)
					{
						case SW_ch:
							//xQueueCRSend(xQueue, pvItemToQueue, xTicksToWait)
							break;

					}
			}
		}
	}
}
