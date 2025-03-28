// ScrollbarAlsByteNachSerial

import processing.serial.*;
Serial port;   // erstellt ein Objekt der Klasse Serial
HScrollbar hs;   // horizontal

void setup () {
  println (Serial.list ());   // vorhandene serielle Ports anzeigen
  String portName = Serial.list () [0];   // !!! den richtigen
                                          //     seriellen Port
                                          //     auswaehlen
                                          // !!! [.] startet bei 0
  port = new Serial (this, portName, 9600);   // auf diesen verbinden
  size (265, 26);
  background (255, 255, 255);
  hs = new HScrollbar (5, 13, 255, 16, 5);
                    // |   |   |    |  '-> Empfindlichkeit
                    // |   |   |    '-> Hoehe
                    // |   |   '-> Breite
                    // |   '-> mittlere Hoehe bzgl. oberer Rand
                    // '-> linker Rand
  frameRate (20);   // !!! ggf., um nicht zu viel zu senden
                    //     default frameRate = 60
}   // < setup

void draw () {
  println (hs.getPos ());   // -> Konsole, unnoetig,
                            //    aber ggf. hilfreich
  port.write ((byte) hs.getPos ());   // wert rausschreiben
                                      // !!! map hier nicht noetig, da
                                      //     Scrollbarbreite = 255 :-)
  hs.update ();
  hs.display ();
}   // < draw

// ab hier: nur verwenden, nicht aendern :-)
// kopiert von Beispiele/GUI/Scrollbar
// !!! getPos jedoch noch korrigiert
class HScrollbar {
  int swidth, sheight;    // width and height of bar
  float xpos, ypos;       // x and y position of bar
  float spos, newspos;    // x position of slider
  float sposMin, sposMax; // max and min values of slider
  int loose;              // how loose/heavy
  boolean over;           // is the mouse over the slider?
  boolean locked;
  float ratio;

  HScrollbar (float xp, float yp, int sw, int sh, int l) {
    swidth = sw;
    sheight = sh;
    int widthtoheight = sw - sh;
    ratio = (float)sw / (float)widthtoheight;
    xpos = xp;
    ypos = yp-sheight/2;
    spos = xpos + swidth/2 - sheight/2;
    newspos = spos;
    sposMin = xpos;
    sposMax = xpos + swidth - sheight;
    loose = l;
  }

  void update() {
    if (overEvent()) {
      over = true;
    } else {
      over = false;
    }
    if (mousePressed && over) {
      locked = true;
    }
    if (!mousePressed) {
      locked = false;
    }
    if (locked) {
      newspos = constrain(mouseX-sheight/2, sposMin, sposMax);
    }
    if (abs(newspos - spos) > 1) {
      spos = spos + (newspos-spos)/loose;
    }
  }

  float constrain(float val, float minv, float maxv) {
    return min(max(val, minv), maxv);
  }

  boolean overEvent() {
    if (mouseX > xpos && mouseX < xpos+swidth &&
       mouseY > ypos && mouseY < ypos+sheight) {
      return true;
    } else {
      return false;
    }
  }

  void display() {
    noStroke();
    fill(204);
    rect(xpos, ypos, swidth, sheight);
    if (over || locked) {
      fill(0, 0, 0);
    } else {
      fill(102, 102, 102);
    }
    rect(spos, ypos, sheight, sheight);
  }

  float getPos() {
    // Convert spos to be values between
    // 0 and the total width of the scrollbar
    return spos * ratio - xpos;
                 // !!! - xpos: correction (Markus Sing)
  }
}   // < class HScrollbar
