#include<Servo.h>
Servo myServo;

void setup() {
  myServo.attach(2);
  Serial.begin(9600);
}


void loop() {
  int potValue = analogRead(A0);

  int angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Potentiometer: ");
  Serial.println(potValue);

  Serial.print("Servo Angle: ");
  Serial.println(angle);

  delay(100);
  }