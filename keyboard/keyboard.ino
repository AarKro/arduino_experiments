#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(" ");
  Keyboard.releaseAll();

  delay(200);

  Keyboard.press("w");
  Keyboard.releaseAll();
  Keyboard.press("o");
  Keyboard.releaseAll();
  Keyboard.press("r");
  Keyboard.releaseAll();
  Keyboard.press("d");
  Keyboard.releaseAll();
  
  delay(100);

  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void loop() {

}
