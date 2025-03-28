int red = 0;
int green = 0;
int blue = 0;

void setup() {
  size(600, 400);
}

void draw() {
  background(red, green, blue);
  
  blue++;
  
  if (blue == 256) {
    green++;
    blue = 0;
  }
  
  if (green == 256) {
    red++;
    green = 0;
  }
  
  if (red == 256) {
    red = 0;
  }
}
