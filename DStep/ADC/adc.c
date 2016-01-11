#include "stm32f10x_conf.h"
#include "adc.h"
		   
void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// enable adc
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_ADC1	, ENABLE );	  
 	
	//RCC_APB2Periph_GPIOx,x=GPIOx
	//AD采样时钟72M/6=12M,不能超过14M，否则精度下降
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   
	
	//PA0--ADC_IN0  PA1--ADC_IN1  PA2--ADC_IN2  PA3--ADC_IN3  PA4--ADC_IN4  PA5--ADC_IN5  PA6--ADC_IN6  PA7--ADC_IN7  
	//PB0--ADC_IN8  PB1--ADC_IN9  PC0--ADC_IN10  PC1--ADC_IN11  PC2--ADC_IN12  PC3--ADC_IN13  PC4--ADC_IN14  PC5--ADC_IN15                   
	//PA0~3  4路作为模拟通道输入引脚                         
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;	//analog input
	GPIO_Init(GPIOA, &GPIO_InitStructure);			  //x=GPIOx
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		
	GPIO_Init(GPIOB, &GPIO_InitStructure);			  
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		
	GPIO_Init(GPIOC, &GPIO_InitStructure);			  

//------------------------------------ADC设置--------------------------------------------------------

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

//获得ADC值
//ch:通道值 0~3
u16 Get_Adc(u8 ch)   
{	
	unsigned int result=0;
	unsigned char i;

  //设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道ch,规则采样顺序值序列为1,采样时间为239.5周期	  			    
  for(i=0;i<8;i++) {
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	 
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
		result+=ADC_GetConversionValue(ADC1);
	}
	result=result/8;	 //取8次采样的平均值
	return result;	//返回平均值
}

int analogRead(u16 pin)
{
	unsigned int result=0;
	unsigned char i;

  //设置指定ADC的规则组通道，设置它们的转化顺序和采样时间
	ADC_RegularChannelConfig(ADC1, pin, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道ch,规则采样顺序值序列为1,采样时间为239.5周期	  			    
  for(i=0;i<8;i++) {
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	 
		while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
		result+=ADC_GetConversionValue(ADC1);
	}
	result=result/8;	 //取8次采样的平均值
	return result;	//返回平均值
}



