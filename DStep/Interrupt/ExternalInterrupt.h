#ifndef _MOTOR_KEY_H_
#define _MOTOR_KEY_H_

#ifdef __cplusplus
extern "C" {
#endif

void KEY_GPIO_Config(void);

#define RISING_FALLING 		EXTI_Trigger_Rising_Falling 
#define RISING 						EXTI_Trigger_Rising  
#define FALLING 					EXTI_Trigger_Falling

void attachInterrupt(u8 pin, void (*userFunction)(void), EXTITrigger_TypeDef mode);
void detachInterrupt(u8 pin);

#ifdef __cplusplus
}
#endif	
	
	
#endif

