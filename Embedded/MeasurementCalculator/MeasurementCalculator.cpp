#include "MeasurementCalculator.h"

MeasurementCalculator::MeasurementCalculator(){
    
}

double MeasurementCalculator::measureConvert1D(double amount = 0, Measure from = Measure::METRES, Measure to = Measure::MILES, bool printResult = false) {
    double total = -1;
    String measurement = "null";
    switch (from) {
    case Measure::METRES:
        switch (to) {
        case Measure::FEET:
            total = amount * 3.28084;
            measurement = "Feet";
            break;
        case Measure::MILES:
            total = amount / 1606;
            measurement = "Miles";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case Measure::FEET:
        switch (to) {
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
        switch (to) {
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

double MeasurementCalculator::measureConvert2D(double x = 0, double y = 0, Measure from = Measure::METRES, Measure to = Measure::HECTARES, bool printResult = false) {
    double total = -1;
    String measurement = "null";
    switch (from) {
        case Measure::METRES: 
        switch (to) {
            case Measure::SQUAREMETRES:
            total = x * y;
            measurement = "Square metres";
            break;
            case Measure::HECTARES:
            total = x * y * 10000;
            measurement = "Hectares";
            break;
            case Measure::SQUAREFEET:
            total = measureConvert1D(x, Measure::METRES, Measure::FEET) * measureConvert1D(y, Measure::METRES, Measure::FEET);
            measurement = "Square feet";
            break;
            case Measure::ACRES:
            total = measureConvert2D(x, y, Measure::METRES, Measure::SQUAREFEET) * 43560;
            measurement = "Acres";
            break;
            default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
        case Measure::FEET:
            switch (to) {
                case Measure::SQUAREMETRES:
                total = measureConvert1D(x, Measure::FEET, Measure::METRES) * measureConvert1D(y, Measure::FEET, Measure::METRES);
                measurement = "Square metres";
                break;
                case Measure::HECTARES:
                total = measureConvert2D(x, y, Measure::FEET, Measure::SQUAREMETRES) * 10000;
                measurement = "Hectares";
                break;
                case Measure::SQUAREFEET:
                total = x * y;
                measurement = "Square feet";
                break;
                case Measure::ACRES:
                total = x * y * 43560;
                measurement = "Acres";
                break;
                default:
                measurement = "Not a valid output measurement.";
                break;
            }
        break;
        case Measure::MILES:
            switch (to) {
                case Measure::SQUAREMETRES:
                total = measureConvert1D(x, Measure::MILES, Measure::METRES) * measureConvert1D(y, Measure::MILES, Measure::METRES);
                measurement = "Square metres";
                break;
                case Measure::HECTARES:
                total = measureConvert2D(x, y, Measure::MILES, Measure::SQUAREMETRES) * 10000;
                measurement = "Hectares";
                break;
                case Measure::SQUAREFEET:
                total = measureConvert1D(x, Measure::MILES, Measure::FEET) * measureConvert1D(y, Measure::MILES, Measure::FEET);
                measurement = "Square feet";
                break;
                case Measure::ACRES:
                total = measureConvert2D(x, y, Measure::MILES, Measure::SQUAREFEET) * 43560;
                measurement = "Acres";
                break;
                default:
                measurement = "Not a valid output measurement.";
                break;
            }
        break;
        case Measure::SQUAREMETRES:
        if (y = 0) {
            switch (to) {
            case Measure::HECTARES:
                total = x * 10000;
                measurement = "Hectares";
                break;
            case Measure::SQUAREFEET:
                total = x * 10.7639;
                measurement = "Square feet";
                break;
            case Measure::ACRES:
                total = x / 4046.86;
                measurement = "Acres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        } else {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
        case Measure::SQUAREFEET:
        if (y = 0) {
            switch (to) {
            case Measure::HECTARES:
                total = measureConvert2D(x, 0, Measure::SQUAREFEET, Measure::SQUAREMETRES) * 10000;
                measurement = "Hectares";
                break;
            case Measure::SQUAREMETRES:
                total = x * 0.092903;
                measurement = "Square metres";
                break;
            case Measure::ACRES:
                total = x / 43560;
                measurement = "Acres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        } else {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
        case Measure::HECTARES:
        if (y = 0) {
            switch (to) {
            case Measure::SQUAREFEET:
                total = measureConvert2D(x, 0, Measure::HECTARES, Measure::ACRES) * 43560;
                measurement = "Hectares";
                break;
            case Measure::SQUAREMETRES:
                total = x * 10000;
                measurement = "Square metres";
                break;
            case Measure::ACRES:
                total = x * 2.47105;
                measurement = "Acres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        } else {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
        case Measure::ACRES:
        switch (to) {
            if (y = 0) {
            case Measure::SQUAREFEET:
                total = x * 43560;
                measurement = "Hectares";
            case Measure::SQUAREMETRES:
                total = x * 4046.86;
                measurement = "Square metres";
            case Measure::HECTARES:
                total = x * 0.404686;
                measurement = "Acres";
            default:
                measurement = "Not a valid output measurement.";
                break;
            } else {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
            }
            break;
        }
            default:
            measurement += " Not a valid input measurement.";
            break;

        if (printResult) Serial.println(String(total) + " " + measurement);
        return total;
    }
}
