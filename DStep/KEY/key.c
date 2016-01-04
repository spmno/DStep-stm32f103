#include "stm32f10x_conf.h"
#include "key.h"
#include "../can/can.h"

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

void EXTI15_10_IRQHandler(void)
{
	CAN_Test_Function1();
	EXTI_ClearFlag(EXTI_Line15);
}

