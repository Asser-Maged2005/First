#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial motorSerial(2, 3); 

void setup() {
  Wire.begin();            
  Serial.begin(9600);       
  motorSerial.begin(9600);
}

void loop() {
  // First I2C request
  Wire.requestFrom(8, 3); 
  while (Wire.available()) {
    char data1 = Wire.read();
    Serial.print(data1);
  }
  Serial.println();
  delay(300);

  // Second I2C request 
  Wire.requestFrom(7, 2);
  if (Wire.available() >= 2) {
    byte state1 = Wire.read();
    byte state2 = Wire.read();
    Serial.print(" state 1 = ");
    Serial.print(state1);
    Serial.print(" state 2 = ");
    Serial.println(state2);
  }
  
  delay(300); 

  if (Serial.available() > 0) {
    char val1 = Serial.read(); 
    motorSerial.println(val1);
  }
}