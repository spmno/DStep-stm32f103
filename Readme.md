DStep Borad 
====

stm32 cpu has like arduino api.
IO
----
<p>
write:
<code>
pinMode(IO0, OUTPUT);
digitalWrite(IO0, LOW);
</code>
read:
<code>
pinMode(IO0, INPUT);
u8 value = digitalRead(IO0);
</code>
</p>
Serial Port
-----------
<p>
DStepSerial0::begin(9600);
DStepSerial0::write('8');
u8 value = DStepSerial0::read();
</p>
<p>
AD
----
pinMode(A0, ANALOG_INPUT);
u16 ad_value = analogRead(A0);
</p>
<p>
PWM
----
pinMode(PWM0, ANALOG_OUTPUT);
analogWrite(PWM0, 50);
</p>
