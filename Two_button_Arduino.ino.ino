// Pin definitions
const int ledPin1 = 13;
const int ledPin2 = 12;
const int buttonPin1 = 2;
const int buttonPin2 = 3;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

}
void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);

  if(buttonState1 == 0){
    digitalWrite(ledPin1, HIGH);
  }
  else if(buttonState2 == 0){
    digitalWrite(ledPin2, HIGH);
  }
  else{
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
}
