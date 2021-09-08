
void setup() {
  // put your setup code here, to run once:
pinMode(D2,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D2,1);
Serial.print("LED is on\n");
delay(3000);
digitalWrite(D2,0);
Serial.print("LED is off\n");
delay(3000);
}
