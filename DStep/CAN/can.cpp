#include "stm32f10x_conf.h"
#include "can.h"
#include "../GPIO/GPIO.h"

void CAN_GPIOB_Config(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//clock setting
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	
	
	// configure can pin: rx pb8
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// configure can pin: tx pb9
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	// io setting
	GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE);
}

void CAN_GPIOA_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//clock setting
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	
	// configure can pin: rx pa11
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// configure can pin: tx pa12
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

}

void CAN_GPIO_Config(void)
{
	CAN_GPIOA_Config();
}

void CAN_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//configure one bit for preemption priority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	// can rx0 interrupt
	//NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;  //for pb8 pb9
	NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn; // for pa11 pa12
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void CAN_Mode_Config(void)
{
	int ret = 0;
	CAN_InitTypeDef CAN_InitStructure;
	CAN_DeInit(CAN1);
	CAN_StructInit(&CAN_InitStructure);
	
	// can unit init
	// disable ttcan which is high level can transmition protocol
	CAN_InitStructure.CAN_TTCM = DISABLE;
	// auto offline management
	CAN_InitStructure.CAN_ABOM = DISABLE;//ENABLE;
	// auto awake up mode
	CAN_InitStructure.CAN_AWUM = DISABLE;//ENABLE;
	// auto resend report 
	CAN_InitStructure.CAN_NART = DISABLE;
	// receive fifo locked mode, DISABLE-overwrite the exist data
	CAN_InitStructure.CAN_RFLM = DISABLE;
	// tranmit fifo priority, DISABLE-priority is decide by id
	CAN_InitStructure.CAN_TXFP = DISABLE;
	// work mode
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;//CAN_Mode_Normal;
	//CAN_InitStructure.CAN_Mode = CAN_Mode_LoopBack;//CAN_Mode_LoopBack;
	// 500k baudrate
	// jump 1 time unit while syn
	CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
	// TS1 6 time sigment
	CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
	// TS2 5 time sigment
	CAN_InitStructure.CAN_BS2 = CAN_BS2_5tq;
	CAN_InitStructure.CAN_Prescaler = 6;
	
	ret = CAN_Init(CAN1, &CAN_InitStructure);
	if (ret ==  CAN_InitStatus_Failed) {
		ret = 0;
	}
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
}

void CAN_Filter_Config(void)
{
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
	CAN_FilterInitStructure.CAN_FilterNumber = 0;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(&CAN_FilterInitStructure);

}

void CAN_Config(void)
{
	CAN_GPIO_Config();
	CAN_NVIC_Config();
	CAN_Mode_Config();
	CAN_Filter_Config();
}

void USB_LP_CAN1_RX0_IRQHandler(void)
{
	CanRxMsg RxMessage;
	char data0;
	CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
	if (RxMessage.StdId == 0x2e1) {
		if ((RxMessage.Data[0] != 0) || (RxMessage.Data[1] != 0) ||
			(RxMessage.Data[2] != 0) || (RxMessage.Data[3] != 0) ||
			(RxMessage.Data[4] != 0) || (RxMessage.Data[5] != 0) ||
			(RxMessage.Data[6] != 0) ||	(RxMessage.Data[7] != 0)) {
			data0 = RxMessage.Data[0];
			if ((data0&0xff) > 0) {
				LED_ON();
			} else {
				LED_OFF();
			}
		}

	}
	
}

void CAN_Test_Function(void)
{
	int TransmitBoxResult = 0;
	int i = 0;
	CanTxMsg TxMessage;
	TxMessage.StdId = 0x2e1;
  TxMessage.ExtId = 1;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
	TxMessage.Data[0] = 0;
	TxMessage.Data[1] = 0;
	TxMessage.Data[2] = 0;
	TxMessage.Data[3] = 0;
	TxMessage.Data[4] = 0;
	TxMessage.Data[5] = 0;
	TxMessage.Data[6] = 0;
	TxMessage.Data[7] = 0;
	TransmitBoxResult = CAN_Transmit(CAN1, &TxMessage);
	while( ( CAN_TransmitStatus(CAN1,TransmitBoxResult) != CANTXOK ) && ( i != 0xFF )) {
                i++;
  }
}

void CAN_Test_Function1(void)
{
	int TransmitBoxResult = 0;
	int i = 0;
	CanTxMsg TxMessage;
	TxMessage.StdId = 0x2e1;
  TxMessage.ExtId = 1;
  TxMessage.RTR = CAN_RTR_DATA;
  TxMessage.IDE = CAN_ID_STD;
  TxMessage.DLC = 8;
	TxMessage.Data[0] = 0x40;
	TxMessage.Data[1] = 0;
	TxMessage.Data[2] = 0;
	TxMessage.Data[3] = 0;
	TxMessage.Data[4] = 0;
	TxMessage.Data[5] = 0;
	TxMessage.Data[6] = 0;
	TxMessage.Data[7] = 0;
	TransmitBoxResult = CAN_Transmit(CAN1, &TxMessage);
	while( ( CAN_TransmitStatus(CAN1,TransmitBoxResult) != CANTXOK ) && ( i != 0xFF )) {
                i++;
  }
}
