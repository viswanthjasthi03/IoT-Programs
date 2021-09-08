#define led D1
#define pir D0
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "Viswanth";   // your network name
char pass[] = "jasthiuha";   // your network password
WiFiClient  client;

unsigned long myChannelField= 1491766;               //my Channel id
const int ChannelField = 1;                          //Channel Field 1                  
const char * myWriteApIKey = "VINAYEETUA8EEWMC";     //write API key 

void setup() {
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
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
      Serial.print("Connecting...\n");
      delay(5000);
    }
  Serial.println("\nConnected.");
  }
int x = digitalRead(pir);
Serial.print("PIR Value is ");
Serial.print(x);
Serial.print("\n");
if(x == HIGH)
{
  digitalWrite(led,HIGH);
  Serial.print("Led is on\n");
}
else
{
  digitalWrite(led,LOW);
  Serial.print("Led is off\n");
}
if(isnan(x))
{
  Serial.print("Failed to read from the sensor");
  return;
}
ThingSpeak.writeField(myChannelField, ChannelField, x, myWriteApIKey);
}

