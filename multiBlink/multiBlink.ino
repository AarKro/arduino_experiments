void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int frequency = analogRead(0);

  digitalWrite(2, HIGH);
  delay(frequency);
  digitalWrite(3, HIGH);
  delay(frequency);
  digitalWrite(4, HIGH);
  delay(frequency);

  delay(700);
  turnOffAll();
  delay(500);
}

void turnOffAll() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}
