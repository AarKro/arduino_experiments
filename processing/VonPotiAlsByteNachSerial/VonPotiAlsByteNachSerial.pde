// VonPotiAlsByteNachSerial

import processing.serial.*;
Serial port;   // erstellt ein Objekt der Klasse Serial
int wert;   // !!! int, nicht byte
            //     Java: byte von -128 bis +127

void setup () {
  println (Serial.list ());   // vorhandene serielle Ports anzeigen
  String portName = Serial.list () [3];   // !!! den richtigen
                                          //     seriellen Port
                                          //     auswaehlen
                                          // !!! [.] startet bei 0
  port = new Serial (this, portName, 9600);   // auf diesen verbinden
  colorMode (HSB, 256, 100, 100);
}   // < setup

void draw () {
  if (port.available () > 0) {   // wert
    wert = port.read ();         // ein-
  }                              // lesen
  println (wert);   // -> Konsole, unnoetig, aber ggf. hilfreich
  background (wert, 100, 100);
}   // < draw
