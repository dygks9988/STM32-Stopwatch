
#include "Stopwatch.h"
#include "main.h"

volatile uint8_t ten_ms_cnt;
volatile uint8_t sec_cnt;
volatile uint8_t sec_flag;
volatile uint8_t min_cnt;
volatile uint8_t min_flag;
volatile uint8_t hour_cnt;
volatile uint8_t hour_flag;

#define TICK_PER_SEC 100
#define SEC_PER_MIN 60
#define MIN_PER_HOUR 60

static TIM_HandleTypeDef* TIM_Handle;

void stopwatch_Init(TIM_HandleTypeDef *htim){
ten_ms_cnt = 0;

sec_flag = 0;
sec_cnt = 0;

min_cnt = 0;
min_flag =0;

hour_cnt = 0;
hour_flag = 0;

TIM_Handle = htim;
}

void stopwatch_counter(){
	ten_ms_cnt++;
	if (ten_ms_cnt >=TICK_PER_SEC)
	{
		ten_ms_cnt =0;
		sec_flag++; //타이머 콜백에서 FALG만 띄움 (메인루프 최적화)
		sec_cnt++;

		if(sec_cnt >= SEC_PER_MIN)
		{
			sec_cnt = 0;
			min_flag++;
			min_cnt++;

			if(min_cnt >= MIN_PER_HOUR)
			{
				min_cnt = 0;
				hour_flag++;
				hour_cnt++;
			}
		}
	}
}



HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (TIM_Handle == htim)
	stopwatch_counter();
}

