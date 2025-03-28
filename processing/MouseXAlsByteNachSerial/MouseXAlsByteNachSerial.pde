// MouseXAlsByteNachSerial

import processing.serial.*;
Serial port;   // erstellt ein Objekt der Klasse Serial

void setup () {
  println (Serial.list ());   // vorhandene serielle Ports anzeigen
  String portName = Serial.list () [3];   // !!! den richtigen
                                          //     seriellen Port
                                          //     auswaehlen
                                          // !!! [.] startet bei 0
  port = new Serial (this, portName, 9600);   // auf diesen verbinden
  size (256, 120);
  frameRate (20);   // !!! ggf., um nicht zu viel zu senden
                    //     default frameRate = 60
}   // < setup

void draw () {
  port.write ((byte) mouseX);   // wert rausschreiben
                                // !!! map hier nicht noetig, da
                                //     Fensterbreite = 256 :-)
}   // < draw
