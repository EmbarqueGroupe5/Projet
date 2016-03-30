#include "Arduino.h"
#include "Magnetometer.h"
#include "utility/vector.h"

/*Magnetometer::Magnetometer(){
  }*/

bool Magnetometer::begin()
{
  bno055_opmode_t mode = OPERATION_MODE_NDOF;
  /* Enable I2C */
  Wire.begin();

  /* Make sure we have the right device */
  uint8_t id = read8(BNO055_CHIP_ID_ADDR);
  if (id != BNO055_ID)
  {
    delay(1000); // hold on for boot
    id = read8(BNO055_CHIP_ID_ADDR);
    if (id != BNO055_ID) {
      return false;  // still not? ok bail
    }
  }

  /* Switch to config mode (just in case since this is the default) */
  setMode(OPERATION_MODE_CONFIG);

  /* Reset */
  write8(BNO055_SYS_TRIGGER_ADDR, 0x20);
  while (read8(BNO055_CHIP_ID_ADDR) != BNO055_ID)
  {
    delay(10);
  }
  delay(50);

  /* Set to normal power mode */
  write8(BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
  delay(10);

  write8(BNO055_PAGE_ID_ADDR, 0);

  write8(BNO055_SYS_TRIGGER_ADDR, 0x0);
  delay(10);
  /* Set the requested operating mode */
  setMode(mode);
  delay(20);

  return true;
}

imu::vector<3> Magnetometer::getVector() {
  std::vector<3> euler;
  uint8_t buffer[6];
  memset (buffer, 0, 6);

  int16_t x, y, z;
  x = y = z = 0;

  /* Read vector data (6 bytes) */
  readLen((bno055_reg_t)VECTOR_EULER, buffer, 6); // Lit à l'adresse correspondante du EULER (enum registre)

  x = ((int16_t)buffer[0]) | (((int16_t)buffer[1]) << 8);
  y = ((int16_t)buffer[2]) | (((int16_t)buffer[3]) << 8);
  z = ((int16_t)buffer[4]) | (((int16_t)buffer[5]) << 8);

  /* Convert the value to an appropriate range and assign the value to the Vector type */

  /* Convert to EULER (angle) */
  /* 1 degree = 16 LSB */
  euler[0] = ((double)x) / 16.0;
  euler[1] = ((double)y) / 16.0;
  euler[2] = ((double)z) / 16.0;

  return euler;
}

void Magnetometer::setMode(bno055_opmode_t mode)
{
  _mode = mode;
  write8(BNO055_OPR_MODE_ADDR, _mode);
  delay(30);
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
