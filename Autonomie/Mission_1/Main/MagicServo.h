#ifndef MagicServo_h
#define MagicServo_h

#include "Arduino.h"
#include <Servo.h>

#define DIRECTION_FRONT 1
#define DIRECTION_BACK -1

class MagicServo {
  private:
    Servo servo;
    int pin;
    int frontOrientation; //Setting 0:normal - 1: reverse
     
    int speed; //range 0 - 100
    //NOT NEEDED YET int actualDirection; //0: front / 1: back
    int getAngle(int direction, int speed);
  public:
    MagicServo(int pin, int orientation);
    void stop();
    void run(int direction, int speed);
    void front(int speed);
    void back(int speed);
    void writeMicroseconds(int ms);
};

#endif

