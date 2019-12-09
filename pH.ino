

int analogInPin = A0;
int buf[10],avgValue,temp;


void setup()
{
  Serial.begin(9600);
}
void loop()
{
  for(int i=0;i<10;i++) 

 { 
  buf[i]=analogRead(analogInPin);// Take 10 readings
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])//sorting the values
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];//calculate avg 
 float pHVol=(float)(avgValue*5.0/1024)/6; //Convert avg to Voltage 
 float phValue = 3.5 * pHVol; //Convert voltage to pH 
 Serial.print("pH Value = ");
 Serial.println(phValue);
 delay(2000);
} 
