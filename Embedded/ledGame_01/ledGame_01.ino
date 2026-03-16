
const int clearPos = 7;
const int yellowPos = 9;
const int redPos = 10;
const int bluePos = 12;

const int clearLed = 13;
const int yellowBase = 0;
const int redBase = 1;
const int blueBase = 2;

const int buttonInterrupt = 3;
const int ledBlue = 4;
const int ledYellow = 5;
const int ledRed = 6;

const int grassStart = 7;
const int grassEnd = 12;

const byte stickInput = A0;

volatile int position = grassStart;
volatile bool red = false;
volatile bool yellow = false;
volatile bool blue = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(clearLed, OUTPUT);

  pinMode(yellowBase, OUTPUT);
  pinMode(redBase, OUTPUT);
  pinMode(blueBase, OUTPUT);

  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);

  for (int i = grassStart; i < grassEnd; i++){
    pinMode(i,OUTPUT);
  }

  attachInterrupt(digitalPinToInterrupt(buttonInterrupt), buttonPress, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(clearLed) == HIGH){
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    delay(500);
    digitalWrite(clearLed, LOW);
  }

  for (int i = grassStart; i < grassEnd; i++){
    if (i != position)
      digitalWrite(i, LOW);
    else
      digitalWrite(i, HIGH);
  }
}

void buttonPress(){

  if (position < grassEnd){
    position++;
  } else {
    position = grassStart;
  }

  switch(position){
    case clearPos:
      digitalWrite(clearLed, HIGH);
    break;
  }

}
