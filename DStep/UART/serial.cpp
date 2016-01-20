#include "serial.h"

unsigned short DStepSerial0::txPin = GPIO_Pin_12;
unsigned short DStepSerial0::rxPin = GPIO_Pin_2;
GPIO_TypeDef*  DStepSerial0::txGpioType = GPIOC;
GPIO_TypeDef*  DStepSerial0::rxGpioType = GPIOD;
USART_TypeDef* DStepSerial0::uartType = UART5;

unsigned short DStepSerial1::rxPin = GPIO_Pin_11;
unsigned short DStepSerial1::txPin = GPIO_Pin_10;
GPIO_TypeDef* DStepSerial1::rxGpioType = GPIOC;
GPIO_TypeDef* DStepSerial1::txGpioType = GPIOC;
USART_TypeDef* DStepSerial1::uartType = UART4;

void DStepSerial0::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12 ;	/* UART5 Tx (PC.12)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =  rxPin ;	/* UART5 Rx (PD.2)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(rxGpioType, &GPIO_InitStructure);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE); 
	USART_InitStructure.USART_BaudRate = baudrate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
    
  USART_Init(UART5, &USART_InitStructure);
  USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
  USART_Cmd(UART5, ENABLE);
}

u8 DStepSerial0::read()
{
	return USART_ReceiveData(uartType);
}

void DStepSerial0::write(char ch)
{
	USART_SendData(UART5, (uint8_t) ch);
	while(USART_GetFlagStatus(UART5, USART_FLAG_TC) == RESET){}  
}


void DStepSerial0::print(char* string)
{
	while (0 != *string) {    
		USART_SendData(uartType, (uint8_t)*string);  
    string++;    
  }   
}

void DStepSerial1::begin(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStructure;	
	USART_InitTypeDef USART_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin =     txPin ;	/* USART4 Tx (PC.10)*/							
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(txGpioType, &GPIO_InitStructure);
	/******************************************************************/
	GPIO_InitStructure.GPIO_Pin =     rxPin ;	/* USART4 Rx (PC.11)*/								
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(rxGpioType, &GPIO_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
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
	
	NVIC_InitTypeDef NVIC_InitStructure;  
   
  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);  
   
  /* Enable the USART4 Interrupt */  
  NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;  
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
  NVIC_Init(&NVIC_InitStructure); 
}

void UART4_IRQHandler(void)  
{
	u8 data = USART_ReceiveData(UART4);
}

u8 DStepSerial1::read()
{
	return USART_ReceiveData(uartType);
}

void DStepSerial1::write(char ch)
{
	USART_SendData(uartType, (uint8_t) ch);
	while(USART_GetFlagStatus(uartType, USART_FLAG_TC) == RESET){}  
}


void DStepSerial1::print(char* string)
{
	while (0 != *string) {    
		USART_SendData(uartType, (uint8_t)*string);  
    string++;    
  }    
}

