#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

#define SENSOR_MODE_MINUS 0
#define SENSOR_MODE_PLUS 1

class Sensor {
  private:
    int pin;
    int limit = 500;
    int operatorMode = SENSOR_MODE_PLUS;
     
  public:
    Sensor(int pin);
    int read();
    void setLimit(int limit);
    bool detect();
    int readMap(int begin, int end);
    void setMode(int operatorMode);
};

#endif

