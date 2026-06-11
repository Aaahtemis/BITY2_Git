#include <avr/wdt.h>
int input = 0;

int lightStart = 2;
int lightEnd = 8;

int movingAverage[5] = { 0, 0, 0, 0, 0 };
int simpleAverage[100];
int lowerDeadZone = 100;

float smoothing = 0;

int tickCount = 0;
int tickCarryMoving = 5000;
int tickCarrySimpleMod = 5;

void setup() {
  Serial.begin(9600);
  //wdt_enable(WDTO_2S);
  Serial.println("Device was reset");
  for (int i = lightStart; i <= lightEnd; i++) {
    pinMode(i, OUTPUT);
  }

  smoothing = 2/((sizeof(movingAverage) / sizeof(movingAverage[0]))+1);
  Serial.println("smoothingMult = " + String(smoothing));
}

void loop() {
  tickCount++;

  int rawData = analogRead(input);
  //Serial.println("raw data: " + String(rawData));
  int safeValue = constrain(rawData, lowerDeadZone, 1023);
  //Serial.println("safe data: " + String(safeValue));
  float normalizedValue = map(safeValue, lowerDeadZone, 1023, 0, 100);
  //Serial.println("normalized data: " + String(normalizedValue));

  float currentLightStage = map(normalizedValue, 0, 100, lightStart, lightEnd);
  for (int i = lightStart; i <= lightEnd; i++) {
    if (i < currentLightStage) {
      digitalWrite(i, HIGH);
    } else {
      digitalWrite(i, LOW);
    }
  }

  if (tickCount % tickCarryMoving / tickCarrySimpleMod ){
    if (safeValue != 0) AddToStartOfArray(safeValue, simpleAverage);
  }

  if (tickCount >= tickCarryMoving) { // inner loop #1
    AddToStartOfArray(safeValue, movingAverage);
    tickCount = 0;
  }
}

void AddToStartOfArray(int value, int array[]) {
  for (int i = 0; i < (sizeof(array) / sizeof(array[0])) - 1; i++) {
    array[i + 1] = array[i];
  }
  array[0] = value;

  for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
    Serial.println(array[i]);
  }
}

void FindExponentialAverage(){
  
}
