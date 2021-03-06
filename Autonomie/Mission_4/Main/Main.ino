#include "MagicServo.h"
#include "Sensor.h"
#include "Robot.h"
#include <ArduinoUnit.h>

#define BLYNK_PRINT Serial
#include <WiFi101.h>
#include <Servo.h>
#include <BlynkSimpleWiFiShield101.h>

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15

#define SENSOR_FRONT_PIN 0
#define SENSOR_BACK_PIN 1
#define SENSOR_LEFT_PIN 2
#define SENSOR_RIGHT_PIN 3
#define SENSOR_LUM_PIN 4
#define SENSOR_GREY_PIN 5

#define HIGH 0
#define LOW 1

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);
Sensor sensor_left(SENSOR_LEFT_PIN);
Sensor sensor_right(SENSOR_RIGHT_PIN);

//Robot
Robot robot(left, right);

//Vars
char auth[] = "6eaa7bc2a5c44b45848dc490d170e3eb"; // Blynk Token
bool status = 0;
char wifi_hotspot[] = "Wifi_Arduino";
char wifi_password[] = "aarduino";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth , wifi_hotspot, wifi_password);  // Connect to Blynk Cloud

  pinMode(PIN_SW0, INPUT_PULLUP);

  sensor_front.setLimit(400);
  sensor_left.setLimit(400);
  sensor_right.setLimit(400);

  left.init();
  right.init();
}
test(one)
{
  assertEqual(sensor_front.detect(),1);
  
}

test(two)
{
  assertEqual(sensor_left.detect(),1);
  
}

test(three)
{
  assertEqual(sensor_right.detect(),1);
  
}

BLYNK_WRITE(V0) //Start & Stop
{
  if (param.asInt() == 0) {
    left.stop();
    right.stop();
    status = 0;
   }
  else
    status = 1;
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
  Test::run();

  if (digitalRead(PIN_SW0) == HIGH) {
    if (status)
      status = 0;
     else status = 1;
  }
    
  if (status) {
    if (sensor_right.detect() || sensor_left.detect() && !sensor_front.detect()) { //Suit droite & voie libre
      robot.forward(20);
    }
    else if (sensor_right.detect() && sensor_left.detect() && sensor_front.detect()) { //Suit droite & bloqué : stop tourne gauche
      robot.left(20);
    }
    else if (!sensor_right.detect() && !sensor_left.detect() && !sensor_front.detect()) {
      robot.right(20);
    }
    else 
      robot.stop();
    
  }

}
