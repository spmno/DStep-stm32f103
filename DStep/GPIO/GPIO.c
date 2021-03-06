#include <stm32f10x_conf.h>
#include "GPIO.h"

#ifdef __cplusplus
extern "C" {
#endif
	
#define PIN_NUMBER	31

static unsigned short pin_table[PIN_NUMBER] = {
	GPIO_Pin_15,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5,
	GPIO_Pin_6,
	GPIO_Pin_7,
	GPIO_Pin_8,
	GPIO_Pin_9,
	// PWM
	GPIO_Pin_10,
	GPIO_Pin_9,
	GPIO_Pin_8,
	GPIO_Pin_9,
	GPIO_Pin_8,
	GPIO_Pin_7,
	GPIO_Pin_6,
	// AD
	GPIO_Pin_0,
	GPIO_Pin_1,
	GPIO_Pin_2,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5,
	GPIO_Pin_6,
	GPIO_Pin_7,
	GPIO_Pin_0,
	GPIO_Pin_1,
	GPIO_Pin_0,
	GPIO_Pin_1,
	GPIO_Pin_2,
	GPIO_Pin_3,
	GPIO_Pin_4,
	GPIO_Pin_5
};

static GPIO_TypeDef* port_table[PIN_NUMBER] = {
	GPIOA,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	GPIOB,
	//pwm
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOC,
	GPIOC,
	GPIOC,
	GPIOC,
	//ad
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOA,
	GPIOB,
	GPIOB,
	GPIOC,
	GPIOC,
	GPIOC,
	GPIOC,
	GPIOC,
	GPIOC
};

static u8 port_source_table[PIN_NUMBER] = {
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	//pwm
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	//ad
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOA,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOB,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC,
	GPIO_PortSourceGPIOC
};

static u8 pin_source_table[PIN_NUMBER] = {
	GPIO_PinSource15,
	GPIO_PinSource3,
	GPIO_PinSource4,
	GPIO_PinSource5,
	GPIO_PinSource6,
	GPIO_PinSource7,
	GPIO_PinSource8,
	GPIO_PinSource9,
	//pwm
	GPIO_PinSource10,
	GPIO_PinSource9,
	GPIO_PinSource8,
	GPIO_PinSource9,
	GPIO_PinSource8,
	GPIO_PinSource7,
	GPIO_PinSource6,
	//ad
	GPIO_PinSource0,
	GPIO_PinSource1,
	GPIO_PinSource2,
	GPIO_PinSource3,
	GPIO_PinSource4,
	GPIO_PinSource5,
	GPIO_PinSource6,
	GPIO_PinSource7,
	GPIO_PinSource0,
	GPIO_PinSource1,
	GPIO_PinSource0,
	GPIO_PinSource1,
	GPIO_PinSource2,
	GPIO_PinSource3,
	GPIO_PinSource4,
	GPIO_PinSource5
};

void adcInit()
{
	ADC_InitTypeDef ADC_InitStructure; 
	ADC_DeInit(ADC1);  //set value to default
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	// independent mode
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;	// disable scan
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;	// single mode
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//soft start not external trig
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	ADC_InitStructure.ADC_NbrOfChannel = 1;	
	ADC_Init(ADC1, &ADC_InitStructure);	

	ADC_Cmd(ADC1, ENABLE);	// enable adc1
	ADC_ResetCalibration(ADC1);	
	while(ADC_GetResetCalibrationStatus(ADC1));	//until calibration complite
	ADC_StartCalibration(ADC1);		// set calibration.
	while(ADC_GetCalibrationStatus(ADC1));		
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		
}

// pin port, mode input, output, input_pullup
void pinMode(int pin, GPIOMode_TypeDef mode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	 
	if (port_table[pin] == GPIOA) {
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );
	} else if(port_table[pin] == GPIOB){
		if ((pin_table[pin] == GPIO_Pin_3)||(pin_table[pin] == GPIO_Pin_4)) {
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
			GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		}
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
	} else {
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );
	}
	
	GPIO_InitStructure.GPIO_Pin = pin_table[pin];
	GPIO_InitStructure.GPIO_Mode = mode;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(port_table[pin], &GPIO_InitStructure);
	
	if (mode == INPUT) {
		GPIO_EXTILineConfig(port_source_table[pin], pin_source_table[pin]);
	} else if (mode == ANALOG_INPUT) {
		// enable adc
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE );	  
		
		//AD采样时钟72M/6=12M,不能超过14M，否则精度下降
		RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
		adcInit();
	} 
}

void digitalWrite(u16 pin, u8 value)
{
	if (value == LOW) {
		GPIO_ResetBits(port_table[pin], pin_table[pin]);
	} else {
		GPIO_SetBits(port_table[pin], pin_table[pin]);
	}
}

u8 digitalRead(u16 pin) 
{
	return GPIO_ReadInputDataBit(port_table[pin], pin_table[pin]);
}

#ifdef __cplusplus
}
#endif

