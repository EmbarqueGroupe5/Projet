#include "MagicServo.h"
#include "Sensor.h"

#include <WiFi101.h>
#include <Servo.h>
#include <BlynkSimpleWiFiShield101.h> // This part is for Ethernet stuff

#define LEFT_SERVO_PIN 15
#define RIGHT_SERVO_PIN 14
#define SENSOR_FRONT_PIN 0

MagicServo left(LEFT_SERVO_PIN, NORMAL_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, REVERSE_FRONT_ORIENTATION);// Constructeur

Sensor sensor_front(SENSOR_FRONT_PIN);
char auth[] = "6eaa7bc2a5c44b45848dc490d170e3eb"; // Put your Auth Token here.
bool status = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth , "Wifi_Arduino" , "aarduino" );  // Here your Arduino connects to the Blynk Cloud.:
  Serial.begin(9600);
  Serial.println("Start");

  sensor_front.setLimit(500);

  left.init();
  right.init();

  left.front(100);
  right.front(100);
}

BLYNK_WRITE(V0) //Virtual0
{
  if (param.asInt()==0){
    left.writeMicroseconds(1500);
    right.writeMicroseconds(1500);
    status = 0;
  }
  else {
    left.writeMicroseconds(700);
    right.writeMicroseconds(700);
    status = 1;
  }
}

BLYNK_WRITE(V1) //Virtual1
{
  if (param.asInt()==1){
    left.writeMicroseconds(1500);
    right.writeMicroseconds(1500);
    status = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (sensor_front.detect()) {
    left.back(100);
    delay(500);
  }
  else {
    left.front(100);
    right.front(100);
  }
  Serial.println(sensor_front.detect());
  delay(100);
}
