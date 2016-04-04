#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor {
  private:
    int pin;
    int limit = 500;
     
  public:
    Sensor(int pin);
    int read();
    void setLimit(int limit);
    bool detect();
    int readMap(int begin, int end);
};

#endif

