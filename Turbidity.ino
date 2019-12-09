void setup() {
  Serial.begin(9600);

}
void loop() {
  int sensorValue = analogRead(A1);
  float voltage = sensorValue * (5.0 / 1024.0);

  Serial.println ("Sensor Output (V):");
  Serial.println (voltage);
  Serial.println();
  delay(1000);
}
