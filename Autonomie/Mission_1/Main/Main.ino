#include "MagicServo.h"
#include "Sensor.h"

#define LEFT_SERVO_PIN 15
#define RIGHT_SERVO_PIN 14
#define SENSOR_FRONT_PIN 0

MagicServo left(LEFT_SERVO_PIN, NORMAL_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, REVERSE_FRONT_ORIENTATION);// Constructeur

Sensor sensor_front(SENSOR_FRONT_PIN);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");

  sensor_front.setLimit(500);

  left.init();
  right.init();

  left.front(100);
  right.front(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (sensor_front.detect()) {
    left.back(100);
    delay(500);
  }
  else {
    left.front(100);
    right.front(100);
  }
  Serial.println(sensor_front.detect());
  delay(100);
}
