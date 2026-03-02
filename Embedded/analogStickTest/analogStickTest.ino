void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  

  
}

void loop() {
  int xValue = analogRead(A0);
  int yValue = analogRead(A1);
  // put your main code here, to run repeatedly:
  if (xValue > 1023/3){
    digitalWrite(9, HIGH);
    digitalWrite(11,LOW);
  } else if (xValue < 1023/3){
    digitalWrite(11,HIGH);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(11,LOW);
  }


}
