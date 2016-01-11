#include <stm32f10x_conf.h>
#include "GPIO.h"

#define LED_PORT GPIO_Pin_8
//#define LED_PORT GPIO_Pin_0

static unsigned short pin_table[8] = {
	GPIO_Pin_15,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5,
	GPIO_Pin_6,
	GPIO_Pin_7,
	GPIO_Pin_8,
	GPIO_Pin_9
};

static GPIO_TypeDef* port_table[8] = {
	GPIOA,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB
};

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

void LED_OFF(void);

// pin port, mode input, output, input_pullup
void pinMode(int pin, int mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	if (port_table[pin] == GPIOA) {
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
	} else {
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	}
	
	GPIO_InitStructure.GPIO_Pin = pin_table[pin];
	GPIO_InitStructure.GPIO_Mode = mode;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port_table[pin], &GPIO_InitStructure);
}

void digitalWrite(u16 pin, u8 value)
{
	if (value == LOW) {
		GPIO_ResetBits(port_table[pin], pin_table[pin]);
	} else {
		GPIO_SetBits(port_table[pin], pin_table[pin]);
	}
}

u8 digitalRead(u16 pin) 
{
	return GPIO_ReadInputDataBit(port_table[pin], pin_table[pin]);
}

