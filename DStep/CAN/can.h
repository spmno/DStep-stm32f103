#ifndef _CAN_H_
#define _CAN_H_

void CAN_Config(void);
void CAN_Test_Function(void);
void CAN_Test_Function1(void);

class CAN
{
	static void begin(int baudrate);
	static unsigned char read();
};

#endif
