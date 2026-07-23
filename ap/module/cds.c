/*
 * cds.c
 *
 *  Created on: Jul 23, 2026
 *      Author: PC
 */



#include "hw_adc.h"
#include "cds.h"

#define CDS1_ADCID 0
#define CDS_TIMEOUT_MS 1
#define CDS_MAX 1
#define ADC_READ_TIMES 5


typedef struct{
	uint8_t cds_adc_id;
}Cds_HandleTypeDef;

Cds_HandleTypeDef cds_tbl[] = {
		{0}
};

/*
 * cds_process
 * 센서가 연결 되어 있는 ADC 채널의 값을 읽어온다.
 * 센서의 상태가 변경 되면 true를 반환한다.
 */

bool cds_process(CdsState_TypeDef* cds_state,uint8_t ch){
	uint32_t cds_value;
	uint32_t cds_avg_value;


	if(cds_state == NULL)return false;
	for(int i = 0; i < ADC_READ_TIMES; i++){
		if(adc_read_polling(cds_tbl[ch].cds_adc_id,CDS_TIMEOUT_MS,&(cds_value)) == false){
			return false;
		}
		cds_avg_value += cds_value;
	}
	cds_avg_value /= ADC_READ_TIMES;

	if(cds_avg_value >= 3000){
		 if(*cds_state == CDS_DARK)return false;
		*cds_state = CDS_DARK;
		return true;
	}
	else if(cds_avg_value >= 1500){
		if(*cds_state == CDS_MIDDLE_LIGHT)return false;
		*cds_state = CDS_MIDDLE_LIGHT;
		return true;
	}
	else if(*cds_state != CDS_LIGHT) {
		*cds_state = CDS_LIGHT;
		return true;
	}
	return false;
}
