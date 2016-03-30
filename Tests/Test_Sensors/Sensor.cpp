#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int pin){
  this->pin = pin;
}

int Sensor::read(){
  return analogRead(this->pin);
}

void Sensor::setLimit(int limit){
  this->limit = limit;
}

bool Sensor::detect(){
  if (this->operatorMode == SENSOR_MODE_PLUS) //Mode supérieur
      return (this->read() > this->limit);
  else //Mode inférieur
    return (this->read() < this->limit);
}

int Sensor::readMap(int begin, int end) {
  return map(this->read(), 0, 1023, begin, end);
}

void Sensor::setMode(int operatorMode){
  this->operatorMode = operatorMode;
}

