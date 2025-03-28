// PotiAlsByteNachSerial

void setup () {
  Serial.begin (9600);
}   // < setup

void loop () {
  Serial.write ((byte) map (analogRead (0), 0, 1023, 0, 255));
  delay (20);   // !!! nicht zu viel senden
}   // < loop
