#include <MeasurementCalculator.h>

MeasurementCalculator calc;

void setup() {
  Serial.begin(9600);
}

volatile bool doOnce = true;

void loop() {

  delay(1000);
  if (doOnce) {
    calcUnitTest_1D();
    doOnce = false;
  }

  delay(5000);
}

void calcUnitTest_1D() {
  // METRES to all
  Serial.println(abs(calc.measureConvert1D(1, calc.METRES, calc.FEET) - 3.28084) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.METRES, calc.MILES) - 0.000621371) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.METRES, calc.KILOMETRES) - 0.001) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.METRES, calc.INCHES) - 39.3701) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.METRES, calc.CENTIMETRES) - 100) < 0.0001);

  // FEET to all
  Serial.println(abs(calc.measureConvert1D(12, calc.FEET, calc.INCHES) - 144) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(5280, calc.FEET, calc.MILES) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.FEET, calc.METRES) - 0.304801) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.FEET, calc.KILOMETRES) - 0.000304801) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.FEET, calc.CENTIMETRES) - 30.4801) < 0.0001);

  // MILES to all
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.FEET) - 5280) < 1);
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.METRES) - 1609.34) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.KILOMETRES) - 1.60934) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.INCHES) - 63360) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.CENTIMETRES) - 160934) < 1);

  // KILOMETRES to all
  Serial.println(abs(calc.measureConvert1D(1, calc.KILOMETRES, calc.METRES) - 1000) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.KILOMETRES, calc.FEET) - 3280.84) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.KILOMETRES, calc.MILES) - 0.621371) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.KILOMETRES, calc.INCHES) - 39370.1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.KILOMETRES, calc.CENTIMETRES) - 100000) < 0.0001);

  // INCHES to all
  Serial.println(abs(calc.measureConvert1D(12, calc.INCHES, calc.FEET) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.INCHES, calc.CENTIMETRES) - 2.54) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.INCHES, calc.METRES) - 0.0254) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(63360, calc.INCHES, calc.MILES) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(1, calc.INCHES, calc.KILOMETRES) - 0.0000254) < 0.0001);

  // CENTIMETRES to all
  Serial.println(abs(calc.measureConvert1D(100, calc.CENTIMETRES, calc.METRES) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(2.54, calc.CENTIMETRES, calc.INCHES) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(30.48, calc.CENTIMETRES, calc.FEET) - 1) < 0.0001);
  Serial.println(abs(calc.measureConvert1D(100000, calc.CENTIMETRES, calc.KILOMETRES) - 1) < 0.1);
  Serial.println(abs(calc.measureConvert1D(160934, calc.CENTIMETRES, calc.MILES) - 1) < 0.01);
  // FEET → KILOMETRES
  Serial.println(abs(calc.measureConvert1D(1, calc.FEET, calc.KILOMETRES) - 0.000304801) < 0.001);

  // MILES → FEET
  Serial.println(abs(calc.measureConvert1D(1, calc.MILES, calc.FEET) - 5280) < 10);
}

