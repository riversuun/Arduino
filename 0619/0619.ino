int motorPinA = 2;
int motorPinB = 3;
int enablePin = 11;

void setup()
{
  pinMode(motorPinA,OUTPUT);
  pinMode(motorPinB,OUTPUT);
  pinMode(enablePin,OUTPUT);
  analogWrite(enablePin,1000 );
}


void loop()
{
  digitalWrite(motorPinA,HIGH);
  digitalWrite(motorPinB,LOW);
  delay(1000);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,HIGH);
  delay(1000);
}
