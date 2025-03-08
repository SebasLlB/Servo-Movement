#include <Servo.h>

Servo motor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.attach(5);
  pinMode(2, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(2) == LOW){
  motor.write(10);
 }else {
  motor.write(200);
 }
}
