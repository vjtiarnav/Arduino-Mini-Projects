void setup() {
  pinMode(7, OUTPUT);  // RED LED
  pinMode(6, OUTPUT);  // YELLOW LED
  pinMode(5, OUTPUT);  // GREEN LED
  Serial.begin(9600);
}

void loop() {
  // RED LED for 10 seconds with countdown
  digitalWrite(7, HIGH);
  for (int i = 10; i >= 1; i--) {
    Serial.print("RED - Time Remaining: ");
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(7, LOW);

  // YELLOW LED for 15 seconds with countdown
  digitalWrite(6, HIGH);
  for (int i = 15; i >= 1; i--) {
    Serial.print("YELLOW - Time Remaining: ");
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(6, LOW);

  // GREEN LED for 17 seconds with countdown
  digitalWrite(5, HIGH);
  for (int i = 17; i >= 1; i--) {
    Serial.print("GREEN - Time Remaining: ");
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(5, LOW);
}
