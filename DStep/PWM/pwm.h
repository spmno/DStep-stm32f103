#ifndef _MOTOR_PWM_H_
#define _MOTOR_PWM_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "../MotorTypeDef.h"

void timeMode(u16 pin);
void timeModeConfig(TIM_TypeDef* timer, u8 channel, u8 value);

void analogWrite(u16 pin, u8 value);
void analogFrequence(int frequence);

#ifdef __cplusplus
}
#endif

	
#endif

