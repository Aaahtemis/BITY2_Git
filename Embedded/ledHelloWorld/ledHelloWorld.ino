void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}  

int Speed = 150;

void loop() {

  // put your main code here, to run repeatedly:
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(Speed);
  digitalWrite(9, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(Speed);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(Speed);
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  delay(Speed);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(Speed);
}
