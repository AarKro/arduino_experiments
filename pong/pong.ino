// DreiPotisAlsStringNachSerial

void setup () {
  Serial.begin (9600);
}   // < setup

void loop () {
  Serial.print (analogRead (0));
  Serial.print (",");
  Serial.print (analogRead (1));
  Serial.print (";");
  delay (20); 
}   // < loop
