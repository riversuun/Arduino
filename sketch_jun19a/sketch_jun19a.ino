#include <Servo.h>

Servo myservo;

int motorPinA = 2;
int motorPinB = 3;
int enablePin = 11;

void setup()
{
  myservo.attach(9);
  pinMode(motorPinA,OUTPUT);
  pinMode(motorPinB,OUTPUT);
  pinMode(enablePin,OUTPUT);
  analogWrite(enablePin,1000);
}


void loop()
{
  myservo.write(130);
  digitalWrite(motorPinA,HIGH);
  digitalWrite(motorPinB,LOW);
  delay(1000);
  myservo.write(50);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,HIGH);
  delay(1000);
}
