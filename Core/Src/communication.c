#include "communication.h"
#include <string.h>
#include "main.h"
#include "Stopwatch.h"
#include "tim.h"
#include "usart.h"

static UART_HandleTypeDef* UART_Handler;
volatile uint8_t RX_buf[50];
volatile uint8_t Command_flag;
uint8_t RX_data;

volatile static uint8_t RX_index;
static char TX_BUF[50];

volatile HAL_StatusTypeDef tx_status;

#define TX_GET_TIME_PRINT "\r\n%02d:%02d:%02d\r\n"


void UART_RX_stopwatch_Init(){

	Command_flag = 0;
	RX_data = 0;

}

void Command_execute(Stop_watchTypedef* sw){
	if(strncmp((const char *)RX_buf,"stop",4) == 0){
		HAL_TIM_Base_Stop_IT(&htim1);
	}
	if(strncmp((const char *)RX_buf,"start",5) == 0){
		HAL_TIM_Base_Start_IT(&htim1);
	}
	Command_flag = 0;
	if(strncmp((const char *)RX_buf,"get_time",8) == 0){
		    sprintf(TX_BUF,TX_GET_TIME_PRINT,sw->hour_cnt,sw->min_cnt,sw->sec_cnt);
		    tx_status =	HAL_UART_Transmit(&huart2,(const uint8_t*)TX_BUF,strlen(TX_BUF),100);
		}
	Command_flag = 0;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(&huart2 == huart){
		if((RX_data =='\n') | (RX_data == '\r')){
			RX_buf[RX_index]='\0';
			RX_index = 0;
			Command_flag = 1;

		}
		else{
	RX_buf[RX_index++]=RX_data;


		}




	}



	HAL_UART_Receive_IT(&huart2, &RX_data, 1);
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART2){

        HAL_UART_Receive_IT(huart, (uint8_t *)&RX_data, 1);
    }
}
