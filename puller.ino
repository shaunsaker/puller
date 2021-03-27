// Define pin connections & motor's steps per revolution
const int stepPin = 8;
const int dirPin = 9;
const int potPin = A0;
int potVal = 0;
const int stepsPerRevolution = 200; // see NEMA 17 motor specs
const int motorDelayHigh = 500;
const int motorDelayLow = 2000;

void setup()
{
  Serial.begin(9600);

  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(potPin, INPUT);
}
void loop()
{
  // read the potentiometer value
  potVal = analogRead(potPin);
  int delay = map(potVal, 0, 1023, motorDelayLow, motorDelayHigh);
  Serial.println(delay);

  // Set motor direction clockwise
  digitalWrite(dirPin, HIGH);

  for (int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delay);
  }
}