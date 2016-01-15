#include "stm32f10x_conf.h"
#include "pwm.h"
#include "../PinDefine.h"


void timeModeConfig(TIM_TypeDef* timer, u8 channel, u8 value) 
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	short CCR1_Val = (value*1.0/255)*1000;
	
	TIM_TimeBaseStructure.TIM_Period = 999;
	//预分频
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	//分频
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//计数模式
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(timer, &TIM_TimeBaseStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	//设置跳转值
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	//当定时器小于这个值为高电平
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	
	if (channel == 1) {
		TIM_OC1Init(timer, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(timer, TIM_OCPreload_Enable);
	} else if (channel == 2) {
		TIM_OC2Init(timer, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(timer, TIM_OCPreload_Enable);		
	} else if (channel == 3) {
		TIM_OC3Init(timer, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(timer, TIM_OCPreload_Enable);		
	} else {
		TIM_OC4Init(timer, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(timer, TIM_OCPreload_Enable);		
	}
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
}


void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the TIM1 Interrupt */
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM17_IRQn;
#else
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_IRQn;
#endif

  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure); 

}

void analogWrite(u16 pin, u8 value)
{
	switch(pin) {
		case PWM0:
			timeModeConfig(TIM1, 3, value);
			break;
		case PWM1:
			timeModeConfig(TIM1, 2, value);
			break;
		case PWM2:
			timeModeConfig(TIM1, 1, value);
			break;
		case PWM3:
			timeModeConfig(TIM8, 4, value);
			break;
		case PWM4:
			timeModeConfig(TIM8, 3, value);
			break;
		case PWM5:
			timeModeConfig(TIM8, 2, value);
			break;
		case PWM6:
			timeModeConfig(TIM8, 1, value);
			break;
	}
}

void analogFrequence(int frequence)
{
	
}

