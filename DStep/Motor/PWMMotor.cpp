#include "stm32f10x_conf.h"
#include "PWMMotor.h"

void PWMMotor::Motor_T1_Low()
{
	TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
}

void PWMMotor::Motor_T1_PWM()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);
	TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
}

void PWMMotor::Motor_T2_High()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_ForcedAction_Active);
	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);
}

void PWMMotor::Motor_T2_Low()
{
	TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);
}

void PWMMotor::Motor_T3_Low()
{
	TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
}

void PWMMotor::Motor_T3_PWM()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1);
	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
	TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);

}

void PWMMotor::Motor_T4_High()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_ForcedAction_Active);
	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
}

void PWMMotor::Motor_T4_Low()
{
	TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
}

void PWMMotor::Motor_T5_Low()
{
	TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
}

void PWMMotor::Motor_T5_PWM()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);
	TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
}

void PWMMotor::Motor_T6_High()
{
	TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_ForcedAction_Active);
	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);
}

void PWMMotor::Motor_T6_Low()
{
	TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);
}

