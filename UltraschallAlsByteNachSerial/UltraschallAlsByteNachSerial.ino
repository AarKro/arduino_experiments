// UltraschallAlsByteNachSerial.ino

#include <Ultrasonic.h>

Ultrasonic ultrasonic (12, 13);   // Trig: 12, Echo: 13
int distance;

void setup () {
  Serial.begin (9600);
}   // < setup

void loop () {
  distance = ultrasonic.read();
  Serial.print(distance);
  if (distance <= 255) {
    Serial.write ((byte) distance);
  }
  else {
    Serial.write ((byte) 0);
  }
  delay (100);   // !!! nicht zu viel senden
}   // < loop
