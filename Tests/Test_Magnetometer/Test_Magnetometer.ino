#include "Magnetometer.h"

//Magnetometer
Magnetometer magneto;

void setup() {
  Serial.begin(9600);

  while (!magneto.begin()) {
    Serial.println("No BNO !");
    delay(1000);
  }
}



void loop() {
  //Magnetometer
  
  Serial.println(diff(330, 200));
  delay(1000);
}
