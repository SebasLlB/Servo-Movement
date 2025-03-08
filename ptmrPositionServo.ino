#include <Wire.h>
#include <Servo.h>

Servo motor;

int val;

void setup(){
  motor.attach(9);
}

void loop(){
  val = analogRead(0);
  val = map(val, 0, 1023, 0, 180);
  motor.write(val);
  delay(15);
}
