#ifndef _DSTEP_SERIAL_H_
#define _DSTEP_SERIAL_H_
#include "stm32f10x_conf.h"

#ifdef __cplusplus
extern "C" {
#endif
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

#define Serial0	DStepSerial0::getInstance()
#define Serial1 DStepSerial1::getInstance()

//uart5 tx pc12 rx pd2
class DStepSerial0 //: Serial
{
public:
	static void begin(int baudrate);
	static u8 read();
	static void write(char ch);
	static void print(char* string);
	static DStepSerial0 getInstance() {
		static DStepSerial0 serial;
		return serial;
	}
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* rxGpioType;
	static GPIO_TypeDef* txGpioType;
	static USART_TypeDef* uartType;
};

//uart4 tx pc10 rx pc11
class DStepSerial1 //: Serial
{
public:
	static void begin(int baudrate);
	static u8 read();
	static void write(char ch);
	static void print(char* string);
	static DStepSerial1 getInstance() {
		static DStepSerial1 serial;
		return serial;
	}
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* rxGpioType;
	static GPIO_TypeDef* txGpioType;
	static USART_TypeDef* uartType;
};


//usart3 tx pb10 rx pb11
class DStepSerial2 //: Serial
{
public:
	static void begin(int baudrate);
	static u8 read();
	static void write(char ch);
	static void print(char* string);
	static DStepSerial2 getInstance() {
		static DStepSerial2 serial;
		return serial;
	}
protected:
	static unsigned short rxPin;
	static unsigned short txPin;
	static GPIO_TypeDef* rxGpioType;
	static GPIO_TypeDef* txGpioType;
	static USART_TypeDef* uartType;
};

#ifdef __cplusplus
}
#endif

#endif
