#include <Stepper.h>

// puller setup
const int stepsPerRevolution = 200; // see NEMA 17 motor specs
const int lowSpeed = 5;
const int highSpeed = 120;
const int stepPin = 8;
const int dirPin = 9;
Stepper puller(stepsPerRevolution, stepPin, dirPin);

// knob setup
const int potPin = A0;
int potVal = 0;

void setup()
{
  pinMode(potPin, INPUT);

  puller.setSpeed(lowSpeed);

  Serial.begin(9600);
}
void loop()
{

  // get the required speed from the potentiometer
  potVal = analogRead(potPin);
  int requiredSpeed = map(potVal, 0, 1023, lowSpeed, highSpeed);

  puller.setSpeed(requiredSpeed);

  puller.step(stepsPerRevolution);
}