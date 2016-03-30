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
  return (this->read() > this->limit);
}

int Sensor::readMap(int begin, int end) {
  return map(this->read(), 0, 1023, begin, end);
}

