#include "MagicServo.h"
#include "Sensor.h"

#include <Servo.h>

#define LEFT_SERVO_PIN 14
#define RIGHT_SERVO_PIN 15
#define SENSOR_FRONT_PIN 0

//Servos
MagicServo left(LEFT_SERVO_PIN, REVERSE_FRONT_ORIENTATION); // Constructeur
MagicServo right(RIGHT_SERVO_PIN, NORMAL_FRONT_ORIENTATION);// Constructeur

//Sensors
Sensor sensor_front(SENSOR_FRONT_PIN);

long vitesse = 0;
  
long chrono = 0; // valeur courante du chrono
  
long chrono_depart = 0; // valeur de départ du chrono
  
long duree_test = 3000; // test sur 3 secondes
  
volatile long nb_chgt = 0; // nb de changement etat Pin
  
// Gestion de l'interruption 0
  
void gere_int0() { 
    nb_chgt = nb_chgt + 1 ;  
}

void setup() {
  Serial.begin(9600);

  sensor_front.setLimit(600);

  left.init();
  right.init();

  chrono_depart = millis();

  attachInterrupt(12,gere_int0,CHANGE);

  right.front(100);
  left.front(100);
}

void loop() {
  chrono = millis();
  if (chrono - chrono_depart > duree_test) { 
 
   
 
   vitesse=nb_chgt*20;
   Serial.println(vitesse);            
     
   chrono_depart = millis(); 
   nb_chgt=0;
  }   
  /*for (int i = 1; i<100;++i) {
    right.front(i);
    Serial.print("i : ");
    Serial.println(i);
    Serial.print("val : ");
    Serial.println(right.get().read());
    Serial.println("");
    delay(1000);
  }*/
}
