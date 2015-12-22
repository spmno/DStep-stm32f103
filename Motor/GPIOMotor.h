#ifndef _GPIO_MOTOR_H_
#define _GPIO_MOTOR_H_

#include "MotorBase.h"

class GPIOMotor : public MotorBase
{
public:
	virtual void Motor_T1_Low();
	virtual void Motor_T1_PWM();

	virtual void Motor_T2_High();
	virtual void Motor_T2_Low();

	virtual void Motor_T3_Low();
	virtual void Motor_T3_PWM();

	virtual void Motor_T4_High();
	virtual void Motor_T4_Low();

	virtual void Motor_T5_Low();
	virtual void Motor_T5_PWM();

	virtual void Motor_T6_High();
	virtual void Motor_T6_Low();
	
};

#endif
