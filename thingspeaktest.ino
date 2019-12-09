#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include<ThingSpeak.h>
#include<WiFiClient.h>
#include<SoftwareSerial.h>
#include<ESP8266WiFi.h>
//#include<ESP8266WiFiGeneric.h>
#include<ESP8266WifiSTA.h>
//SoftwareSerial espSerial(2, 3);   
char* WriteAPIKey="0R6SUQY5SMNURGBWU";
char* ssid="FD-23";
char* pass="admin007";
char* thingSpeakAddress = "api.thingspeak.com";
const long ChannelNumber=882136;
WiFiClient client;

int n1=1;
int n2=0;

void setup() 
{
 //pinMode(trigPin, OUTPUT);
 //pinMode(echoPin, INPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
//  WiFi.mode(WiFi_STA);
}
void loop()
{
  if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Attempting to connect");
    while(WiFi.status()!=WL_CONNECTED)
      WiFi.begin(ssid, pass);
  }
  ThingSpeak.writeField(ChannelNumber, 1,n1, WriteAPIKey);
  ThingSpeak.writeField(ChannelNumber, 1,n2, WriteAPIKey);
  n1=!n2;
  n2=!n1;
  delay(4000);
}
