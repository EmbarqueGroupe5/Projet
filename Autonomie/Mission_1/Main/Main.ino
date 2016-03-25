#include "MagicServo.h"
#include "Sensor.h"

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15

MagicServo left(LEFT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);
MagicServo right(RIGHT_SERVO_PIN, REVERSE_FRONT_ORIENTATION);

Sensor sensor_1(4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:

}
