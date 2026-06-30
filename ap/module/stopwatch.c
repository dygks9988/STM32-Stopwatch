/*
 * stopwatch.c
 *
 *  Created on: Jun 16, 2026
 *      Author: PC
 */

#include "stopwatch.h"

#define SEC_PER_TEN_MS 100
#define MIN_PER_SEC 60
#define HOUR_PER_MIN 60


typedef struct{
	SW_STATE state;
	uint8_t ten_ms_cnt;
	uint8_t sec_cnt;
	uint8_t min_cnt;
	uint8_t hour_cnt;
}stop_status;

stop_status sw;
static SW_CMD_TYPE_T SW_CMD;

void stopwatch_init(void){
	SW_CMD = SW_NONE;
	ten_ms_flag = 0;
	sw.state = IDLE;
	sw.ten_ms_cnt = 0;
	sw.sec_cnt = 0;
	sw.min_cnt = 0;
	sw.hour_cnt = 0;
}
void stopwatch_start(void){
	hw_TIM_start(SW_ch);
	sw.state = RUNNING;
}
void stopwatch_pause(void){
	hw_TIM_stop(SW_ch);
	sw.state = PAUSE;
}
void stopwatch_stop(void){
	hw_TIM_stop(SW_ch);
	stopwatch_init();
	sw.state = IDLE;
}
void stopwatch_set_cmd(SW_CMD_TYPE_T cmd){
	SW_CMD = cmd;
}


void stopwatch_update(void){
	sw.ten_ms_cnt++;
	if(sw.ten_ms_cnt >= SEC_PER_TEN_MS){
		sw.ten_ms_cnt = 0;
		sw.sec_cnt++;
		led_toggle(LED_CH_0);
		if(sw.sec_cnt >= MIN_PER_SEC){
			sw.sec_cnt = 0;
			sw.min_cnt++;
			if(sw.min_cnt >= HOUR_PER_MIN){
				sw.min_cnt = 0;
				sw.hour_cnt++;
			}
		}
	}

}
void stopwatch_process(void){
		switch(sw.state){
		case IDLE:
			if(SW_CMD == SW_START){
				stopwatch_start();
				SW_CMD = SW_NONE;
			}
			break;
		case RUNNING:
			if(SW_CMD == SW_PAUSE){
				stopwatch_pause();
				SW_CMD = SW_NONE;
			}
			if(ten_ms_flag != 0){
				stopwatch_update();
				ten_ms_flag = 0;
			}
			break;
		case PAUSE:
			if(SW_CMD == SW_STOP){
				stopwatch_stop();
				SW_CMD = SW_NONE;
			}
			if(SW_CMD == SW_START){
				stopwatch_start();
				SW_CMD = SW_NONE;
			}
			break;
	}
	//if(SW_CMD == SW_GET_TIME)
}


