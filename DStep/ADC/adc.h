#ifndef _MOTOR_ADC_H_
#define _MOTOR_ADC_H	_
#include "stm32f10x.h"

#define AD0			0
#define AD1			1
#define AD2			2
#define AD3			3
#define AD4			4
#define AD5			5
#define AD6			6
#define AD7			7
#define AD8			8
#define AD9			9
#define AD10		10
#define AD11		11
#define AD12		12
#define AD13		13
#define AD14		14
#define AD15		15


#ifdef __cplusplus
extern "C" {
#endif 
 
void Adc_Init(void);
u16  Get_Adc(u8 ch);  

int analogRead(u16 pin);

 
#ifdef __cplusplus
}
#endif	
	
#endif 
