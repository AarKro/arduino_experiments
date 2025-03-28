/*
  Single Frame
  
  Displays single frames using matrix.loadFrame
  
  See the full documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix
*/

#include "Arduino_LED_Matrix.h"   // Include the LED_Matrix library
#include "frames.h"               // Include a header file containing some custom icons

ArduinoLEDMatrix matrix;          // Create an instance of the ArduinoLEDMatrix class

void setup() {
  Serial.begin(115200);           // Initialize serial communication at a baud rate of 115200
  matrix.begin();                 // Initialize the LED matrix
}

void loop() {

  matrix.loadFrame(heart1);
  delay(100);

  matrix.loadFrame(heart2);
  delay(100);

  matrix.loadFrame(heart3);
  delay(100);

  matrix.loadFrame(heart4);
  delay(100);

  // Print the current value of millis() to the serial monitor
  Serial.println(millis());
}
