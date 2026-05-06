#include <MeasurementCalculator.h>

MeasurementCalculator calc;

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(calc.measureConvert1D(2500, calc.FEET, calc.MILES, true));
  Serial.println(calc.measureConvert1D(2000, calc.METRES, calc.MILES, true));
  Serial.println(calc.measureConvert2D(2000, 120, calc.METRES, calc.ACRES, true));
  Serial.println(calc.measureConvert2D(20, 30,calc.METRES,calc.SQUAREMETRES, true));
  
  delay(1000);
}
