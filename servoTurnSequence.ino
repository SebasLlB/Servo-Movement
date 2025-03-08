#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver drive = Adafruit_PWMServoDriver();

int min = 300;
int max = 600;

void setup(){
  Serial.begin(9600);
  Serial.println("New test");
}

void loop(){
  for(int motor = 0; motor < 6; motor++){
    drive.setPWM(motor, 0, min);
  }
  for(int motor = 0; motor < 6; motor++){
    drive.setPWM(motor, 0, max);
  }
}
