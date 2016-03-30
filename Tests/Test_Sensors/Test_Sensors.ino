#include "Sensor.h"

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15

#define SENSOR_FRONT_PIN 0
#define SENSOR_BACK_PIN 1
#define SENSOR_LEFT_PIN 2
#define SENSOR_RIGHT_PIN 3
#define SENSOR_LUM_PIN 4
#define SENSOR_GREY_PIN 5

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);
Sensor sensor_back(SENSOR_BACK_PIN);
Sensor sensor_left(SENSOR_LEFT_PIN);
Sensor sensor_right(SENSOR_RIGHT_PIN);
Sensor sensor_lum(SENSOR_LUM_PIN);
Sensor sensor_grey(SENSOR_GREY_PIN);

//Vars
bool status = 0;

void setup() {
  Serial.begin(9600);

  sensor_front.setLimit(600);
  sensor_back.setMode(SENSOR_MODE_MINUS); //Valeur faible si detection
  sensor_back.setLimit(150);
  sensor_left.setLimit(600);
  sensor_right.setLimit(600);
  sensor_grey.setLimit(600);
}

void loop() {
  Serial.println(sensor_back.detect());
  delay(400);
}
