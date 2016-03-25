#include "MagicServo.h"
#include "Sensor.h"

#define LEFT_SERVO_PIN 15
#define RIGHT_SERVO_PIN 14


MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

Sensor sensor_1(0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");

  sensor_1.setLimit(500);

  left.init();
  right.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
