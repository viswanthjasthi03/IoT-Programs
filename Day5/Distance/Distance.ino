#define TrigPin D4
#define EchoPin D7
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "Viswanth";   // your network name
char pass[] = "jasthiuha";   // your network password
WiFiClient  client;

unsigned long myChannelField= 1490241;           //my Channel id
const int ChannelField = 1;                      //Channel Field
const char * myWriteApIKey = "ZEWCJB1L9XXH3CAX";  //write API key 

void setup() {
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
  int duration,distance;

void loop() {
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
  Serial.println("\nConnected.");
  }
digitalWrite(TrigPin,LOW);
delayMicroseconds(2);
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
duration = pulseIn(EchoPin,HIGH);
distance = duration * 0.034/2;
Serial.print("Distance:\t");
Serial.print(distance);
Serial.print("cm");
Serial.print("\n");
delay(5000);
if(isnan(distance))
{
  Serial.print("Failed to read from the sensor");
  return;
}
ThingSpeak.writeField(myChannelField, ChannelField, distance, myWriteApIKey);

delay(1000);
}

