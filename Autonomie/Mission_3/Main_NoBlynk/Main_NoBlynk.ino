#include "MagicServo.h"
#include "Sensor.h"
#include "Magnetometer.h"
#include "Robot.h"

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15

#define SENSOR_FRONT_PIN 0
#define SENSOR_BACK_PIN 1
#define SENSOR_LEFT_PIN 2
#define SENSOR_RIGHT_PIN 3
#define SENSOR_LUM_PIN 5
#define SENSOR_GREY_PIN 4

#define HIGH 0
#define LOW 1

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_grey(SENSOR_GREY_PIN);

//Robot
Robot robot(left, right);

//Vars
bool status = 0;
float angle = 0.0;
float actualAngle = 0.0;
float diffe = 0.0;

//Magnetometer
Magnetometer magneto;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_SW0, INPUT_PULLUP);

  sensor_grey.setMode(SENSOR_MODE_MINUS);
  sensor_grey.setLimit(300); //Detecte en dessous de 400

  left.init();
  right.init();

  while (!magneto.begin()) {
    Serial.println("No Magnetometer found !");
    delay(1000);
  }
}

int diff(int a, int b) {
  int diff = b - a ;
  if (diff < -180) diff += 360;
  else if (diff > 180) diff -= 360;
  return diff;
}

void loop() {
  if (digitalRead(PIN_SW0) == HIGH) {
    if (status)
      status = 0;
    else status = 1;
  }

  if (status) {
    if (sensor_grey.detect())
    {
      robot.forward(100) ;
      angle = magneto.getX();
      //Serial.println("front");
    }
    else // !detect
    {
      actualAngle = magneto.getX();
      diffe = diff(actualAngle, angle + 3);
      //Serial.println(diffe);
      if (diffe > 0) {
        left.front(100);
        left.stop();
        //Serial.println("right");
      }
      else {
        right.front(100);
        left.stop();
        //Serial.println("left");
      }
    }
  }
}
