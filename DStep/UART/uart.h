#ifndef _MOTOR_UART_H_
#define _MOTOR_UART_H_
#include <stdio.h>

void UART_Init(void);
void UART_PutString(u8* buf,u8 len);

#endif

