/*
 * led.h
 *
 *  Created on: Jun 17, 2026
 *      Author: PC
 */

#ifndef DRIVERS_LED_H_
#define DRIVERS_LED_H_

#include "gpio.h"

#define LEDS_SIZE 1

#define LED_CH_0 0



void led_init(uint8_t ch);
void led_toggle(uint8_t ch);
void led_on(uint8_t ch);
void led_off(uint8_t ch);

#endif /* DRIVERS_LED_H_ */
