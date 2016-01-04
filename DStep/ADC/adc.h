#ifndef _MOTOR_ADC_H_
#define _MOTOR_ADC_H	_
#include "stm32f10x.h"

/*
#define ADC_CH0  0 //ͨ��0
#define ADC_CH1  1 //ͨ��1
#define ADC_CH2  2 //ͨ��2
#define ADC_CH3  3 //ͨ��3	   
*/
#ifdef __cplusplus
extern "C" {
#endif 
 
void Adc_Init(void);
u16  Get_Adc(u8 ch);  

int analogRead(int pin);
 
#ifdef __cplusplus
}
#endif	
	
#endif 
