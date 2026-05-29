
#include "Stopwatch.h"
#include "stm32f4xx_hal.h"



volatile uint8_t ten_ms_cnt;
volatile uint8_t sec_cnt;
volatile uint8_t sec_flag;
volatile uint8_t min_cnt;
volatile uint8_t min_flag;
volatile uint8_t hour_cnt;
volatile uint8_t hour_flag;


void stopwatch_Init(){
ten_ms_cnt = 0;

sec_flag = 0;
sec_cnt = 0;

min_cnt = 0;
min_flag =0;

hour_cnt = 0;
hour_flag = 0;
}

void stopwatch_counter(){
	ten_ms_cnt++;
	if (ten_ms_cnt >=100)    //1초
	{
		ten_ms_cnt =0;
		sec_flag++;
		sec_cnt++;

		if(sec_cnt >= 60) // 60초
		{
			sec_cnt = 0;
			min_flag++;
			min_cnt++;

			if(min_cnt >= 60) // 60분
			{
				min_cnt = 0;
				hour_flag++;
				hour_cnt++;
			}
		}
	}
}
