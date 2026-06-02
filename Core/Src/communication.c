#include "communication.h"

#include "main.h"

static UART_HandleTypeDef* UART_Handler;
extern volatile uint8_t RX_buf[50];
extern volatile uint8_t RX_data;
static uint8_t RX_index;
extern volatile uint8_t Command_flag;


void UART_RX_TIM2_Init(UART_HandleTypeDef *huart){
	UART_Handler = huart;

}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(UART_Handler == huart){
		if(RX_data =="\n" | RX_data == "\r"){
			RX_buf[RX_index]="\0";
			RX_index = 0;
			Command_flag = 1;

		}

	RX_buf[RX_index]=RX_data;


	RX_index ++;




	}




}
