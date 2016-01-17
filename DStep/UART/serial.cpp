#include "serial.h"

unsigned short Serial1::rxPin;
unsigned short Serial1::txPin;
GPIO_TypeDef* Serial1::gpioType;
USART_TypeDef* Serial1::uartType;

unsigned short Serial2::rxPin;
unsigned short Serial2::txPin;
GPIO_TypeDef* Serial2::gpioType;
USART_TypeDef* Serial2::uartType;

void Serial1::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =     txPin ;	/* USART3 Tx (PB.10)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(gpioType, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =     rxPin ;	/* USART3 Rx (PB.11)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(gpioType, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
    
  USART_Init(uartType, &USART_InitStructure);
  USART_ITConfig(uartType, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
  USART_Cmd(uartType, ENABLE);
}

char Serial1::read()
{
	
}

void Serial1::write(char ch)
{
	
}


void Serial1::print(char* string)
{
	
}

void Serial2::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =     txPin ;	/* USART3 Tx (PB.10)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(gpioType, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =     rxPin ;	/* USART3 Rx (PB.11)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(gpioType, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = baudrate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
    
  USART_Init(uartType, &USART_InitStructure);
  USART_ITConfig(uartType, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
  USART_Cmd(uartType, ENABLE);
}

char Serial2::read()
{
	
}

void Serial2::write(char ch)
{
	
}


void Serial2::print(char* string)
{
	
}

