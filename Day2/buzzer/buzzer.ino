int buzzer=D4;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzzer,HIGH);
Serial.print("buzzer is on\n");
delay(1000);
digitalWrite(buzzer,LOW);
Serial.print("buzzer is off\n");
delay(1000);
}
