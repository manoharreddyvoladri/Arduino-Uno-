// This code is used in the Arduino Uno R3 for basic design when you used the stepper motor



#include<Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution,8,9,10,11);
int stepCount = 0;
void setup()
{
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading,0,1023,0,100);
  
  if(motorSpeed > 0){
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution/100);
  }
  Serial.print("Rotation: ");
  Serial.println(sensorReading);
  delay(10);
}
