class Calculator
{

  public:
    enum Measure {METRES,MILES,FEET, HECTARES, ACRES, SQUAREFEET, SQUAREMETRES};  

  double measureConvert1D(double amount = 0, Measure from = Measure::METRES, Measure to = Measure::MILES, bool printResult = false)
  {
    double total = -1;
    String measurement = "null";
    switch (from){
      case Measure::METRES:
        switch (to){
          case Measure::FEET:
            total = amount * 3.28084;
            measurement = "Feet";
          break;
          case Measure::MILES:
            total = amount /1606;
            measurement = "Miles";
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      case Measure::FEET:
        switch (to){
          case Measure::METRES:
            total = amount * 0.3048;
            measurement = "Metres";
          break;
          case Measure::MILES:
            total = amount / 5280;
            measurement = "Miles";
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      case Measure::MILES:
        switch (to){
          case Measure::METRES:
            total = amount * 1609.344;
            measurement = "Metres";
          break;
          case Measure::FEET:
            total = amount * 5280;
            measurement = "Feet";
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      default:
        measurement += " Not a valid input measurement.";
      break;
    }
    if (printResult) Serial.println(String(total) + " " + measurement);
    return total;
  }

  double measureConvert2D(double x = 0, double y = 0, Measure from = Measure::METRES, Measure to = Measure::HECTARES, bool printResult = false)
  {
    double total = -1;
    String measurement = "null";
    switch (from){
      case Measure::METRES:
        switch(to){
          case Measure::SQUAREMETRES:
            total = x * y;
          break;
          case Measure::HECTARES:
            total = x*y * 10000;
          break;
          case Measure::SQUAREFEET:
            total = measureConvert1D(x,Measure::METRES,Measure::FEET) * measureConvert1D(y,Measure::METRES,Measure::FEET);
          break;
          case Measure::ACRES:
            total = measureConvert2D(x,y,Measure::METRES,Measure::SQUAREFEET) * 43560;
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      case Measure::FEET:
        switch(to){
          case Measure::SQUAREMETRES:
            total = measureConvert1D(x,Measure::FEET,Measure::METRES) * measureConvert1D(y,Measure::FEET,Measure::METRES);
          break;
          case Measure::HECTARES:
            total = measureConvert2D(x,y,Measure::FEET,Measure::SQUAREMETRES) * 10000;
          break;
          case Measure::SQUAREFEET:
            total = x * y;
          break;
          case Measure::ACRES:
            total = x * y * 43560;
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      case Measure::MILES:
        switch(to){
          case Measure::SQUAREMETRES:
            total = measureConvert1D(x,Measure::MILES,Measure::METRES) * measureConvert1D(y,Measure::MILES,Measure::METRES);
          break;
          case Measure::HECTARES:
            total = measureConvert2D(x,y,Measure::MILES,Measure::SQUAREMETRES) * 10000;
          break;
          case Measure::SQUAREFEET:
           total = measureConvert1D(x,Measure::MILES,Measure::FEET) * measureConvert1D(y,Measure::MILES,Measure::FEET);
          break;
          case Measure::ACRES:
            measureConvert2D(x,y,Measure::MILES,Measure::SQUAREFEET) * 43560;
          break;
          default:
            measurement = "Not a valid output measurement.";
          break;
        }
      break;
      default:
        measurement += " Not a valid input measurement.";
      break;
    }
    if (printResult) Serial.println(String(total) + " " + measurement);
    return total;
  }
};

Calculator calc;

void setup(){
  Serial.begin(9600);
}

void loop(){
  calc.measureConvert1D(2500, calc.FEET,calc.MILES, true);
  calc.measureConvert1D(2000, calc.METRES,calc.MILES, true);

  delay(1000);

}
