#include <stm32f10x_conf.h>
#include "motor.h"
#include "PWMMotor.h"
#include "GPIOMotor.h"

#ifdef __cplusplus
extern "C"{
#endif
	
static MotorBase* current_motor;	

void Motor_Init(MOTROR_ControlType type)
{
	if (type == PWM_CONTROL) {
		current_motor = new PWMMotor();
	} else {
		current_motor = new GPIOMotor();
	}
}


void Motor_T1_Low()
{
	current_motor->Motor_T1_Low();
}

void Motor_T1_PWM()
{
	current_motor->Motor_T1_PWM();
}

void Motor_T2_High()
{
	current_motor->Motor_T2_High();
}

void Motor_T2_Low()
{
	current_motor->Motor_T2_Low();
}

void Motor_T3_Low()
{
	current_motor->Motor_T3_Low();
}

void Motor_T3_PWM()
{
	current_motor->Motor_T3_PWM();
}

void Motor_T4_High()
{
	current_motor->Motor_T4_High();
}


void Motor_T4_Low()
{
	current_motor->Motor_T4_Low();
}

void Motor_T5_Low()
{
	current_motor->Motor_T5_Low();
}

void Motor_T5_PWM()
{
	current_motor->Motor_T5_PWM();
}

void Motor_T6_High()
{
	current_motor->Motor_T6_High();
}

void Motor_T6_Low()
{
	current_motor->Motor_T6_Low();
}
	
#ifdef __cplusplus
}
#endif
