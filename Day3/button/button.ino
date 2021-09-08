#define button D0
#define buzzer D1
int y;
void setup() {
  // put your setup code here, to run once:
pinMode(button, INPUT_PULLUP);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
y = digitalRead(button);
if(y == HIGH)
{
  digitalWrite(buzzer,1);
  Serial.print("Buzzer is on\n");
  delay(5000);
  digitalWrite(buzzer,0);
}
else
{
digitalWrite(buzzer,0); 
Serial.print("Buzzer is off\n"); 
}
delay(1000);
}

