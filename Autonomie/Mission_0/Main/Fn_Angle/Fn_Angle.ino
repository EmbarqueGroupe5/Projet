void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
} 

#define DIR_LEFT_FORWARD 0 //700-1500ms
#define DIR_RIGHT_FORWARD 1 //1500-2300ms
#define DIR_LEFT_BACKWARD 1 //1500-2300ms
#define DIR_RIGHT_BACKWARD 0 //700-1500ms


int getAngle(int percent, int direction) {
  //Direction : 0 => 0-90° - 700-1500ms
  //            1 => 90-180° - 1500-2300ms

  if (direction == 0) //0-90°
    return map(percent, 0, 100, 1500, 700);
  else //90-180°
    return map(percent, 0, 100, 1500, 2300);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getAngle(20, 0));
  delay(1000);
}
