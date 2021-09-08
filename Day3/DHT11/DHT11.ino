#include "DHTesp.h"
float hum,temp;
#define green D1
#define blue D2
#define red D3

DHTesp dht;

void setup() {
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  dht.setup(D0, DHTesp::DHT11);
}

void loop() {
  hum = dht.getHumidity();
  temp = dht.getTemperature();

  if(isnan(hum) || isnan(temp))
  {
    Serial.println("Failed to read the Tem and Hum values from DHT sensors ! \n");
    return ;
  }
    Serial.print("Temperature : ");
  Serial.print(temp);
  Serial.print("Degrees Celcius ,Humidity : ");
  Serial.print(hum);
  Serial.print("\n");
if(temp <=20)
{
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  Serial.print("Low Temperature\n");
}
else if(temp >20 && temp < 40)
{
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  Serial.print("Normal Temperature\n");
}
else if(temp >= 40)
{
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  Serial.print("High Temperature\n");
}
  delay(5000);
  
  
}
