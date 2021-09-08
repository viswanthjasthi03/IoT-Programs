#define ldr A0
#define led D0
int x;
void setup() {
  // put your setup code here, to run once:
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
x=analogRead(A0);
if(x<=300){
digitalWrite(led,1);
Serial.print("Darkness\t");
Serial.print("Light is on\n");
}
else
{
  digitalWrite(led,0);
  Serial.print("Lightness\t");
Serial.print("Light is off\n");
}
delay(1000);
}
