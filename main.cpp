
#include "DStep/DStep.h"

static void vLEDTask( void *pvParameters );  


int main()
{
	unsigned short adc_value =0;
	float temperature = 0.0;
	vTraceInitTraceData();
	if (! uiTraceStart() ) {
		vTraceConsoleMessage("Could not start recorder!");
	}
	//LED_GPIO_Config();
	Temperature_Config();
	adc_value = Get_Temperature();
	temperature= (1.42 - adc_value*3.3/4096)*1000/4.35 + 25;
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

