// VonDreiPotisAlsStringNachSerial

import processing.serial.*;
Serial port;   // erstellt ein Objekt der Klasse Serial
int potiX, potiY, potiZ;
float sX, sY, sZ;

void setup () {
  println (Serial.list ());   // vorhandene serielle Ports anzeigen
  String portName = Serial.list () [2];   // !!! den richtigen
                                          //     seriellen Port
                                          //     auswaehlen
                                          // !!! [.] startet bei 0
  port = new Serial (this, portName, 9600);   // auf diesen verbinden
  port.bufferUntil (';');   // serialEvent ausloesen,
                            // wenn dies gelesen
                            
  size(600, 600, P3D);
  colorMode (HSB, 256, 100, 100);
  
  sX = width / 2 - 200 + random(400);
  sY= height / 2 - 200 + random(400);
  sZ = 0 + random(400);
}   // < setup

void draw () {
  background(0, 0, 100);
  pushMatrix();
  translate(sX, sY, sZ);
  fill(255, 100, 100);
  sphere(30);
  popMatrix();
  translate (potiX, potiY, potiZ);
  fill(100, 100, 100);
  sphere(30);
  
  if (abs(potiX - sX) < 30 && abs(potiY - sY) < 30 && abs(potiZ - sZ) > 30) {
    text("GEWONNEN", 50, 50);
  }
}   // < draw

void serialEvent (Serial port) {
  String gelesen = port.readStringUntil (';');
  if (gelesen != null) {   // nicht nur ';' gesehen
                           // (sonst ggf. Problem am Anfang)
    String[] farben = split (gelesen, ",");   // in Teile zerlegen
    if (farben.length >= 3) {   // alle 3 da (sonst ggf.
                                // Problem am Anfang)
                                
      potiX = (int) map (int (farben[0]), 0, 1023, 0, width);
      potiY = (int) map (int (farben[1]), 0, 1023, 0, height);
      potiZ = (int) map (int (farben[2].replaceAll (";", "")), 0, 1023, 0, 600);
      
      println(farben[0], potiX, farben[1], potiY, farben[2], potiZ); 
    }
  }
}   // < serialEvent
