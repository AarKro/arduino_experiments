// VonProcessingAlsByteNachSerial

byte wert;

void setup () {
  Serial.begin (9600);
}   // < setup

void loop () {
  if (Serial.available ()) {   // wert
    wert = Serial.read ();     // ein-
  }                            // lesen
  analogWrite (11, wert);   // !!! PWM Pin 13:
                            //     nur beim Leonardo
}   // < loop
