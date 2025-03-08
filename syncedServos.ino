#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver drive = Adafruit_PWMServoDriver();

void setup(){
  Serial.begin(9600);
  Serial.println("New Test");

  drive.begin();
  drive.setPWMFreq(60);

  yield();
}

void loop(){

  int base = analogRead(0);
  base = map(base, 0, 1023, 140, 750);
  int first = analogRead(1);
  first = map(first, 0, 1023, 140, 680);
  int second = analogRead(2);
  second = map(second, 0, 1023, 140, 710);
  Serial.println(base);
  
  drive.setPWM(0, 0, base);
  drive.setPWM(1, 0, first);
  drive.setPWM(2, 0, second);
  delay(15);

}
