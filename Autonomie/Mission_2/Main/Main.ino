#include "MagicServo.h"
#include "Sensor.h"


#define BLYNK_PRINT Serial
#include <WiFi101.h>
#include <Servo.h>
#include <BlynkSimpleWiFiShield101.h> // This part is for Ethernet stuff

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15
#define SENSOR_FRONT_PIN 0

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);

//Vars
char auth[] = "6eaa7bc2a5c44b45848dc490d170e3eb"; // Put your Auth Token here.
bool status = 0;
char wifi_hotspot[] = "Wifi_Arduino";
char wifi_password[] = "aarduino";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth , wifi_hotspot, wifi_password);  // Here your Arduino connects to the Blynk Cloud.:

  sensor_front.setLimit(600);

  left.init();
  right.init();
}
test(correct)
{
  assertEqual(sensor_front.detect(),1);
}

test(incorrect)
{
  assertNotEqual(sensor_front.detect(),1);
}

BLYNK_WRITE(V0) //Start & Stop
{
  if (param.asInt() == 0) {
    left.stop();
    right.stop();
    status = 0;
  }
  else {
    left.writeMicroseconds(700);
    right.writeMicroseconds(700);
    status = 1;
  }
}

BLYNK_WRITE(V1) //STOP
{
  if (param.asInt() == 1) {
    left.stop();
    right.stop();
    status = 0;
  }
}

void loop() {
  Blynk.run();
  if (digitalRead(PIN_SW0) == HIGH)
    status = 1;
    
  if (status) {
    if (sensor_front.detect()) {
      left.back(100);
      
      delay(500);
    }
    else {
      left.front(100);
      right.front(100);
    }
  }
  Test::run();

}
