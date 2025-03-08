#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver drive = Adafruit_PWMServoDriver();

int degreesMin = 80;
int degreesMax = 120;
int pwmMin = 150;
int pwmMax = 670;
int onPose = 0, offPose = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("New Test");
  pinMode(2, INPUT);

  drive.begin();
  drive.setPWMFreq(60);

  offPose = map(degreesMin, 0, 180, pwmMin, pwmMax);
  onPose = map(degreesMax, 0, 180, pwmMin, pwmMax);

  yield();
}

void loop(){
  int base = analogRead(0);
  int first = analogRead(1);
  int second = analogRead(2);

  base = map(base, 0, 1023, 150, 700);
  first = map(first, 0, 1023, 150, 700);
  second = map(second, 0, 1023, 150, 700);

  drive.setPWM(0, 0, base);
  drive.setPWM(1, 0, first);
  drive.setPWM(2, 0, second);

  if(digitalRead(2) == LOW)
  {
    drive.setPWM(3, 0, offPose);
  }else{
    drive.setPWM(3, 0, onPose);
  }
  delay(15);
}
