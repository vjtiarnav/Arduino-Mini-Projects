void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(8,OUTPUT);  // Use internal pull-up
}

void loop() {
  int buttonState = digitalRead(2);
  Serial.print("Button state: ");
  Serial.println(buttonState); // 1 = not pressed, 0 = pressed
  if(buttonState == 0){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }
  delay(500);
}
