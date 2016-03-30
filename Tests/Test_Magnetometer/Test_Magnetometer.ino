#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>
#include "Magnetometer.h"


//Magnetometer
Magnetometer magneto;

void setup() {
  Serial.begin(9600);

  while (!magneto.begin()) {
    Serial.println("No BNO !");
    delay(1000);
  }
}

void loop() {
  //Magnetometer
  
  Serial.println(magneto.getX());

  delay(100);
}
