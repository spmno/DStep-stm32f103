#ifndef _MOTOR_PWM_H_
#define _MOTOR_PWM_H_

#include "../MotorTypeDef.h"

void PWM_Config(MOTROR_ControlType type);

void analogWrite(u16 pin, u8 value);
void analogFrequence(int frequence);

#endif

