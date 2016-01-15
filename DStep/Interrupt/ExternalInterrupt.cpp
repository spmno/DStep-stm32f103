#include "stm32f10x_conf.h"
#include "ExternalInterrupt.h"
#include "../PinDefine.h"
#include <map>

//using namespace std;

//static map<u8, void (*)(void)> interruptFunction;

static void (*interruptFunctionContainer[8])() ;

u32 interruptLine[8] = {
	EXTI_Line15,
	EXTI_Line3,
	EXTI_Line4,
	EXTI_Line5,
	EXTI_Line6,
	EXTI_Line7,
	EXTI_Line8,
	EXTI_Line9
};

static void NVIC_Configuration(u8 pin)
{

	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	switch(pin) {
		case IO0:
			NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
		case IO1:
			NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;
			break;
		case IO2:
			NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
			break;
		case IO3:
		case IO4:
		case IO5:
		case IO6:
		case IO7:
			NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
			break;
	}

	

	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);

}


void EXTI3_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line3);
	EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI4_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line4);
	EXTI_ClearITPendingBit(EXTI_Line4);
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
		if (interruptFunctionContainer[0] != 0) {
			interruptFunctionContainer[0]();
		}
	}
}

void attachInterrupt(u8 pin, void (*userFunction)(void), int mode)
{
	interruptFunctionContainer[pin] = userFunction;
	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_Configuration(pin);

	EXTI_InitStructure.EXTI_Line = interruptLine[pin];

	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 

	EXTI_InitStructure.EXTI_LineCmd = ENABLE;

	EXTI_Init(&EXTI_InitStructure);
}
