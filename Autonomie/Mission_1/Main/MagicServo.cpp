#include "Arduino.h"
#include "MagicServo.h"
#include <Servo.h>

MagicServo::MagicServo(int pin, int orientation){
  this->pin = pin;
  this->frontOrientation = orientation;
  this->servo.attach(pin);

  //Init
  this->servo.writeMicroseconds(1500);
}

int MagicServo::getAngle(int direction, int speed) {
  if (this->frontOrientation == 0){ //Normal oriantation : 0-90° / 700-1500ms
    if (direction == DIRECTION_FRONT) //Front
      return map(speed, 0, 100, 1500, 700);
    else //Back
      return map(speed, 0, 100, 1500, 2300); 
  }
  else { //Reverse oriantation : 90-180° / 1500-2300ms
    if (direction == DIRECTION_FRONT) //Front
      return map(speed, 0, 100, 1500, 2300);
    else //Back
      return map(speed, 0, 100, 1500, 700);
  }
}

void MagicServo::stop(){
  this->servo.writeMicroseconds(1500);
}

void MagicServo::run(int direction, int speed){
  this->servo.writeMicroseconds(
    this->getAngle(direction, speed)
  );
}

void MagicServo::front(int speed){
  this->run(0, speed); //Front
}

void MagicServo::back(int speed){
  this->run(1, speed); //Back
}

void MagicServo::writeMicroseconds(int ms){
  this->servo.writeMicroseconds(ms);
}
