#ifndef MeasurementCalculator_h
    #define MeasurementCalculator_h

    #include <Arduino.h>

    class MeasurementCalculator {
        public:
            enum Measure { METRES,
                            MILES,
                            FEET,
                            HECTARES,
                            ACRES,
                            SQUAREFEET,
                            SQUAREMETRES };
            MeasurementCalculator();
            double measureConvert1D(double amount = 0, Measure from = Measure::METRES, Measure to = Measure::MILES, bool printResult = false);
            double measureConvert2D(double x = 0, double y = 0, Measure from = Measure::METRES, Measure to = Measure::HECTARES, bool printResult = false);
        };
#endif