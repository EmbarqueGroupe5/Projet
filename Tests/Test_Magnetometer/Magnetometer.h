#ifndef Magnetometer_h
#define Magnetometer_h

#include "Arduino.h"

//Address enums

class Magnetometer {
  public:
    Magnetometer(int pin);
    

  private:
    bool  readLen ( adafruit_bno055_reg_t, byte* buffer, uint8_t len );
    bool  write8  ( adafruit_bno055_reg_t, byte value );
    std::vector<3> getVector();
};

#endif

