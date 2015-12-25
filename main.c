#include <stm32f10x_conf.h>

#include "GPIO/LED.h"
#include "CAN/CAN.h"
#include "I2C/I2C.h"
#include "KEY/key.h"
#include "PWM/pwm.h"
#include "Motor/motor.h"
#include "Uart/uart.h"
#include "SPI/spi.h"

//free rt os
#include "FreeRTOS.h"  
#include "task.h"  
#include "queue.h"  

static void vLEDTask( void *pvParameters );  


int main()
{
	vTraceInitTraceData();
	if (! uiTraceStart() ) {
		vTraceConsoleMessage("Could not start recorder!");
	}
	LED_GPIO_Config();
	xTaskCreate( vLEDTask, ( const portCHAR * ) "LED", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL );
	vTaskStartScheduler();  
}

void vLEDTask( void *pvParameters )  
{  
  for( ;; )  
  {  
    LED_ON();  
    vTaskDelay( 2000/portTICK_RATE_MS );  
    LED_OFF();  
    vTaskDelay( 2000/portTICK_RATE_MS );  
  }  
}  

