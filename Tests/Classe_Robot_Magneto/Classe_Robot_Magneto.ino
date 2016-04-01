#include "MagicServo.h"
#include "Sensor.h"
#include "Robot.h"

#include <Servo.h>

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15
#define SENSOR_FRONT_PIN 0

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);

//Robot
Robot robot(left, right);

void setup() {
  Serial.begin(9600);

  sensor_front.setLimit(600);

  left.init();
  right.init();
}

void loop() {
  robot.forward(100);
  delay(2000);
  robot.stop();
  delay(2000);
  robot.left(10);
  delay(2000);
  robot.right(20);
  delay(2000);
  robot.backward(5);
  delay(2000);
}
