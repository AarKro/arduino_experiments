#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_C6 1047

void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(9, OUTPUT);

  Serial.begin(9600);

  Serial.println("");
  Serial.println("=============================");
  Serial.println("Game Start");
  Serial.println("=============================");
  Serial.println("");
  Serial.println("-----------------");
}

bool gameOver = false;
int activePlayer = 2;
int field[7][7]{
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0 }
};

void loop() {
  // put your main code here, to run repeatedly:

  checkForGameEnd();

  updateActivePlayerLed();

  if (digitalRead(7) == LOW) {
    insertIntoColumn(0);
  } else if (digitalRead(8) == LOW) {
    insertIntoColumn(1);
  } else if (digitalRead(2) == LOW) {
    insertIntoColumn(2);
  } else if (digitalRead(3) == LOW) {
    insertIntoColumn(3);
  } else if (digitalRead(4) == LOW) {
    insertIntoColumn(4);
  } else if (digitalRead(5) == LOW) {
    insertIntoColumn(5);
  } else if (digitalRead(6) == LOW) {
    insertIntoColumn(6);
  }

  delay(200);

  if (changeDetected()) {
    printGameBoard();

    if (!gameOver) {
      changeActivePlayer();
    }
  }
}

void insertIntoColumn(int col) {
  for (int i = 6; i >= 0; i--) {
    if (field[i][col] == 0) {
      field[i][col] = activePlayer;

      printMoveIndicator(col);

      checkForWin(i, col);
      return;
    }
  }
}

int checkSum = 0;
int prevCheckSum = 1;
bool changeDetected() {
  checkSum = 0;

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      checkSum = checkSum + field[i][j];
    }
  }

  if (checkSum != prevCheckSum) {
    prevCheckSum = checkSum;
    return true;
  }

  prevCheckSum = checkSum;
  return false;
}

int changeActivePlayer() {
  if (activePlayer == 1) {
    activePlayer = 2;
  } else {
    activePlayer = 1;
  }
}

bool checkForWin(int y, int x) {
  if (
    (field[y][x + 1] == activePlayer && field[y][x + 2] == activePlayer && field[y][x + 3] == activePlayer) ||              // right
    (field[y][x - 1] == activePlayer && field[y][x - 2] == activePlayer && field[y][x - 3] == activePlayer) ||              // left
    (field[y + 1][x] == activePlayer && field[y + 2][x] == activePlayer && field[y + 3][x] == activePlayer) ||              // up
    (field[y - 1][x] == activePlayer && field[y - 2][x] == activePlayer && field[y - 3][x] == activePlayer) ||              // down
    (field[y + 1][x - 1] == activePlayer && field[y + 2][x - 2] == activePlayer && field[y + 3][x - 3] == activePlayer) ||  // up left
    (field[y + 1][x + 1] == activePlayer && field[y + 2][x + 2] == activePlayer && field[y + 3][x + 3] == activePlayer) ||  // up right
    (field[y - 1][x - 1] == activePlayer && field[y - 2][x - 2] == activePlayer && field[y - 3][x - 3] == activePlayer) ||  // down left
    (field[y - 1][x + 1] == activePlayer && field[y - 2][x + 2] == activePlayer && field[y - 3][x + 3] == activePlayer)     // down right
  ) {
    digitalWrite(13, HIGH);
    gameOver = true;
  } else {
    digitalWrite(13, LOW);
  }
}

void updateActivePlayerLed() {
  if (activePlayer == 1) {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
  }
}

bool gameEndMessagePrinted = false;
void checkForGameEnd() {
  if (gameOver && !gameEndMessagePrinted) {
    Serial.println("");
    Serial.println("=============================");
    Serial.print("Player ");
    Serial.print(activePlayer);
    Serial.print(" wins!");
    Serial.println("");
    Serial.println("=============================");
    delay(200);

    tone(9, NOTE_C5);
    delay(100);
    tone(9, NOTE_F5);
    delay(100);
    tone(9, NOTE_A5);
    delay(300);
    tone(9, NOTE_G5);
    delay(100);
    tone(9, NOTE_A5);
    delay(500);
    noTone(9);

    gameEndMessagePrinted = true;
    return;
  }
}

void printGameBoard() {
  // info: first line of board is printed by the printMoveIndicator function

  for (int i = 0; i < 7; i++) {
    Serial.print("| ");
    for (int j = 0; j < 7; j++) {
      Serial.print(field[i][j]);
      Serial.print(" ");
    }
    Serial.println("|");
  }

  Serial.println("-----------------");
}

void printMoveIndicator(int col) {
  Serial.println("");
  for (int j = 0; j < 17; j++) {
    if (j == col * 2 + 2) {
      Serial.print("v");
    } else {
      Serial.print("-");
    }
  }
  Serial.println("");
}