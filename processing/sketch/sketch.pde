int rect1 = 60;
int rect2 = 60;
float rectX1;
float rectY1;
float rectX2;
float rectY2;

void setup () {
  size(600, 400);
}

void draw () {
  background(255, 255, 255);
  
  // rectX1 = (width / 4) - (rect1 / 2);
  rectY1 = (height / 2) - (rect1 / 2);
  // rectX2 = (width / 4 * 3) - (rect2 / 2);
  rectY2 = (height / 2) - (rect2 / 2);

  fill (255, 0, 0);
  rect1 = (mouseX % width) / 2;
  rectX1 = (mouseX % width) / 2;
  rectY1 = (mouseY % height) / 2;
  rect(rectX1, rectY1, rect1, rect1);

  fill (0, 255, 0);
  rect2 = (width / 2) - (mouseX % width) / 2;
  rectX2 = (width / 2) - (mouseX % width) / 2;
  rectY2 = (height / 2) - (mouseY % height) / 2;
  rect(rectX2, rectY2, rect2, rect2);
}
