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
    //calcUnitTest_2D();
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
  Serial.println(abs(calc.measureConvert2D(37, 83, calc.METRES, calc.SQUAREMETRES) - 3071) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(47, 63, calc.METRES, calc.HECTARES) - 0.2961) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(29, 54, calc.METRES, calc.SQUAREFEET) - 16909.146) < 0.1);
  Serial.println(abs(calc.measureConvert2D(73, 41, calc.METRES, calc.ACRES) - 0.73956) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(56, 78, calc.METRES, calc.SQUAREKILOMETRES) - 0.004368) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(34, 97, calc.METRES, calc.SQUAREMILES) - 0.001276) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(12, 43, calc.METRES, calc.SQUAREINCHES) - 7966174.8) < 1);
  Serial.println(abs(calc.measureConvert2D(18, 27, calc.METRES, calc.SQUARECENTIMETRES) - 48600000) < 1);

  // FEET to all
  Serial.println(abs(calc.measureConvert2D(127, 43, calc.FEET, calc.SQUAREFEET) - 5461) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(213, 67, calc.FEET, calc.ACRES) - 0.32789) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(94, 38, calc.FEET, calc.SQUAREMETRES) - 331.757) < 0.01);
  Serial.println(abs(calc.measureConvert2D(156, 72, calc.FEET, calc.HECTARES) - 0.104329) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(203, 57, calc.FEET, calc.SQUAREKILOMETRES) - 0.001077) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(312, 87, calc.FEET, calc.SQUAREMILES) - 0.000972) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(17, 23, calc.FEET, calc.SQUAREINCHES) - 56304) < 0.1);
  Serial.println(abs(calc.measureConvert2D(22, 31, calc.FEET, calc.SQUARECENTIMETRES) - 6330773.4) < 1);

  // KILOMETRES to all
  Serial.println(abs(calc.measureConvert2D(3.7, 2.4, calc.KILOMETRES, calc.SQUAREKILOMETRES) - 8.88) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(1.3, 4.7, calc.KILOMETRES, calc.SQUAREMETRES) - 6110000) < 1);
  Serial.println(abs(calc.measureConvert2D(2.6, 1.9, calc.KILOMETRES, calc.HECTARES) - 494) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(4.1, 3.3, calc.KILOMETRES, calc.ACRES) - 3341.713) < 0.01);
  Serial.println(abs(calc.measureConvert2D(1.7, 2.3, calc.KILOMETRES, calc.SQUAREFEET) - 42086498.2) < 10);
  Serial.println(abs(calc.measureConvert2D(3.1, 1.8, calc.KILOMETRES, calc.SQUAREMILES) - 2.155) < 0.001);
  Serial.println(abs(calc.measureConvert2D(0.3, 0.4, calc.KILOMETRES, calc.SQUAREINCHES) - 186000000) < 1000);
  Serial.println(abs(calc.measureConvert2D(0.5, 0.7, calc.KILOMETRES, calc.SQUARECENTIMETRES) - 350000000000.0) < 1000000);

  // MILES to all
  Serial.println(abs(calc.measureConvert2D(2.3, 1.7, calc.MILES, calc.SQUAREMILES) - 3.91) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(1.4, 3.2, calc.MILES, calc.ACRES) - 2867.2) < 0.01);
  Serial.println(abs(calc.measureConvert2D(2.7, 1.3, calc.MILES, calc.SQUAREFEET) - 97939814.4) < 100);
  Serial.println(abs(calc.measureConvert2D(1.6, 2.9, calc.MILES, calc.SQUAREMETRES) - 11996346.3) < 10);
  Serial.println(abs(calc.measureConvert2D(3.4, 1.1, calc.MILES, calc.HECTARES) - 968.117) < 0.01);
  Serial.println(abs(calc.measureConvert2D(2.1, 4.3, calc.MILES, calc.SQUAREKILOMETRES) - 23.357) < 0.001);
  Serial.println(abs(calc.measureConvert2D(0.3, 0.4, calc.MILES, calc.SQUAREINCHES) - 214277760) < 100);
  Serial.println(abs(calc.measureConvert2D(0.5, 0.7, calc.MILES, calc.SQUARECENTIMETRES) - 1446326967.6) < 1000);

  // INCHES to all
  Serial.println(abs(calc.measureConvert2D(733, 412, calc.INCHES, calc.SQUAREINCHES) - 301996) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(544, 317, calc.INCHES, calc.SQUARECENTIMETRES) - 1112095.24) < 1);
  Serial.println(abs(calc.measureConvert2D(829, 431, calc.INCHES, calc.SQUAREFEET) - 2484.118) < 0.01);
  Serial.println(abs(calc.measureConvert2D(612, 278, calc.INCHES, calc.SQUAREMETRES) - 109.514) < 0.001);
  Serial.println(abs(calc.measureConvert2D(934, 517, calc.INCHES, calc.HECTARES) - 0.031139) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(743, 628, calc.INCHES, calc.ACRES) - 0.076924) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(512, 394, calc.INCHES, calc.SQUAREKILOMETRES) - 0.000130) < 0.000001);
  Serial.println(abs(calc.measureConvert2D(867, 423, calc.INCHES, calc.SQUAREMILES) - 0.000088) < 0.000001);

  // CENTIMETRES to all
  Serial.println(abs(calc.measureConvert2D(1873, 1124, calc.CENTIMETRES, calc.SQUARECENTIMETRES) - 2105252) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(2341, 1876, calc.CENTIMETRES, calc.SQUAREINCHES) - 683204.6) < 1);
  Serial.println(abs(calc.measureConvert2D(1432, 2871, calc.CENTIMETRES, calc.SQUAREMETRES) - 411.217) < 0.01);
  Serial.println(abs(calc.measureConvert2D(3124, 1739, calc.CENTIMETRES, calc.SQUAREFEET) - 5929.89) < 0.01);
  Serial.println(abs(calc.measureConvert2D(4312, 2187, calc.CENTIMETRES, calc.HECTARES) - 0.094286) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(3871, 2934, calc.CENTIMETRES, calc.ACRES) - 0.279651) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(5123, 4871, calc.CENTIMETRES, calc.SQUAREKILOMETRES) - 0.024954) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(2987, 3142, calc.CENTIMETRES, calc.SQUAREMILES) - 0.003624) < 0.0001);

  // SQUAREMETRES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(7543, 0, calc.SQUAREMETRES, calc.HECTARES) - 0.7543) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(3217, 0, calc.SQUAREMETRES, calc.SQUAREFEET) - 34628.134) < 0.1);
  Serial.println(abs(calc.measureConvert2D(8432, 0, calc.SQUAREMETRES, calc.ACRES) - 2.08388) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(5619, 0, calc.SQUAREMETRES, calc.SQUAREKILOMETRES) - 0.005619) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(9273, 0, calc.SQUAREMETRES, calc.SQUAREMILES) - 0.003580) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(4831, 0, calc.SQUAREMETRES, calc.SQUAREINCHES) - 7488284.3) < 1);
  Serial.println(abs(calc.measureConvert2D(6124, 0, calc.SQUAREMETRES, calc.SQUARECENTIMETRES) - 61240000) < 1);

  // SQUAREFEET to all (y=0)
  Serial.println(abs(calc.measureConvert2D(17432, 0, calc.SQUAREFEET, calc.ACRES) - 0.40027) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(23718, 0, calc.SQUAREFEET, calc.SQUAREMETRES) - 2203.757) < 0.01);
  Serial.println(abs(calc.measureConvert2D(51200, 0, calc.SQUAREFEET, calc.HECTARES) - 0.47564) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(38461, 0, calc.SQUAREFEET, calc.SQUAREKILOMETRES) - 0.003572) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(72318, 0, calc.SQUAREFEET, calc.SQUAREMILES) - 0.002595) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(14832, 0, calc.SQUAREFEET, calc.SQUAREINCHES) - 2135808) < 1);
  Serial.println(abs(calc.measureConvert2D(29471, 0, calc.SQUAREFEET, calc.SQUARECENTIMETRES) - 273826489.6) < 100);

  // HECTARES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(3.47, 0, calc.HECTARES, calc.SQUAREMETRES) - 34700) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(7.23, 0, calc.HECTARES, calc.SQUAREFEET) - 778133.73) < 1);
  Serial.println(abs(calc.measureConvert2D(2.81, 0, calc.HECTARES, calc.ACRES) - 6.94365) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(9.14, 0, calc.HECTARES, calc.SQUAREKILOMETRES) - 0.0914) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(4.67, 0, calc.HECTARES, calc.SQUAREMILES) - 0.018031) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(1.34, 0, calc.HECTARES, calc.SQUAREINCHES) - 207564484.5) < 100);
  Serial.println(abs(calc.measureConvert2D(5.71, 0, calc.HECTARES, calc.SQUARECENTIMETRES) - 5710000000.0) < 1000);

  // ACRES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(17.3, 0, calc.ACRES, calc.SQUAREMILES) - 0.027031) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(4.61, 0, calc.ACRES, calc.SQUAREFEET) - 200811.6) < 0.1);
  Serial.println(abs(calc.measureConvert2D(8.34, 0, calc.ACRES, calc.SQUAREMETRES) - 33750.612) < 0.01);
  Serial.println(abs(calc.measureConvert2D(3.72, 0, calc.ACRES, calc.HECTARES) - 1.505479) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(6.19, 0, calc.ACRES, calc.SQUAREKILOMETRES) - 0.025054) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(2.43, 0, calc.ACRES, calc.SQUAREINCHES) - 152371382.4) < 100);
  Serial.println(abs(calc.measureConvert2D(7.81, 0, calc.ACRES, calc.SQUARECENTIMETRES) - 316048164.0) < 100);

  // SQUAREKILOMETRES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(4.37, 0, calc.SQUAREKILOMETRES, calc.SQUAREMETRES) - 4370000) < 1);
  Serial.println(abs(calc.measureConvert2D(2.19, 0, calc.SQUAREKILOMETRES, calc.SQUAREFEET) - 23572963.56) < 10);
  Serial.println(abs(calc.measureConvert2D(7.83, 0, calc.SQUAREKILOMETRES, calc.HECTARES) - 783) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(3.51, 0, calc.SQUAREKILOMETRES, calc.ACRES) - 867.038) < 0.01);
  Serial.println(abs(calc.measureConvert2D(1.74, 0, calc.SQUAREKILOMETRES, calc.SQUAREMILES) - 0.671817) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(0.83, 0, calc.SQUAREKILOMETRES, calc.SQUAREINCHES) - 1286499651.6) < 1000);
  Serial.println(abs(calc.measureConvert2D(2.41, 0, calc.SQUAREKILOMETRES, calc.SQUARECENTIMETRES) - 24100000000.0) < 10000);

  // SQUAREMILES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(3.47, 0, calc.SQUAREMILES, calc.ACRES) - 2220.8) < 0.01);
  Serial.println(abs(calc.measureConvert2D(1.83, 0, calc.SQUAREMILES, calc.SQUAREFEET) - 50997552) < 10);
  Serial.println(abs(calc.measureConvert2D(2.64, 0, calc.SQUAREMILES, calc.SQUAREMETRES) - 6837567.04) < 10);
  Serial.println(abs(calc.measureConvert2D(4.12, 0, calc.SQUAREMILES, calc.HECTARES) - 1067.076) < 0.01);
  Serial.println(abs(calc.measureConvert2D(1.57, 0, calc.SQUAREMILES, calc.SQUAREKILOMETRES) - 4.066) < 0.001);
  Serial.println(abs(calc.measureConvert2D(0.43, 0, calc.SQUAREMILES, calc.SQUAREINCHES) - 16989753600.0) < 10000);
  Serial.println(abs(calc.measureConvert2D(0.71, 0, calc.SQUAREMILES, calc.SQUARECENTIMETRES) - 1838892357.6) < 1000);

  // SQUAREINCHES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(174832, 0, calc.SQUAREINCHES, calc.SQUARECENTIMETRES) - 1127820.51) < 1);
  Serial.println(abs(calc.measureConvert2D(391274, 0, calc.SQUAREINCHES, calc.SQUAREMETRES) - 252.434) < 0.01);
  Serial.println(abs(calc.measureConvert2D(841293, 0, calc.SQUAREINCHES, calc.SQUAREFEET) - 5842.312) < 0.01);
  Serial.println(abs(calc.measureConvert2D(293847, 0, calc.SQUAREINCHES, calc.HECTARES) - 0.018958) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(748291, 0, calc.SQUAREINCHES, calc.ACRES) - 0.119096) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(512938, 0, calc.SQUAREINCHES, calc.SQUAREKILOMETRES) - 0.000331) < 0.000001);
  Serial.println(abs(calc.measureConvert2D(934712, 0, calc.SQUAREINCHES, calc.SQUAREMILES) - 0.000211) < 0.000001);

  // SQUARECENTIMETRES to all (y=0)
  Serial.println(abs(calc.measureConvert2D(7418329, 0, calc.SQUARECENTIMETRES, calc.SQUAREINCHES) - 1149826.5) < 1);
  Serial.println(abs(calc.measureConvert2D(3291847, 0, calc.SQUARECENTIMETRES, calc.SQUAREMETRES) - 329.1847) < 0.001);
  Serial.println(abs(calc.measureConvert2D(8471293, 0, calc.SQUARECENTIMETRES, calc.SQUAREFEET) - 9118.478) < 0.01);
  Serial.println(abs(calc.measureConvert2D(4829173, 0, calc.SQUARECENTIMETRES, calc.HECTARES) - 0.048292) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(6284719, 0, calc.SQUARECENTIMETRES, calc.ACRES) - 0.155324) < 0.0001);
  Serial.println(abs(calc.measureConvert2D(9173824, 0, calc.SQUARECENTIMETRES, calc.SQUAREKILOMETRES) - 0.000917) < 0.000001);
  Serial.println(abs(calc.measureConvert2D(5481293, 0, calc.SQUARECENTIMETRES, calc.SQUAREMILES) - 0.000212) < 0.000001);
}
