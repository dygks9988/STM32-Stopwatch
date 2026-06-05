
#include "Stopwatch.h"
#include "main.h"
#include "tim.h"


volatile uint8_t sw_flag;

#define TICK_PER_SEC 100
#define SEC_PER_MIN 60
#define MIN_PER_HOUR 60


void stopwatch_Init(Stop_watchTypedef* sw){
sw->ten_ms_cnt = 0;

sw->sec_flag = 0;
sw->sec_cnt = 0;

sw->min_cnt = 0;
sw->min_flag =0;

sw->hour_cnt = 0;
sw->hour_flag = 0;

}

void stopwatch_counter(Stop_watchTypedef* sw){
	sw->ten_ms_cnt++;
	if ((sw->ten_ms_cnt) >= TICK_PER_SEC)
	{
		sw->ten_ms_cnt = 0;
		sw->sec_flag++; // 타이머 콜백에서 FALG만 띄움 (메인루프 최적화)
		sw->sec_cnt++;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

		if((sw->sec_cnt) >= SEC_PER_MIN)
		{
			sw->sec_cnt = 0;
			sw->min_flag++;
			sw->min_cnt++;

			if(sw->min_cnt >= MIN_PER_HOUR)
			{
				sw->min_cnt = 0;
				sw->hour_flag++;
				sw->hour_cnt++;
			}
		}
	}
}



HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (&htim1 == htim)
	sw_flag = 1;
}

