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
	
void LED_GPIO_Config(void);
void LED_ON(void);
void LED_OFF(void);

// pin port, mode input, output, input_pullup
void pinMode(int pin, int mode);

// pin port, value HIGH, LOW
void digitalWrite(int pin, int value);

// pin port, 
// return value, HIGH, LOW
int digitalRead(int pin);

#ifdef __cplusplus
}
#endif

#endif
