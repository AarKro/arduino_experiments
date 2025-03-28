#include <AbsMouse.h>

// open drums on https://www.musicca.com/drums

void setup() {
  AbsMouse.init(3456, 2234);
}

int frequency = 250;
int loopCount = 0;
void loop() {
  loopCount += 1;

  hihat();
  base();
  delay(frequency);

  hihat();
  delay(frequency);

  hihat();
  snare();
  delay(frequency);

  hihat();
  delay(frequency);

  if (false && loopCount % 8 == 0) {
    highTom();
    delay(frequency / 3);
    highTom();
    delay(frequency / 3);
    highTom();
    delay(frequency / 3);
    highTom();
    delay(frequency / 3);
    lowTom();
    delay(frequency / 3);
    lowTom();
    delay(frequency / 3);
    lowTom();
    delay(frequency / 3);
    lowTom();
    delay(frequency / 3);
    floorTom();
    delay(frequency / 3);
    floorTom();
    delay(frequency / 3);
    floorTom();
    delay(frequency / 3);
    floorTom();
    delay(frequency / 3);
    hihihat();
    delay(frequency * 4);
  }

  // attempt at jazz
  /*
  hihihihat();
  delay(frequency * 2);

  snare();
  delay(frequency / 2);
  hihihihat();
  delay(frequency);
  hihihihat();
  delay(frequency);
  */

}
void hihat() {
  AbsMouse.move(1400, 1270);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void base() {
  AbsMouse.move(1900, 1550);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void snare () {
  AbsMouse.move(1600, 1350);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void highTom () {
  AbsMouse.move(1850, 1300);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void lowTom () {
  AbsMouse.move(2150, 1300);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void floorTom () {
  AbsMouse.move(2250, 1500);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void hihihat () {
  AbsMouse.move(1600, 1150);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}

void hihihihat () {
  AbsMouse.move(2250, 1300);
  AbsMouse.press(MOUSE_LEFT);
  AbsMouse.release(MOUSE_LEFT);
}


