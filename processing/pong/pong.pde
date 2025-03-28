import processing.serial.*;
Serial port;

int player1, player2;
int scorePlayer1, scorePlayer2;

float ballX;
float ballY;
int ballR;
float ballVV;
float ballHV;

int barWidth;
int barHeight;
int barX1;
int barX2;

void setup () {
  println (Serial.list ());
  String portName = Serial.list () [2];
  port = new Serial (this, portName, 9600);
  port.bufferUntil (';');
                            
  size(600, 600);
  colorMode (HSB, 256, 100, 100);
  
  barWidth = 20;
  barHeight = 80;
  barX1 = 0;
  barX2 = barX2 = width - barWidth;
  
  resetBall();
}

void draw () { 
  ballX = ballX + ballHV;
  ballY = ballY + ballVV;
  
  background(0);
  rect(barX1, player1, barWidth, barHeight);
  rect(barX2, player2, barWidth, barHeight);
  circle(ballX, ballY, ballR);
  
  if (ballX < barX1 + barWidth &&
    ballY < player1 + barHeight &&
    ballY > player1) {
    // left bar was hit
    println("left");
    
    ballHV = abs(ballHV);
    ballHV = ballHV + 0.3;
    adjustAngle(player1);
  } else if (ballX + ballR > barX2 &&
    ballY < player2 + barHeight &&
    ballY > player2) {
    // right bar was hit
    println("right");
    
    ballHV = ballHV * -1;
    ballHV = ballHV - 0.3;
    adjustAngle(player2);
  } else if (ballY < 0) {
    // hit top edge
    ballVV = abs(ballVV);
  } else if (ballY + ballR > height) {
    // hit bottom edge
    ballVV = ballVV * -1;
  } else if (ballX > barX2) {
    // point for player 1
    scorePlayer1++;
    resetBall();
  } else if (ballX < barX1 + barWidth) {
    // point for player 2
    scorePlayer2++;
    resetBall();
  }

  fill(255, 0, 100);
  textSize(50);
  text(scorePlayer1 + " - " + scorePlayer2, width / 2 - 43, 60);
}

void adjustAngle(int barY) {
  float heightDiff = ballY - barY;
  
  println(heightDiff,  barY, ballY);
  
  if (heightDiff < barHeight / 2) {
    // adjust angle upwards
    ballVV = ballVV - (map(heightDiff, 0, barHeight / 2, 4, 0));
  } else {
    // adjust angle downwards
    ballVV = ballVV + (map(heightDiff, barHeight / 2, barHeight, 0, 4));
  }
}

void resetBall() {
  ballX = width / 2;
  ballY = height / 2;
  ballR = 15;
  ballVV = 0;
  ballHV = 3;
}

void serialEvent (Serial port) {
  String gelesen = port.readStringUntil (';');
  if (gelesen != null) {
    String[] positions = split (gelesen, ",");
    if (positions.length >= 2) {
      player1 = (int) map (int (positions[0]), 0, 1023, 0, height);
      player2 = (int) map (int (positions[1].replaceAll (";", "")), 0, 1023, 0, height);
    }
  }
}   // < serialEvent
