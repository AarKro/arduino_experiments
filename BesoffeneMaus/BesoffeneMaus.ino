// BesoffeneMaus
// Einfachbsp. fuer Verwendung der Mouse library
// !!! - Mauszeiger sollte nach dem Hochladen etwa in der Mitte
//       stehen
//     - Leonardo ausstecken -> Mauskontrolle zurueck an ...
//     ggf. TBD: Button fuer Ein / Aus einbauen
// Markus Sing, Jan 2018

#include "Mouse.h"

void setup () {
  Mouse.begin();
}   // < setup

void loop () {
  Mouse.move (-3 + random (7), -3 + random (7), 0); 
  delay (20);
}   // < loop

