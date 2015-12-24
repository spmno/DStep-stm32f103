#include <stm32f10x_conf.h>
#include "LED.h"

#define LED_PORT GPIO_Pin_8
//#define LED_PORT GPIO_Pin_0

void LED_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	GPIO_InitStructure.GPIO_Pin = LED_PORT;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, LED_PORT);
}

void LED_ON()
{
	GPIO_ResetBits(GPIOB, LED_PORT);
}

void LED_OFF()
{
	GPIO_SetBits(GPIOB, LED_PORT);
}
