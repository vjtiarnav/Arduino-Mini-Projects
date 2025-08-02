const int ldrPin = A0;       // LDR analog pin
const int ledPin = 2;        // LED connected to pin 2
const int threshold = 900;   // Adjust based on testing (0 = dark, 1023 = bright)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);        // Optional: to read LDR values in Serial Monitor
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);  // View LDR value in Serial Monitor

  if (ldrValue < threshold) {
    digitalWrite(ledPin, LOW);  // Turn on LED in darkness
  } else {
    digitalWrite(ledPin, HIGH);   // Turn off LED in brightness
  }

  delay(1000);  // Small delay to stabilize readings
}
