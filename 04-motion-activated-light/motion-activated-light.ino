const int pirPin = 2;
const int ledPin = 7;

void setup() {
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  int motionState = digitalRead(pirPin);

  Serial.println(motionState);

  if (motionState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}