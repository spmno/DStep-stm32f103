DStep Borad 
====

stm32 cpu has like arduino api.
IO
----
<p>
write:
<br>
<code>pinMode(IO0, OUTPUT);</code><br>
<code>digitalWrite(IO0, LOW);</code><br>
read:<br>
<code>pinMode(IO0, INPUT);</code><br>
<code>u8 value = digitalRead(IO0);</code><br>
</p>

Serial Port
-----------
<p>
<code>DStepSerial0::begin(9600);</code><br>
<code>DStepSerial0::write('8');</code><br>
<code>u8 value = DStepSerial0::read();</code><br>
</p>

<p>
AD
----
<code>pinMode(A0, ANALOG_INPUT);</code><br>
<code>u16 ad_value = analogRead(A0);</code><br>
</p>

<p>
PWM
----
<code>pinMode(PWM0, ANALOG_OUTPUT);</code><br>
<code>analogWrite(PWM0, 50);</code><br>
</p>
<br>
