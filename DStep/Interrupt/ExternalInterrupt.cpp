#include "stm32f10x_conf.h"
#include "ExternalInterrupt.h"

static void NVIC_Configuration(void)
{

	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;

	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}

void KEY_GPIO_Config(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE);

	NVIC_Configuration();

	/* EXTI line gpio config(PE5) */

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;  

	GPIO_Init(GPIOC, &GPIO_InitStructure);


	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource15);

	EXTI_InitStructure.EXTI_Line = EXTI_Line15;

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);

}

void EXTI3_IRQHandler(void)
{
	
}

void EXTI4_IRQHandler(void)
{
	
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line5) != RESET) {
		EXTI_ClearFlag(EXTI_Line5);
		EXTI_ClearITPendingBit(EXTI_Line5);
	} else if (EXTI_GetITStatus(EXTI_Line6) != RESET) {
		EXTI_ClearFlag(EXTI_Line6);
		EXTI_ClearITPendingBit(EXTI_Line6);
	} else if (EXTI_GetITStatus(EXTI_Line7) != RESET) {
		EXTI_ClearFlag(EXTI_Line7);
		EXTI_ClearITPendingBit(EXTI_Line7);		
	} else if (EXTI_GetITStatus(EXTI_Line8) != RESET) {
		EXTI_ClearFlag(EXTI_Line8);
		EXTI_ClearITPendingBit(EXTI_Line8);	
	} else if (EXTI_GetITStatus(EXTI_Line9) != RESET) {
		EXTI_ClearFlag(EXTI_Line9);
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line10) != RESET) {
		EXTI_ClearFlag(EXTI_Line10);
		EXTI_ClearITPendingBit(EXTI_Line10);
	} else if (EXTI_GetITStatus(EXTI_Line11) != RESET) {
		EXTI_ClearFlag(EXTI_Line11);
		EXTI_ClearITPendingBit(EXTI_Line11);
	} else if (EXTI_GetITStatus(EXTI_Line12) != RESET) {
		EXTI_ClearFlag(EXTI_Line12);
		EXTI_ClearITPendingBit(EXTI_Line12);		
	} else if (EXTI_GetITStatus(EXTI_Line13) != RESET) {
		EXTI_ClearFlag(EXTI_Line13);
		EXTI_ClearITPendingBit(EXTI_Line13);	
	} else if (EXTI_GetITStatus(EXTI_Line14) != RESET) {
		EXTI_ClearFlag(EXTI_Line14);
		EXTI_ClearITPendingBit(EXTI_Line14);
	}if (EXTI_GetITStatus(EXTI_Line15) != RESET) {
		EXTI_ClearFlag(EXTI_Line15);
		EXTI_ClearITPendingBit(EXTI_Line15);
	}
}

