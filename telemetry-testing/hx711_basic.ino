const int analogPin = A0; 
float sensorValue = 0.0; 

void setup() {
  Serial.begin(9600); 
  pinMode(analogPin, INPUT); 

}

void loop() {
  sensorValue = analogRead(analogPin); 
  Serial.print("Sensor value: "); 
  Serial.println(sensorValue); 

  delay(500); 
}