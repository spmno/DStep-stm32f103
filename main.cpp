
#include "DStep/DStep.h"

static void vLEDTask( void *pvParameters );  
static void interrupt1( void );
TaskHandle_t xHandle = NULL;
int send_flag = 0;

void test()
{
	DStepSerial0::begin(9600);
	DStepSerial0::write('8');
	u8 value = DStepSerial0::read();
	DStepSerial1::begin(9600);
	DStepSerial1::write('8');
	value = DStepSerial1::read();
	
	pinMode(IO0, OUTPUT);
	digitalWrite(IO0, LOW);
	digitalWrite(IO0, HIGH);
	
	pinMode(IO0, OUTPUT);
	pinMode(IO1, OUTPUT);
	pinMode(IO2, OUTPUT);
	pinMode(IO3, OUTPUT);
	pinMode(IO4, OUTPUT);
	pinMode(IO5, OUTPUT);
	pinMode(IO6, OUTPUT);
	pinMode(IO7, OUTPUT);
	
	digitalWrite(IO0, HIGH);
	digitalWrite(IO1, HIGH);
	digitalWrite(IO2, HIGH);
	digitalWrite(IO3, HIGH);
	digitalWrite(IO4, HIGH);
	digitalWrite(IO5, HIGH);
	digitalWrite(IO6, HIGH);
	digitalWrite(IO7, HIGH);
	
}

int main()
{
	unsigned short adc_value =0;
	float temperature = 0.0;
	vTraceInitTraceData();
	if (! uiTraceStart() ) {
		vTraceConsoleMessage("Could not start recorder!");
	}
	//LED_GPIO_Config();

	//attachInterrupt(IO0, interrupt1, EXTI_Trigger_Rising_Falling);
	Temperature_Config();
	adc_value = Get_Temperature();
	temperature= (1.42 - adc_value*3.3/4096)*1000/4.35 + 25;

	CAN_Config();
	xTaskCreate( vLEDTask, ( const portCHAR * ) "LED", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, NULL );
	vTaskStartScheduler();  
}

void vLEDTask( void *pvParameters )  
{  
  for( ;; )  
  { 
		u8 value = digitalRead(IO0);
		if (value == 0) {
			CAN_Test_Function1();
		}	
  }  
}  

void interrupt1( void )
{
	u8 value = digitalRead(IO0);
	if (value == 0) {
		send_flag = 1;
	} else {
		send_flag = 0;
	}
	
}


