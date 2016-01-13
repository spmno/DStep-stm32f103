#include "stm32f10x_conf.h"
#include "pwm.h"

static int step = 1;

void PWM_GPIO_Config(void)
{
	
}

void PWM_TIMER_Config(void)
{
	
}

static void TIM3_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//TIM3Ê±ÖÓ
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//GPIOAºÍGPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	
	//GPIO Configuration 
	//GPIO A
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//GPIO B
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

static void TIM1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//TIM1Ê±ÖÓ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	//GPIOAºÍGPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
	
	//GPIO Configuration 
		//GPIO A
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO B
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}


static void TIM3_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	short CCR1_Val = 500;
	short CCR2_Val = 375;
	short CCR3_Val = 250;
	short CCR4_Val = 125;
	
	TIM_TimeBaseStructure.TIM_Period = 999;
	//Ô¤·ÖÆµ
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	//·ÖÆµ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//¼ÆÊýÄ£Ê½
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	//PWM1 Mode
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	//ÉèÖÃÌø×ªÖµ
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	//µ±¶¨Ê±Æ÷Ð¡ÓÚÕâ¸öÖµÎª¸ßµçÆ½
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//PWM1 Channel2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//PWM1 Channel3
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//PWM1 Channel4
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
	
}


static void TIM1_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	short CCR1_Val = 500;
	short CCR2_Val = 375;
	short CCR3_Val = 250;
	short CCR4_Val = 125;
	short CCRA_Val = 999;
	
	TIM_TimeBaseStructure.TIM_Period = 999;
	//Ô¤·ÖÆµ
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	//·ÖÆµ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	//¼ÆÊýÄ£Ê½
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	//PWM1 Mode
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	//ÉèÖÃÌø×ªÖµ
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	//µ±¶¨Ê±Æ÷Ð¡ÓÚÕâ¸öÖµÎª¸ßµçÆ½
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	//PWM1 Channel2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	//PWM1 Channel3
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	//PWM1 Channel4
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	
}

void TIM1_Mode_Config_COM()
{

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
	short CCR1_Val = 4095;
	short CCR2_Val = 2047;
	short CCR3_Val = 1023;
	short CCR4_Val = 125;
	/* Time Base configuration */
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	//Specifies the period value to be loaded into the active
	//Auto-Reload Register at the next update event.
	TIM_TimeBaseStructure.TIM_Period = CCR1_Val;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //Specifies the clock division.
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	/* Channel 1, 2,3 and 4 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;//TIM_OCMode_PWM1;//
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	//Specifies the pulse value to be loaded into the Capture Compare Register.
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	//TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	//TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	//TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	//PWM1 Channel2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	//PWM1 Channel3
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

	/* Automatic Output enable, Break, dead time and lock configuration*/
	/*
	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable; //?????“????”?? (Off-state selection for Run mode)
	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;
	TIM_BDTRInitStructure.TIM_DeadTime = 1;
	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;   //?????? (Break polarity)
	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;//1:MOE(?????)?????’1’?????????????’1’(????????)?
	
	TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);
	*/
	TIM_CCPreloadControl(TIM1, ENABLE);
	
	TIM_ITConfig(TIM1, TIM_IT_COM, ENABLE);
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	/* TIM1 counter enable */
	TIM_Cmd(TIM1, ENABLE);

	/* Main Output Enable */
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}


void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the TIM1 Interrupt */
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_TIM17_IRQn;
#else
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_IRQn;
#endif

  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure); 

}

void PWM_Config(MOTROR_ControlType type)
{
	if (type == PWM_CONTROL) {
		TIM1_GPIO_Config();
	} else {
		//TIM1_GPIO_Config_With_GPIO();
	}
	
	TIM1_Mode_Config();
	//TIM1_Mode_Config_COM();
	NVIC_Configuration();
	TIM_GenerateEvent(TIM1, TIM_EventSource_COM);
}


#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
void TIM1_TRG_COM_TIM17_IRQHandler(void)
#else
void TIM1_TRG_COM_IRQHandler(void)
#endif
{
   /* Clear TIM1 COM pending bit */
  TIM_ClearITPendingBit(TIM1, TIM_IT_COM);

	if (step == 1)
	{
    /* Next step: Step 2 Configuration ---------------------------- */
    /* Channel3 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);

    /* Channel1 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);

    /* Channel2 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1 );
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
    step++;
	}
	else if (step == 2)
	{
    /* Next step: Step 3 Configuration ---------------------------- */
    /* Channel2 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Enable);
   
    /* Channel3 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);

    /* Channel1 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);
    step++;
	}
	else if (step == 3)
	{
    /* Next step: Step 4 Configuration ---------------------------- */
    /* Channel3 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);

    /* Channel2 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);

    /* Channel1 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);
    step++;
	}
	else if (step == 4)
	{
    /* Next step: Step 5 Configuration ---------------------------- */
    /* Channel3 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Disable);

    /* Channel1 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Enable);

    /* Channel2 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
    step++;
	}
	else if (step == 5)
	{
   /* Next step: Step 6 Configuration ---------------------------- */
    /* Channel3 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);

   /* Channel1 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_1, TIM_CCxN_Disable);

    /* Channel2 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_2, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
    step++;
	}
	else
	{
    /* Next step: Step 1 Configuration ---------------------------- */
    /* Channel1 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_1, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_1, TIM_CCx_Enable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);

    /* Channel3 configuration */
    TIM_SelectOCxM(TIM1, TIM_Channel_3, TIM_OCMode_PWM1);
    TIM_CCxCmd(TIM1, TIM_Channel_3, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_3, TIM_CCxN_Enable);

    /* Channel2 configuration */
    TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Disable);
    TIM_CCxNCmd(TIM1, TIM_Channel_2, TIM_CCxN_Disable);
    step = 1;
	}
}


void analogWrite(u16 pin, u8 value)
{
	
}

void analogFrequence(int frequence)
{
	
}

