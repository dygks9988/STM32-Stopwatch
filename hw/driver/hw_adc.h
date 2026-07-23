/*
 * hw_adc.h
 *
 *  Created on: Jul 22, 2026
 *      Author: PC
 */

#ifndef DRIVER_HW_ADC_H_
#define DRIVER_HW_ADC_H_

#include "adc.h"

#define GL5528_ADC_CH 0


bool adc_read_polling(uint8_t adc_id,uint32_t timeout_ms,uint32_t* adc_value);


#endif /* DRIVER_HW_ADC_H_ */
