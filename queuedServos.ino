#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver drive = Adafruit_PWMServoDriver();

int max = 500;
int min = 200;

void setup(){
  Serial.begin(9600);
  Serial.println("New Test");

  drive.begin();
  drive.setPWMFreq(60);

  yield();
}

void loop(){
  for(int motor = 0; motor < 6; motor++){
    drive.setPWM(motor, 0, max);
    delay(300);
  }
  
  for(int motor = 0; motor < 6; motor++){
    drive.setPWM(motor, 0, min);
    delay(300);
  }
}
