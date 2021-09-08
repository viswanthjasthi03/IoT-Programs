#include "DHTesp.h"
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

char ssid[] = "Viswanth";   // your network name
char pass[] = "jasthiuha";   // your network password
WiFiClient  client;

unsigned long myChannelField= 1493119;           //my Channel id
const int ChannelField = 1;                       //Temperature Channel
const int ChannelField1 = 2;                       //Humidity Channel
const char * myWriteApIKey = "SAM3780V5NG7GWK6";  //write API key 

float hum,temp;

DHTesp dht;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  dht.setup(D0, DHTesp::DHT11);
}

void loop() {
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print("Connecting...\n");
      delay(5000);
    }
  Serial.println("\nConnected.");
  }
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
  ThingSpeak.writeField(myChannelField, ChannelField, temp, myWriteApIKey);
  ThingSpeak.writeField(myChannelField, ChannelField1, hum, myWriteApIKey);
  delay(5000);
}
