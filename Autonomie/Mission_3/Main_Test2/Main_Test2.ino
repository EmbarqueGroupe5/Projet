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

bool status = false;

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_grey(SENSOR_GREY_PIN);

//Robot
Robot robot(left, right);

//Vars

void setup() {
  Serial.begin(115200);

  pinMode(PIN_SW0, INPUT_PULLUP);

  sensor_grey.setMode(SENSOR_MODE_MINUS);
  sensor_grey.setLimit(300); //Detecte en dessous de 400

  left.init();
  right.init();

}

void loop() {  

  if (digitalRead(PIN_SW0) == HIGH) {
    if (status)
      status = 0;
    else status = 1;
  }

  
    if (sensor_grey.detect())
    {
      robot.left(100) ;
      right.stop();
    }
    else 
      robot.right(100);
      left.stop();
}
