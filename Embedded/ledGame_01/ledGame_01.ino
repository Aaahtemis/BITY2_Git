
const int clearPos = 7;
const int yellowPos = 9;
const int redPos = 10;
const int bluePos = 11;

const int clearLed = 13;
const int yellowBase = 0;
const int redBase = 1;
const int blueBase = 2;

const byte buttonInterrupt = 3;
const int ledBlue = 4;
const int ledYellow = 5;
const int ledRed = 6;

const int grassStart = 7;
const int grassEnd = 11;

const byte stickInput = A0;
int stickPosX;
int stickNorm;

volatile int position = grassStart;
volatile bool red = false;
volatile bool yellow = false;
volatile bool blue = false;

volatile int tick = 0;

void setup() {
  pinMode(clearLed, OUTPUT);

  pinMode(yellowBase, OUTPUT);
  pinMode(redBase, OUTPUT);
  pinMode(blueBase, OUTPUT);

  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  for (int i = grassStart; i <= grassEnd; i++){
    pinMode(i,OUTPUT);
  }
  
  attachInterrupt(digitalPinToInterrupt(buttonInterrupt), buttonPress, RISING);

  stickNorm = analogRead(stickInput);

}

void loop() {

  tick++;

  stickPosX = analogRead(A0);

  if (digitalRead(clearLed) == HIGH){
    digitalWrite(ledBlue, LOW);
    digitalWrite(blueBase, LOW);
    blue = false;

    digitalWrite(ledYellow, LOW);
    digitalWrite(yellowBase, LOW);
    yellow = false;

    digitalWrite(ledRed, LOW);
    digitalWrite(redBase, LOW);
    red = false;

    delay(100);
    digitalWrite(clearLed, LOW);
  }

  if (red == true && digitalRead(ledRed) == LOW)  digitalWrite(ledRed, HIGH);
  else if (red == false && digitalRead(ledRed) == HIGH)  digitalWrite(ledRed, LOW);

  if (blue == true && digitalRead(ledBlue) == LOW)  digitalWrite(ledBlue, HIGH);
  else if (blue == false && digitalRead(ledBlue) == HIGH)  digitalWrite(ledBlue, LOW);

  if (yellow == true && digitalRead(ledYellow) == LOW)  digitalWrite(ledYellow, HIGH);
  else if (yellow == false && digitalRead(ledYellow) == HIGH)  digitalWrite(ledYellow, LOW);

  for (int i = grassStart; i <= grassEnd; i++){
    if (i != position)
      digitalWrite(i, LOW);
    else
      digitalWrite(i, HIGH);
  }

  if (tick % 200 == 0){
    if (stickPosX > stickNorm +200 && position != grassEnd) {position = position + 1;}
    else if (stickPosX < stickNorm -200 && position != grassStart) {position = position - 1;}
    tick++;
    delay(50);
  }
}

void buttonPress(){

    switch(position){
      case clearPos:
        digitalWrite(clearLed, HIGH);
        break;
      case redPos:
        if (!red){
          red = true;
          digitalWrite(redBase, HIGH);
        } else {
          red = false;
          digitalWrite(redBase, LOW);
        }
        break;
      case bluePos:
        if (!blue){
          blue = true;
          digitalWrite(blueBase, HIGH);
        } else {
          blue = false;
          digitalWrite(blueBase, LOW);
        }
        break;
      case yellowPos:
        if (!yellow){
          yellow = true;
          digitalWrite(yellowBase, HIGH);
        } else {
          yellow = false;
          digitalWrite(yellowBase, LOW);
        }
        break;
      default:
        break;
    }
  
}
