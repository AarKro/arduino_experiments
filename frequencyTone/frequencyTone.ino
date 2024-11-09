void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int frequency = analogRead(0);
  frequency = frequency * 10;

  digitalWrite(8, HIGH);
  delayMicroseconds(frequency);
  digitalWrite(8, LOW);
  delayMicroseconds(frequency);
}
