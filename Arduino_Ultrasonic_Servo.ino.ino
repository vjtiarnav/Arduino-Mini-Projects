#include <Servo.h>

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 8;
const int redLED = 7;
const int servoPin = 6;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0);  // Initial position
  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  // Send 10us pulse to trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (in cm)
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 4.0) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    myServo.write(90);  // Raise
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    myServo.write(0);   // Stay down
  }

  delay(200); // Small delay for stability
}
