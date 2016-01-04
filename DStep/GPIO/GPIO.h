#ifndef _GPIO_H_
#define _GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

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
