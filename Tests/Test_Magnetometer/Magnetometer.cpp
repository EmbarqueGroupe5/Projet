#include "Arduino.h"
#include "Vector.h"
#include "Magnetometer.h"

Magnetometer::Magnetometer(int pin){
  this->pin = pin;
}

std::vector<3> Magnetometer::getVector() {
	std::vector<3> euler;
  uint8_t buffer[6];
  memset (buffer, 0, 6);

  int16_t x, y, z;
  x = y = z = 0;

  /* Read vector data (6 bytes) */
  readLen((adafruit_bno055_reg_t)vector_type, buffer, 6);

  x = ((int16_t)buffer[0]) | (((int16_t)buffer[1]) << 8);
  y = ((int16_t)buffer[2]) | (((int16_t)buffer[3]) << 8);
  z = ((int16_t)buffer[4]) | (((int16_t)buffer[5]) << 8);

  /* Convert the value to an appropriate range and assign the value to the Vector type */
  
  /* Convert to EULER (angle) */
  /* 1 degree = 16 LSB */
  euler[0] = ((double)x)/16.0;
  euler[1] = ((double)y)/16.0;
  euler[2] = ((double)z)/16.0;
      
  
  return euler;
}

bool Magnetometer::readLen(adafruit_bno055_reg_t reg, byte * buffer, uint8_t len) {
  Wire.beginTransmission(_address);
  Wire.write((uint8_t)reg);

  Wire.endTransmission();
  Wire.requestFrom(_address, (byte)len);

  for (uint8_t i = 0; i < len; i++)
  {
      buffer[i] = Wire.read();
  }

  return true;
}

bool Magnetometer::write8(adafruit_bno055_reg_t reg, byte value) {
  Wire.beginTransmission(_address);
  
Wire.write((uint8_t)reg);
Wire.write((uint8_t)value);
  
  Wire.endTransmission();
  return true;
}