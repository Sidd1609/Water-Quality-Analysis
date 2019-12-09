#include
#define DEBUG true
#define RX 2
#define TX 3

String HOST = "api.thingspeak.com";
String PORT = "80";
String AP = "AP NAME";
String PASS = "AP PASSWORD";


String API = "CJZ1G46URZWEGRVR";
String field = "field1";

int countTrueCommand;
int countTimeCommand;
boolean found = false;
int valSensor = 1;

SoftwareSerial esp8266(RX,TX);
void setup() {

Serial.begin(9600);
esp8266.begin(115200);

sendCommand("AT",5,"OK");
sendCommand("AT+CWMODE=1",5,"OK");
sendCommand("AT+CWJAP=""+ AP +"",""+ PASS +""",15,"OK");
countTrueCommand = 0;

}

void loop() {

String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(valSensor);
switch(countTrueCommand) {

case 0: sendCommand("AT",5,"OK");break;
case 1: sendCommand("AT+RST",10,"invalid");break;
case 2: sendCommand("AT+CIPMUX=1",5,"OK"); break;
case 3: sendCommand("AT+CIPSTART=0,"TCP","+ HOST +","+ PORT,15,"OK"); break;
case 4: sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">"); break;
case 5: esp8266.println(getData);delay(1500);countTrueCommand++; break;
case 6: sendCommand("AT+CIPCLOSE=0",5,"OK"); break;
case 7:

Serial.println(valSensor);
Serial.print(getData);
Serial.print(",");
Serial.println(getData.length());
valSensor = random(100000); // random value, change with sensor value if using sensor
countTrueCommand = 0;
delay(10000);
break;

}

}
void sendCommand(String command, int maxTime, char readReplay[]) {

Serial.print(countTrueCommand);
Serial.print(". at command => ");
Serial.print(command);
Serial.print(" ");
while(countTimeCommand < (maxTime*1))

{

esp8266.println(command);//at+cipsend
if(esp8266.find(readReplay))//ok
{

found = true;
break;

}
countTimeCommand++;

}
if(found == true)
{

Serial.println("OYI");

countTrueCommand++;
countTimeCommand = 0;

}
if(found == false)
{

Serial.println("Fail");
countTrueCommand = 0;
countTimeCommand = 0;

}
found = false;

}
