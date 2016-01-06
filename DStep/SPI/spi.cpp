#include "stm32f10x_conf.h"
#include "spi.h"

#define SPI_AD_CS_HIGH() GPIO_SetBits(GPIOC, GPIO_Pin_9)
#define SPI_AD_CS_LOW()  GPIO_ResetBits(GPIOC, GPIO_Pin_9)

void SPI_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}

void SPI_BUS_Config()
{
	SPI_InitTypeDef SPI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	SPI_AD_CS_HIGH();

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;
	//SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;               
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;      //SPI_CPOL_Low;//          
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;        
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;                
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;                
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;    
  SPI_InitStructure.SPI_CRCPolynomial = 7;        
  SPI_Init(SPI1, &SPI_InitStructure);  
	
	SPI_Cmd(SPI1, ENABLE);
}

void SPI_Config(void)
{
	SPI_GPIO_Config();
	SPI_BUS_Config();
}

unsigned short SPI_GetData()
{
	unsigned short data = 0;
	unsigned short data1 = 0;
	SPI_AD_CS_LOW();
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);
	SPI_I2S_SendData(SPI1, 0x04);
	//SPI_I2S_SendData(SPI1, 0x2C);
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);
	data = SPI_I2S_ReceiveData(SPI1);
	data1 = SPI_I2S_ReceiveData(SPI1);
	SPI_AD_CS_HIGH();
	return data;
}

