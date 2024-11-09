void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int brightness = analogRead(0);
  brightness = brightness / 4;

  if (brightness > 220) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(100);
  } else {
    analogWrite(3, brightness);
    analogWrite(5, brightness);
    analogWrite(6, brightness);
  }
}