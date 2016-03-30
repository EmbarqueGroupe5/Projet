#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Wire.h>
#include "Magnetometer.h"


//Magnetometer
Adafruit_BNO055 magneto = Adafruit_BNO055(55);

void setup() {
  Serial.begin(9600);

  while (!magneto.begin()) {
    Serial.println("No BNO !");
    delay(1000);
  }
}

void loop() {
  //Magnetometer
  sensors_event_t magneto_event;
  magneto.getEvent(&magneto_event);
  
  Serial.println(magneto_event.magnetic.x);

  delay(100);
}
