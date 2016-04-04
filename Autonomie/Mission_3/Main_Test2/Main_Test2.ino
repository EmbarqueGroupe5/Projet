#include "MagicServo.h"
#include "Sensor.h"
#include "Magnetometer.h"
#include "Robot.h"

#define BLYNK_PRINT Serial
#include <WiFi101.h>
#include <BlynkSimpleWiFiShield101.h>

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15

#define SENSOR_FRONT_PIN 0
#define SENSOR_BACK_PIN 1
#define SENSOR_LEFT_PIN 2
#define SENSOR_RIGHT_PIN 3
#define SENSOR_LUM_PIN 5
#define SENSOR_GREY_PIN 4

#define HIGH 0
#define LOW 1

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);
Sensor sensor_back(SENSOR_BACK_PIN);
Sensor sensor_left(SENSOR_LEFT_PIN);
Sensor sensor_right(SENSOR_RIGHT_PIN);
Sensor sensor_lum(SENSOR_LUM_PIN);
Sensor sensor_grey(SENSOR_GREY_PIN);

//Robot
Robot robot(left, right);

//Vars
char auth[] = "6eaa7bc2a5c44b45848dc490d170e3eb"; // Blynk Token
bool status = 0;
char wifi_hotspot[] = "Wifi_Arduino";
char wifi_password[] = "aarduino";

float angle = 0.0;

//Magnetometer
Magnetometer magneto;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth , wifi_hotspot, wifi_password);  // Connect to Blynk Cloud

  pinMode(PIN_SW0, INPUT_PULLUP);

  sensor_front.setLimit(600);
  sensor_back.setMode(SENSOR_MODE_MINUS); //Valeur faible si detection
  sensor_back.setLimit(150);
  sensor_left.setLimit(600);
  sensor_right.setLimit(600);
  sensor_grey.setMode(SENSOR_MODE_MINUS);
  sensor_grey.setLimit(400); //Detecte en dessous de 400

  left.init();
  right.init();

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

  if (digitalRead(PIN_SW0) == HIGH) {
    if (status)
      status = 0;
    else status = 1;
  }

  
    if (sensor_grey.detect())
    {
      robot.left(100) ;
    }
    else 
      robot.right(100);
  
}
