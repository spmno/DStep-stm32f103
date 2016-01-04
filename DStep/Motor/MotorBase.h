#ifndef _MOTOR_BASE_H_
#define _MOTOR_BASE_H_

class MotorBase
{
public:
	virtual void Motor_T1_Low() = 0;
	virtual void Motor_T1_PWM() = 0;

	virtual void Motor_T2_High() = 0;
	virtual void Motor_T2_Low() = 0;

	virtual void Motor_T3_Low() = 0;
	virtual void Motor_T3_PWM() = 0;

	virtual void Motor_T4_High() = 0;
	virtual void Motor_T4_Low() = 0;

	virtual void Motor_T5_Low() = 0;
	virtual void Motor_T5_PWM() = 0;

	virtual void Motor_T6_High() = 0;
	virtual void Motor_T6_Low() = 0;
};

#endif

