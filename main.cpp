
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
	DStepSerial0::begin(9600);
	DStepSerial0::write('8');
	u8 value = DStepSerial0::read();
	DStepSerial1::begin(9600);
	DStepSerial1::write('8');
	//value = DStepSerial1::read();
	xTaskCreate( vLEDTask, ( const portCHAR * ) "LED", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL );
	vTaskStartScheduler();  
}

void vLEDTask( void *pvParameters )  
{  
  for( ;; )  
  {  
 
    vTaskDelay( 2000/portTICK_RATE_MS );  

    vTaskDelay( 2000/portTICK_RATE_MS );  
  }  
}  

