#include <Servo.h>

const int ldrPin = A0;
const int ledPin = 7;
const int threshold = 500; // Adjust depending on ambient light
Servo myServo;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myServo.attach(9); // Servo control pin
  myServo.write(0);  // Initial servo position
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // For debugging LDR values
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue); // Check LDR value in Serial Monitor

  if (ldrValue < threshold) { // It's dark
    myServo.write(0);
    digitalWrite(ledPin, LOW);
  } else {
    myServo.write(90);
    digitalWrite(ledPin, HIGH);
  }

  delay(100); // Small delay to avoid rapid switching
}
