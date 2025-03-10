#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(20); // this speeds up the simulation
  digitalWrite(21, HIGH);
  delay(20);
  digitalWrite(21, LOW);
  delay(50);
  digitalWrite(22, HIGH);
  delay(20);
  digitalWrite(22, LOW);
  delay(50);
  digitalWrite(23, HIGH);
  delay(20);
  digitalWrite(23, LOW);
  delay(50);
}
