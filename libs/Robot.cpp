#include "Arduino.h"
#include "Robot.h"

Robot::Robot(MagicServo &left, MagicServo &right): s_left(left), s_right(right){}

void Robot::stop(){
  this->s_left.stop();
  this->s_right.stop();
}

void Robot::forward(int speed) {
  this->s_left.front(speed);
  this->s_right.front(speed);
}

void Robot::backward(int speed) {
  this->s_left.back(speed);
  this->s_right.back(speed);
}

void Robot::left(int speed) {
  this->s_left.back(speed);
  this->s_right.front(speed);
}

void Robot::right(int speed) {
  this->s_left.front(speed);
  this->s_right.back(speed);
}
