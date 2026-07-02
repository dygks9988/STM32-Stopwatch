/*
 * uart_cmd_process_test.c
 *
 *  Created on: Jul 2, 2026
 *      Author: PC
 */

void uart_cmd_process_test(){
	uint8_t cmd_state;
	uint8_t byte_data[20] = {'S','W','_','S','T','O','P','\r'};

	for(int i=0; i < 8; i++){
	uart_cmd_process(byte_data[i],&cmd_state,SW_ch);
	}
}
