
#define BLYNK_PRINT Serial // Enables Serial Monitor
#include <WiFi101.h>
#include <Servo.h>
#include <BlynkSimpleWiFiShield101.h> // This part is for Ethernet stuff

char auth[] = "6eaa7bc2a5c44b45848dc490d170e3eb"; // Token Julien

//Servos
Servo left;
Servo right;

//Sensors
#define DIST_PIN A0

bool status = 0; //Statut du programme

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth , "Wifi_Arduino" , "aarduino" ); 

  //Servos
  left.attach(14);
  right.attach(15);

}

BLYNK_WRITE(V0) //Virtual0
{
  if (param.asInt()==0){
    left.writeMicroseconds(1500);
    right.writeMicroseconds(1500);
    status = 0; //Arret 
  }
  else {
    status = 1; //Marche
    left.writeMicroseconds(700);
    right.writeMicroseconds(700);
  }
}

BLYNK_WRITE(V1) //Virtual1
{
  if (param.asInt()==1){
    left.writeMicroseconds(1500);
    right.writeMicroseconds(1500);
    status = 0; //Arret
  }
}

void loop()
{
  Blynk.run(); // All the Blynk Magic happens here...

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!


  if (status) { //Programme actif
    int sensorValue = analogRead(DIST_PIN);
    //int distance = map(sensorValue, 0, 1023, 
    Serial.println(sensorValue);
  }
  
}

