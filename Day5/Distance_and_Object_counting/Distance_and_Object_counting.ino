#define TrigPin D4
#define EchoPin D7
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "Viswanth";   // your network name
char pass[] = "jasthiuha";   // your network password
WiFiClient  client;

unsigned long myChannelField= 1490249;           //my Channel id
const int ChannelField = 1;                         //Channel Field 1
const int ChannelField1 = 3;                      //Channel Field 2
const char * myWriteApIKey = "JRGTRS75LW353OJX";  //write API key 
  int duration,distance;
int count = 0;
void setup() {
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("\nAttempting to connect to SSID: ");
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
count = count;
if(distance<180)
{
count = count + 1;
}
Serial.print("Distance:\t");
Serial.print(distance);
Serial.print("cm");
Serial.print("\n");
Serial.print("Object:\t");
Serial.print(count);
Serial.print("\n");
if(isnan(distance))
{
  Serial.print("Failed to read from the sensor");
  return;
}
ThingSpeak.writeField(myChannelField, ChannelField, distance, myWriteApIKey);
ThingSpeak.writeField(myChannelField, ChannelField1, count, myWriteApIKey);

delay(5000);
}

