#include "MagicServo.h"

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15
#define NORMAL_FRONT_ORIENTATION 0
#define REVERSE_FRONT_ORIENTATION 1

MagicServo left(LEFT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);
MagicServo right(RIGHT_SERVO_PIN, REVERSE_FRONT_ORIENTATION);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:

}