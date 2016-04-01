#ifndef Robot_h
#define Robot_h

#include "Arduino.h"
#include "MagicServo.h"

class Robot {
  private:
    MagicServo s_left;
    MagicServo s_right;

  public:
    Robot(MagicServo &left, MagicServo &right);
    void stop();
    void forward(int speed);
    void backward(int speed);
    void left(int speed);
    void right(int speed);
};

#endif

