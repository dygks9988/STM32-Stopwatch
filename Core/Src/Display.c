

#include "Display.h"
#include "stm32f4xx_hal.h"
#include "Stopwatch.h"




void LED_replace()
{
	GPIOB->ODR = sec_cnt;
}


void SEG_replace()
{


}
