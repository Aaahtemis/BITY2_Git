#include <avr/wdt.h>
int input = 0;

int lightStart = 2;
int lightEnd = 8;

int movingAverage[5] = { 0, 0, 0, 0, 0 };

float smoothing = 1.5;

int tickCount = 0;
int tickCarry = 500;

void setup() {
  Serial.begin(9600);
  //wdt_enable(WDTO_2S);
  Serial.println("Device was reset");
  for (int i = lightStart; i <= lightEnd; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int rawData = analogRead(input);
  //Serial.println("raw data: " + String(rawData));
  int safeValue = constrain(rawData, 0, 1023);
  //Serial.println("safe data: " + String(safeValue));
  float normalizedValue = map(safeValue, 0, 1023, 0, 100);
  //Serial.println("normalized data: " + String(normalizedValue));

  float currentLightStage = map(normalizedValue, 0, 100, lightStart, lightEnd);
  for (int i = lightStart; i <= lightEnd; i++) {
    if (i < currentLightStage) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }

  if (tickCount >= tickCarry) {
    if (safeValue != 0) AddToArray(safeValue);
    tickCount = 0;
  } else {
    tickCount++;
  }
  delay(100);
}

void AddToArray(int value) {
  for (int i = 0; i < (sizeof(movingAverage) / sizeof(movingAverage[0])) - 1; i++) {
    movingAverage[i + 1] = movingAverage[i];
  }
  movingAverage[0] = value;

  for (int i = 0; i < (sizeof(movingAverage) / sizeof(movingAverage[0])); i++) {
    Serial.println(movingAverage[i]);
  }
}
