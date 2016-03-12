DStep Borad 
====

stm32 cpu has like arduino api.

IO

write:
pinMode(IO0, OUTPUT);
digitalWrite(IO0, LOW);

read:
pinMode(IO0, INPUT);
u8 value = digitalRead(IO0);

Serial Port

DStepSerial0::begin(9600);
DStepSerial0::write('8');
u8 value = DStepSerial0::read();

AD

pinMode(A0, ANALOG_INPUT);
u16 ad_value = analogRead(A0);

PWM
pinMode(PWM0, ANALOG_OUTPUT);
analogWrite(PWM0, 50);