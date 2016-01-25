#include <stm32f10x_conf.h>
#include "GPIO.h"

#ifdef __cplusplus
extern "C" {
#endif

static unsigned short pin_table[15] = {
	GPIO_Pin_15,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5,
	GPIO_Pin_6,
	GPIO_Pin_7,
	GPIO_Pin_8,
	GPIO_Pin_9,
	GPIO_Pin_10,
	GPIO_Pin_9,
	GPIO_Pin_8,
	GPIO_Pin_9,
	GPIO_Pin_8,
	GPIO_Pin_7,
	GPIO_Pin_6
};

static GPIO_TypeDef* port_table[15] = {
	GPIOA,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOC,
	GPIOC,
	GPIOC,
	GPIOC
};

static u8 port_source_table[15] = {
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC
};

static u8 pin_source_table[15] = {
	GPIO_PinSource15,
	GPIO_PinSource3,
	GPIO_PinSource4,
	GPIO_PinSource5,
	GPIO_PinSource6,
	GPIO_PinSource7,
	GPIO_PinSource8,
	GPIO_PinSource9,
	GPIO_PinSource10,
	GPIO_PinSource9,
	GPIO_PinSource8,
	GPIO_PinSource9,
	GPIO_PinSource8,
	GPIO_PinSource7,
	GPIO_PinSource6
};


// pin port, mode input, output, input_pullup
void pinMode(int pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	if (port_table[pin] == GPIOA) {
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
	} else if(port_table[pin] == GPIOB){
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	} else {
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );
	}
	
	GPIO_InitStructure.GPIO_Pin = pin_table[pin];
	GPIO_InitStructure.GPIO_Mode = mode;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port_table[pin], &GPIO_InitStructure);
	
	if (mode == INPUT) {
		GPIO_EXTILineConfig(port_source_table[pin], pin_source_table[pin]);
	}
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

#ifdef __cplusplus
}
#endif

