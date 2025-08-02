#include <Servo.h>

// Pin definitions
const int buttonPin = 2;
const int buzzerPin = 8;
const int ledPin = 9;
const int servoPin = 10;

// Servo object
Servo myServo;

// Angle tracking
int currentAngle = 0;
int targetAngle = 0;

// Speed control (delay between degree steps in milliseconds)
int speedDelay = 0.1;  // Increase for slower movement, decrease for faster

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(currentAngle);  // Start at 0 degrees
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    targetAngle = 90;  // Move to 90 degrees
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    targetAngle = 0;   // Move back to 0 degrees
  }

  // Move servo toward target angle slowly
  if (currentAngle < targetAngle) {
    currentAngle++;
    myServo.write(currentAngle);
    delay(speedDelay);
  } else if (currentAngle > targetAngle) {
    currentAngle--;
    myServo.write(currentAngle);
    delay(speedDelay);
  }
}
