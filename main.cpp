
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
	DStepSerial2::begin(9600);
	DStepSerial2::write('8');
	value = DStepSerial2::read();
	
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
	
	digitalWrite(IO0, LOW);
	digitalWrite(IO1, LOW);
	digitalWrite(IO2, LOW);
	digitalWrite(IO3, LOW);
	digitalWrite(IO4, LOW);
	digitalWrite(IO5, LOW);
	digitalWrite(IO6, LOW);
	digitalWrite(IO7, LOW);
	
	pinMode(A0, ANALOG_INPUT);
	pinMode(A1, ANALOG_INPUT);
	pinMode(A2, ANALOG_INPUT);
	pinMode(A3, ANALOG_INPUT);
	pinMode(A4, ANALOG_INPUT);
	pinMode(A5, ANALOG_INPUT);
	pinMode(A6, ANALOG_INPUT);
	pinMode(A7, ANALOG_INPUT);
	pinMode(A8, ANALOG_INPUT);
	pinMode(A9, ANALOG_INPUT);
	pinMode(A10, ANALOG_INPUT);
	pinMode(A11, ANALOG_INPUT);
	pinMode(A12, ANALOG_INPUT);
	pinMode(A13, ANALOG_INPUT);
	pinMode(A14, ANALOG_INPUT);
	pinMode(A15, ANALOG_INPUT);
	
	u16 ad_value = analogRead(A0);
	ad_value = analogRead(A1);
	ad_value = analogRead(A2);
	ad_value = analogRead(A3);
	ad_value = analogRead(A4);
	ad_value = analogRead(A5);
	ad_value = analogRead(A6);
	ad_value = analogRead(A7);
	ad_value = analogRead(A8);
	ad_value = analogRead(A9);
	ad_value = analogRead(A10);
	ad_value = analogRead(A11);
	ad_value = analogRead(A12);
	ad_value = analogRead(A13);
	ad_value = analogRead(A14);
	ad_value = analogRead(A15);
	
}

int main()
{
	unsigned short adc_value =0;
	float temperature = 0.0;
	vTraceInitTraceData();
	if (! uiTraceStart() ) {
		vTraceConsoleMessage("Could not start recorder!");
	}

	test();
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


