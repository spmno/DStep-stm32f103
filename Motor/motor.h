#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "../MotorTypeDef.h"

#ifdef __cplusplus
extern "C"{
#endif

void Motor_T1_Low(void);
void Motor_T1_PWM(void);

void Motor_T2_High(void);
void Motor_T2_Low(void);

void Motor_T3_Low(void);
void Motor_T3_PWM(void);

void Motor_T4_High(void);
void Motor_T4_Low(void);

void Motor_T5_Low(void);
void Motor_T5_PWM(void);

void Motor_T6_High(void);
void Motor_T6_Low(void);




void Motor_Init(MOTROR_ControlType type);

#ifdef __cplusplus
}
#endif


#endif
