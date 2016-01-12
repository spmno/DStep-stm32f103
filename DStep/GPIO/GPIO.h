#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#define OUTPUT					GPIO_Mode_Out_PP
#define INPUT						GPIO_Mode_IN_FLOATING
#define INPUT_PULLUP		GPIO_Mode_IPU
	
#define HIGH						1
#define LOW							0
	

// pin port, mode input, output, input_pullup
void pinMode(int pin, int mode);

// pin port, value HIGH, LOW
void digitalWrite(u16 pin, u8 value);

// pin port, 
// return value, HIGH, LOW
u8 digitalRead(u16 pin);


#ifdef __cplusplus
}
#endif

#endif
