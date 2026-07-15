/*
 * Uart_Cmd_task.c
 *
 *  Created on: Jun 30, 2026
 *      Author: PC
 */
#include "rtos_task.h"
#include "uart_cmd.h"




void uart_cmd_task(){
	Uart_Cmd_type huart_cmd;
	uint8_t uart_rx_data;
	Servo_Cmd_PacketTypeDef pservo;

	for (;;){
		if(xQueueReceive(UartRxQueueHandle, &uart_rx_data, portMAX_DELAY)==pdPASS)
		{
			if(uart_cmd_process(uart_rx_data, &huart_cmd))
			{
				switch(huart_cmd.target_ch)
					{
					case NONE_CMD_CH:
						break;
					case SW_CMD_CH:
						xQueueSend(SW_Cmd_QueueHandle,&huart_cmd.cmd,(TickType_t )10);
						break;
					case SERVO_CMD_CH:
						pservo.servo_cmd = huart_cmd.cmd;
						pservo.servo_cmd_angle = huart_cmd.value;
						xQueueSend(Servo_Cmd_QueueHandle,&pservo,(TickType_t )10);
						break;

					}
			}
		}
	}
}
