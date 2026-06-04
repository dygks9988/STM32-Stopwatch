#include "communication.h"
#include <string.h>
#include "main.h"
#include "Stopwatch.h"

static UART_HandleTypeDef* UART_Handler;
volatile uint8_t RX_data;
volatile uint8_t RX_buf[50];
volatile uint8_t Command_flag;

volatile static uint8_t RX_index;




void UART_RX_stopwatch_Init(UART_HandleTypeDef* huart){
	UART_Handler = huart;
	Command_flag = 0;
	RX_data = 0;

}

void Command_execute(){
	if(strncmp((const char *)RX_buf,"stop",4) == 0){
		HAL_TIM_Base_Stop_IT(TIM_Handle);
	}
	if(strncmp((const char *)RX_buf,"start",5) == 0){
		HAL_TIM_Base_Start_IT(TIM_Handle);
	}
	Command_flag = 0;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(UART_Handler == huart){
		if((RX_data =='\n') | (RX_data == '\r')){
			RX_buf[RX_index]='\0';
			RX_index = 0;
			Command_flag = 1;

		}
		else{
	RX_buf[RX_index++]=RX_data;


		}




	}



	HAL_UART_Receive_IT(UART_Handler, &RX_data, 1);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART2){

        HAL_UART_Receive_IT(huart, (uint8_t *)&RX_data, 1);
    }
}