void calcUnitTest_2D() {
  // METRES to all
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.SQUAREMETRES) == 10000);      // metres to square metres
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.HECTARES) == 1);              // metres to hectares
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.SQUAREFEET) == 107639.1);     // metres to square feet
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.ACRES) == 2.47105);           // metres to acres
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.SQUAREKILOMETRES) == 0.01);   // metres to square kilometres
  Serial.println(calc.measureConvert2D(100, 100, calc.METRES, calc.SQUAREMILES) == 0.00386102);  // metres to square miles

  // FEET to all
  Serial.println(calc.measureConvert2D(43560, 1, calc.FEET, calc.ACRES) == 1);                    // feet to acres
  Serial.println(calc.measureConvert2D(100, 100, calc.FEET, calc.SQUAREFEET) == 10000);           // feet to square feet
  Serial.println(calc.measureConvert2D(100, 100, calc.FEET, calc.SQUAREMETRES) == 929.03);        // feet to square metres
  Serial.println(calc.measureConvert2D(100, 100, calc.FEET, calc.HECTARES) == 0.092903);          // feet to hectares
  Serial.println(calc.measureConvert2D(100, 100, calc.FEET, calc.SQUAREKILOMETRES) == 0.000929);  // feet to square kilometres
  Serial.println(calc.measureConvert2D(100, 100, calc.FEET, calc.SQUAREMILES) == 0.000359);       // feet to square miles

  // KILOMETRES to all
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.SQUAREKILOMETRES) == 1);     // kilometres to square kilometres
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.SQUAREMETRES) == 1000000);   // kilometres to square metres
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.HECTARES) == 100);           // kilometres to hectares
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.ACRES) == 247.105);          // kilometres to acres
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.SQUAREFEET) == 10763910.4);  // kilometres to square feet
  Serial.println(calc.measureConvert2D(1, 1, calc.KILOMETRES, calc.SQUAREMILES) == 0.386102);   // kilometres to square miles

  // MILES to all
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.SQUAREMILES) == 1);             // miles to square miles
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.ACRES) == 640);                 // miles to acres
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.SQUAREFEET) == 27878400);       // miles to square feet
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.SQUAREMETRES) == 2589988.11);   // miles to square metres
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.HECTARES) == 258.999);          // miles to hectares
  Serial.println(calc.measureConvert2D(1, 1, calc.MILES, calc.SQUAREKILOMETRES) == 2.58999);  // miles to square kilometres

  // SQUAREMETRES to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(10000, 0, calc.SQUAREMETRES, calc.HECTARES) == 1);              // square metres to hectares
  Serial.println(calc.measureConvert2D(10000, 0, calc.SQUAREMETRES, calc.SQUAREFEET) == 107639.1);     // square metres to square feet
  Serial.println(calc.measureConvert2D(10000, 0, calc.SQUAREMETRES, calc.ACRES) == 2.47105);           // square metres to acres
  Serial.println(calc.measureConvert2D(10000, 0, calc.SQUAREMETRES, calc.SQUAREKILOMETRES) == 0.01);   // square metres to square kilometres
  Serial.println(calc.measureConvert2D(10000, 0, calc.SQUAREMETRES, calc.SQUAREMILES) == 0.00386102);  // square metres to square miles

  // SQUAREFEET to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(43560, 0, calc.SQUAREFEET, calc.ACRES) == 1);                      // square feet to acres
  Serial.println(calc.measureConvert2D(43560, 0, calc.SQUAREFEET, calc.SQUAREMETRES) == 4046.86);         // square feet to square metres
  Serial.println(calc.measureConvert2D(43560, 0, calc.SQUAREFEET, calc.HECTARES) == 0.404686);            // square feet to hectares
  Serial.println(calc.measureConvert2D(43560, 0, calc.SQUAREFEET, calc.SQUAREKILOMETRES) == 0.00404686);  // square feet to square kilometres
  Serial.println(calc.measureConvert2D(43560, 0, calc.SQUAREFEET, calc.SQUAREMILES) == 0.0015625);        // square feet to square miles

  // HECTARES to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(1, 0, calc.HECTARES, calc.SQUAREMETRES) == 10000);      // hectares to square metres
  Serial.println(calc.measureConvert2D(1, 0, calc.HECTARES, calc.SQUAREFEET) == 107639.1);     // hectares to square feet
  Serial.println(calc.measureConvert2D(1, 0, calc.HECTARES, calc.ACRES) == 2.47105);           // hectares to acres
  Serial.println(calc.measureConvert2D(1, 0, calc.HECTARES, calc.SQUAREKILOMETRES) == 0.01);   // hectares to square kilometres
  Serial.println(calc.measureConvert2D(1, 0, calc.HECTARES, calc.SQUAREMILES) == 0.00386102);  // hectares to square miles

  // ACRES to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(640, 0, calc.ACRES, calc.SQUAREMILES) == 1);              // acres to square miles
  Serial.println(calc.measureConvert2D(1, 0, calc.ACRES, calc.SQUAREFEET) == 43560);             // acres to square feet
  Serial.println(calc.measureConvert2D(1, 0, calc.ACRES, calc.SQUAREMETRES) == 4046.86);         // acres to square metres
  Serial.println(calc.measureConvert2D(1, 0, calc.ACRES, calc.HECTARES) == 0.404686);            // acres to hectares
  Serial.println(calc.measureConvert2D(1, 0, calc.ACRES, calc.SQUAREKILOMETRES) == 0.00404686);  // acres to square kilometres

  // SQUAREKILOMETRES to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREKILOMETRES, calc.SQUAREMETRES) == 1000000);   // square kilometres to square metres
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREKILOMETRES, calc.SQUAREFEET) == 10763910.4);  // square kilometres to square feet
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREKILOMETRES, calc.HECTARES) == 100);           // square kilometres to hectares
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREKILOMETRES, calc.ACRES) == 247.105);          // square kilometres to acres
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREKILOMETRES, calc.SQUAREMILES) == 0.386102);   // square kilometres to square miles

  // SQUAREMILES to all (y=0, x is area)
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREMILES, calc.ACRES) == 640);                 // square miles to acres
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREMILES, calc.SQUAREFEET) == 27878400);       // square miles to square feet
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREMILES, calc.SQUAREMETRES) == 2589988.11);   // square miles to square metres
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREMILES, calc.HECTARES) == 258.999);          // square miles to hectares
  Serial.println(calc.measureConvert2D(1, 0, calc.SQUAREMILES, calc.SQUAREKILOMETRES) == 2.58999);  // square miles to square kilometres
}
