#ifndef _DSTEP_SERIAL_H_
#define _DSTEP_SERIAL_H_
#include "stm32f10x_conf.h"
/*
class Serial
{
	static void begin(int baudrate);
	static char read();
	static void write(char ch);
	static void print(char* string);
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static unsigned short rxPin;
	static unsigned short txPin;
};
*/

//uart5 tx pc12 rx pd2
class Serial1 //: Serial
{
	static void begin(int baudrate);
	static u8 read();
	static void write(char ch);
	static void print(char* string);
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* rxGpioType;
	static GPIO_TypeDef* txGpioType;
	static USART_TypeDef* uartType;
};

//uart4 tx pc10 rx pc11
class Serial2 //: Serial
{
	static void begin(int baudrate);
	static u8 read();
	static void write(char ch);
	static void print(char* string);
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* rxGpioType;
	static GPIO_TypeDef* txGpioType;
	static USART_TypeDef* uartType;
};

#endif
