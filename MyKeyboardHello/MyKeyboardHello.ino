// MyKeyboardHello
// Einfachbsp. fuer Verwendung der Keyboard library
// Schaltung: Gnd --- Taster --- Digital Pin 2
// Markus Sing, Jan 2018

#include "Keyboard.h"

void setup () {
  pinMode (2, INPUT_PULLUP);
  Keyboard.begin ();
  delay (2000);   // etwas delay hier sinnvoll
}   // < setup

void loop () {
  if (digitalRead (2) == LOW) {
    Keyboard.println ("hello");
    delay (500);   // verhindert Kettenreaktion (Taster ja sicher
                   // etwas laenger als 20 ms gedrueckt)
  }
  delay (20);
}   // < loop

