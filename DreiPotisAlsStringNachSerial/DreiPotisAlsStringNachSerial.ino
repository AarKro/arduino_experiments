// DreiPotisAlsStringNachSerial

void setup () {
  Serial.begin (9600);
}   // < setup

void loop () {
  Serial.print (analogRead (0));
  Serial.print (",");
  Serial.print (analogRead (1));
  Serial.print (",");
  Serial.print (analogRead (2));
  Serial.print (";");   // !!! kein Zeilenende, da Probleme
                        //     mit Linux, Windoofs, Mac
  delay (20);   // !!! nicht zu viel senden
}   // < loop
