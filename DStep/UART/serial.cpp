#include "serial.h"

unsigned short Serial1::rxPin = GPIO_Pin_12;
unsigned short Serial1::txPin = GPIO_Pin_2;
GPIO_TypeDef* Serial1::rxGpioType = GPIOC;
GPIO_TypeDef* Serial1::txGpioType = GPIOD;
USART_TypeDef* Serial1::uartType = UART5;

unsigned short Serial2::rxPin = GPIO_Pin_11;
unsigned short Serial2::txPin = GPIO_Pin_10;
GPIO_TypeDef* Serial2::rxGpioType = GPIOC;
GPIO_TypeDef* Serial2::txGpioType = GPIOC;
USART_TypeDef* Serial2::uartType = UART4;

void Serial1::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =  txPin ;	/* USART5 Tx (PD.2)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(txGpioType, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =  rxPin ;	/* USART5 Rx (PC.12)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(rxGpioType, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE); 
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

u8 Serial1::read()
{
	return USART_ReceiveData(uartType);
}

void Serial1::write(char ch)
{
	USART_SendData(uartType, (uint8_t) ch);
	while(USART_GetFlagStatus(uartType, USART_FLAG_TC) == RESET){}  
}


void Serial1::print(char* string)
{
	while (0 != *string) {    
		USART_SendData(uartType, (uint8_t)*string);  
    string++;    
  }   
}

void Serial2::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =     txPin ;	/* USART3 Tx (PB.10)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(txGpioType, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =     rxPin ;	/* USART3 Rx (PB.11)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(rxGpioType, &GPIO_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE); 
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

u8 Serial2::read()
{
	return USART_ReceiveData(uartType);
}

void Serial2::write(char ch)
{
	USART_SendData(uartType, (uint8_t) ch);
	while(USART_GetFlagStatus(uartType, USART_FLAG_TC) == RESET){}  
}


void Serial2::print(char* string)
{
	while (0 != *string) {    
		USART_SendData(uartType, (uint8_t)*string);  
    string++;    
  }    
}

