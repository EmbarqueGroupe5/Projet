/**
 * Test de luminosité pour controller une led
 */
#include "Sensor.h"

#define SENSOR_LUM_PIN 4
#define LED_PIN 13


//Sensors
Sensor sensor_lum(SENSOR_LUM_PIN);

//Vars
bool status = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
}




void loop() {
  int percentage = sensor_lum.readMap(100, 0);
  Serial.print("Pourcentage : ");
  Serial.println(percentage);
  if (percentage < 20) {
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(200);
}
