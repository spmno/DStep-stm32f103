#ifndef _MOTOR_KEY_H_
#define _MOTOR_KEY_H_

void KEY_GPIO_Config(void);

void attachInterrupt(u8 interupt, void (*userFunction)(void), int mode);

#endif

