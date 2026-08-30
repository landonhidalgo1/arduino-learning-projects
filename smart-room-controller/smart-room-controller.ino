#include <Servo.h>
Servo myServo;

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pirPin = 7;

const int lightPin = A0;
const int ledPin = 6;
const int lightThreshold = 300;



void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  myServo.attach(9);
  myServo.write(90);

  lcd.begin(16, 2);
  lcd.print("Smart Room");
  delay(1500);
  lcd.clear();
}


void loop(){

int motionState = digitalRead(pirPin);

Serial.print("Motion: ");
Serial.println(motionState);

delay(200);


int lightValue = analogRead(lightPin);

Serial.print("Light Level: ");
Serial.println(lightValue);

if (lightValue < lightThreshold && motionState == HIGH) {
  digitalWrite(ledPin, HIGH);
}
else {
  digitalWrite(ledPin, LOW);
}

if (motionState == HIGH) {
  myServo.write(90);
}
else {
  myServo.write(0);
}

delay(250);

lcd.setCursor(0, 0);
lcd.print("LIGHT: ");

if (lightValue < lightThreshold) {
  lcd.print("DARK ");
}
else {
  lcd.print("BRIGHT");
}

lcd.setCursor(0, 1);
lcd.print("ROOM: ");

if(motionState == HIGH) {
  lcd.print("MOTION");
}
else {
  lcd.print("EMPTY ");
}
}

