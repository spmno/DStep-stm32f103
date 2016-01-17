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

class Serial1 //: Serial
{
	static void begin(int baudrate);
	static char read();
	static void write(char ch);
	static void print(char* string);
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* gpioType;
	static USART_TypeDef* uartType;
};

class Serial2 //: Serial
{
	static void begin(int baudrate);
	static char read();
	static void write(char ch);
	static void print(char* string);
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* gpioType;
	static USART_TypeDef* uartType;
};

#endif
