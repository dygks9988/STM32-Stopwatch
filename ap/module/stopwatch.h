/*
 * stopwatch.h
 *
 *  Created on: Jun 16, 2026
 *      Author: PC
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include "hw.h"




enum SW_STATE{
	IDLE = 1,
	RUNNING,
	PAUSE
};

void stopwatch_init(void);
void stopwatch_main(void);
void stopwatch_start(void);
void stopwatch_stop(void);
void stopwatch_pause(void);


#endif /* STOPWATCH_H_ */
