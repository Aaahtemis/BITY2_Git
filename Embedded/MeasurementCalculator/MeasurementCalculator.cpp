/*
  MeasurementCalculator.cpp - Function library for MeasurementCalculator.h
  Created by Artemis Churcher, May 6, 2026.
*/

#include "Arduino.h"
#include "MeasurementCalculator.h"

MeasurementCalculator::MeasurementCalculator(int baud = 9600)
{
    _baud = baud;
}

double MeasurementCalculator::measureConvert1D(double amount = 0, Measure from = METRES, Measure to = MILES, bool printResult = false)
{
    double total = -1;
    String measurement = "null";
    switch (from)
    {
    case METRES:
        switch (to)
        {
        case FEET:
            total = amount * 3.28084;
            measurement = "Feet";
            break;
        case MILES:
            total = amount / 1606;
            measurement = "Miles";
            break;
        case KILOMETRES:
            total = amount / 1000;
            measurement = "Kilometres";
            break;
        case INCHES:
            total = amount * 39.3701;
            measurement = "Inches";
            break;
        case CENTIMETRES:
            total = amount * 100;
            measurement = "Centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case FEET:
        switch (to)
        {
        case METRES:
            total = amount * 0.3048;
            measurement = "Metres";
            break;
        case MILES:
            total = amount / 5280;
            measurement = "Miles";
            break;
        case KILOMETRES:
            total = amount / 3280.84;
            measurement = "Kilometres";
            break;
        case INCHES:
            total = amount * 12;
            measurement = "Inches";
            break;
        case CENTIMETRES:
            total = measureConvert1D(amount, FEET, METRES) * 100;
            measurement = "Centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case MILES:
        switch (to)
        {
        case METRES:
            total = amount * 1609.344;
            measurement = "Metres";
            break;
        case FEET:
            total = amount * 5280;
            measurement = "Feet";
            break;
        case KILOMETRES:
            total = amount * 1.60934;
            measurement = "Kilometres";
            break;
        case INCHES:
            total = amount * 63360;
            measurement = "Inches";
            break;
        case CENTIMETRES:
            total = measureConvert1D(amount, MILES, METRES) * 100;
            measurement = "Centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;

    case KILOMETRES:
        switch (to)
        {
        case METRES:
            total = amount * 1000;
            measurement = "Metres";
            break;
        case FEET:
            total = amount * 3280.84;
            measurement = "Feet";
            break;
        case MILES:
            total = amount / 1.60934;
            measurement = "Miles";
            break;
        case INCHES:
            total = amount * 39370.1;
            measurement = "Inches";
            break;
        case CENTIMETRES:
            total = amount * 100000;
            measurement = "Centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case INCHES:
        switch (to)
        {
        case METRES:
            total = amount / 39.3701;
            measurement = "Metres";
            break;
        case CENTIMETRES:
            total = amount * 2.54;
            measurement = "Centimetres";
            break;
        case FEET:
            total = amount / 12;
            measurement = "Feet";
            break;
        case MILES:
            total = amount / 63360;
            measurement = "Miles";
            break;
        case KILOMETRES:
            total = amount / 39370.1;
            measurement = "Kilometres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case CENTIMETRES:
        switch (to)
        {
        case METRES:
            total = amount / 100;
            measurement = "Metres";
            break;
        case INCHES:
            total = amount / 2.54;
            measurement = "Inches";
            break;
        case FEET:
            total = measureConvert1D(amount / 100, METRES, FEET);
            measurement = "Feet";
            break;
        case MILES:
            total = measureConvert1D(amount / 100, METRES, MILES);
            measurement = "Miles";
            break;
        case KILOMETRES:
            total = amount / 100000;
            measurement = "Kilometres";
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
    if (printResult)
        Serial.println(String(total) + " " + measurement);
    return total;
}

double MeasurementCalculator::measureConvert2D(double x = 0, double y = 0, Measure from = METRES, Measure to = HECTARES, bool printResult = false)
{
    double total = -1;
    String measurement = "null";
    switch (from)
    {
    case METRES:
        switch (to)
        {
        case SQUAREMETRES:
            total = x * y;
            measurement = "Square metres";
            break;
        case HECTARES:
            total = x * y / 10000;
            measurement = "Hectares";
            break;
        case SQUAREFEET:
            total = measureConvert1D(x, METRES, FEET) * measureConvert1D(y, METRES, FEET);
            measurement = "Square feet";
            break;
        case ACRES:
            total = measureConvert2D(x, y, METRES, SQUAREFEET) / 43560;
            measurement = "Acres";
            break;
        case SQUAREKILOMETRES:
            total = x * y / 1000000;
            measurement = "Square kilometres";
            break;
        case SQUAREMILES:
            total = measureConvert1D(x, METRES, MILES) * measureConvert1D(y, METRES, MILES);
            measurement = "Square miles";
            break;
        case SQUAREINCHES:
            total = measureConvert1D(x, METRES, INCHES) * measureConvert1D(y, METRES, INCHES);
            measurement = "Square inches";
            break;
        case SQUARECENTIMETRES:
            total = measureConvert1D(x, METRES, CENTIMETRES) * measureConvert1D(y, METRES, CENTIMETRES);
            measurement = "Square centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case FEET:
        switch (to)
        {
        case SQUAREMETRES:
            total = measureConvert1D(x, FEET, METRES) * measureConvert1D(y, FEET, METRES);
            measurement = "Square metres";
            break;
        case HECTARES:
            total = measureConvert2D(x, y, FEET, SQUAREMETRES) / 10000;
            measurement = "Hectares";
            break;
        case SQUAREFEET:
            total = x * y;
            measurement = "Square feet";
            break;
        case ACRES:
            total = x * y / 43560;
            measurement = "Acres";
            break;
        case SQUAREKILOMETRES:
            total = measureConvert1D(x, FEET, KILOMETRES) * measureConvert1D(y, FEET, KILOMETRES);
            measurement = "Square kilometres";
            break;
        case SQUAREMILES:
            total = measureConvert1D(x, FEET, MILES) * measureConvert1D(y, FEET, MILES);
            measurement = "Square miles";
            break;
        case SQUAREINCHES:
            total = measureConvert1D(x, FEET, INCHES) * measureConvert1D(y, FEET, INCHES);
            measurement = "Square inches";
            break;
        case SQUARECENTIMETRES:
            total = measureConvert1D(x, FEET, CENTIMETRES) * measureConvert1D(y, FEET, CENTIMETRES);
            measurement = "Square centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case MILES:
        switch (to)
        {
        case SQUAREMETRES:
            total = measureConvert1D(x, MILES, METRES) * measureConvert1D(y, MILES, METRES);
            measurement = "Square metres";
            break;
        case HECTARES:
            total = measureConvert2D(x, y, MILES, SQUAREMETRES) * 10000;
            measurement = "Hectares";
            break;
        case SQUAREFEET:
            total = measureConvert1D(x, MILES, FEET) * measureConvert1D(y, MILES, FEET);
            measurement = "Square feet";
            break;
        case ACRES:
            total = measureConvert2D(x, y, MILES, SQUAREFEET) * 43560;
            measurement = "Acres";
            break;
        case SQUAREKILOMETRES:
            total = measureConvert1D(x, MILES, KILOMETRES) * measureConvert1D(y, MILES, KILOMETRES);
            measurement = "Square kilometres";
            break;
        case SQUAREMILES:
            total = x * y;
            measurement = "Square miles";
            break;
        case SQUAREINCHES:
            total = measureConvert1D(x, MILES, INCHES) * measureConvert1D(y, MILES, INCHES);
            measurement = "Square inches";
            break;
        case SQUARECENTIMETRES:
            total = measureConvert1D(x, MILES, CENTIMETRES) * measureConvert1D(y, MILES, CENTIMETRES);
            measurement = "Square centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case KILOMETRES:
        switch (to)
        {
        case SQUAREKILOMETRES:
            total = x * y;
            measurement = "Square kilometres";
            break;
        case SQUAREMETRES:
            total = x * y * 1000000;
            measurement = "Square metres";
            break;
        case HECTARES:
            total = x * y * 100;
            measurement = "Hectares";
            break;
        case SQUAREFEET:
            total = measureConvert1D(x, KILOMETRES, FEET) * measureConvert1D(y, KILOMETRES, FEET);
            measurement = "Square feet";
            break;
        case ACRES:
            total = measureConvert2D(x, y, KILOMETRES, SQUAREFEET) / 43560;
            measurement = "Acres";
            break;
        case SQUAREMILES:
            total = measureConvert1D(x, KILOMETRES, MILES) * measureConvert1D(y, KILOMETRES, MILES);
            measurement = "Square miles";
            break;
        case SQUAREINCHES:
            total = measureConvert1D(x, KILOMETRES, INCHES) * measureConvert1D(y, KILOMETRES, INCHES);
            measurement = "Square inches";
            break;
        case SQUARECENTIMETRES:
            total = measureConvert1D(x, KILOMETRES, CENTIMETRES) * measureConvert1D(y, KILOMETRES, CENTIMETRES);
            measurement = "Square centimetres";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case INCHES:
        switch (to)
        {
        case SQUAREINCHES:
            total = x * y;
            measurement = "Square inches";
            break;
        case SQUARECENTIMETRES:
            total = measureConvert1D(x, INCHES, CENTIMETRES) * measureConvert1D(y, INCHES, CENTIMETRES);
            measurement = "Square centimetres";
            break;
        case SQUAREMETRES:
            total = measureConvert1D(x, INCHES, METRES) * measureConvert1D(y, INCHES, METRES);
            measurement = "Square metres";
            break;
        case SQUAREFEET:
            total = measureConvert1D(x, INCHES, FEET) * measureConvert1D(y, INCHES, FEET);
            measurement = "Square feet";
            break;
        case HECTARES:
            total = measureConvert2D(x, y, INCHES, SQUAREMETRES) / 10000;
            measurement = "Hectares";
            break;
        case ACRES:
            total = measureConvert2D(x, y, INCHES, SQUAREFEET) / 43560;
            measurement = "Acres";
            break;
        case SQUAREKILOMETRES:
            total = measureConvert2D(x, y, INCHES, SQUAREMETRES) / 1000000;
            measurement = "Square kilometres";
            break;
        case SQUAREMILES:
            total = measureConvert2D(x, y, INCHES, SQUAREFEET) / 27878400;
            measurement = "Square miles";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;

    case CENTIMETRES:
        switch (to)
        {
        case SQUARECENTIMETRES:
            total = x * y;
            measurement = "Square centimetres";
            break;
        case SQUAREINCHES:
            total = measureConvert1D(x, CENTIMETRES, INCHES) * measureConvert1D(y, CENTIMETRES, INCHES);
            measurement = "Square inches";
            break;
        case SQUAREMETRES:
            total = measureConvert1D(x, CENTIMETRES, METRES) * measureConvert1D(y, CENTIMETRES, METRES);
            measurement = "Square metres";
            break;
        case SQUAREFEET:
            total = measureConvert1D(x, CENTIMETRES, FEET) * measureConvert1D(y, CENTIMETRES, FEET);
            measurement = "Square feet";
            break;
        case HECTARES:
            total = measureConvert2D(x, y, CENTIMETRES, SQUAREMETRES) / 10000;
            measurement = "Hectares";
            break;
        case ACRES:
            total = measureConvert2D(x, y, CENTIMETRES, SQUAREFEET) / 43560;
            measurement = "Acres";
            break;
        case SQUAREKILOMETRES:
            total = measureConvert2D(x, y, CENTIMETRES, SQUAREMETRES) / 1000000;
            measurement = "Square kilometres";
            break;
        case SQUAREMILES:
            total = measureConvert2D(x, y, CENTIMETRES, SQUAREFEET) / 27878400;
            measurement = "Square miles";
            break;
        default:
            measurement = "Not a valid output measurement.";
            break;
        }
        break;
    case SQUAREMETRES:
        if (y == 0)
        {
            switch (to)
            {
            case HECTARES:
                total = x / 10000;
                measurement = "Hectares";
                break;
            case SQUAREFEET:
                total = x * 10.7639;
                measurement = "Square feet";
                break;
            case ACRES:
                total = measureConvert2D(x, 0, SQUAREMETRES, SQUAREFEET) / 43560;
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = x / 1000000;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = x / 2589988.11;
                measurement = "Square miles";
                break;
            case SQUAREINCHES:
                total = measureConvert2D(x, 0, SQUAREMETRES, SQUAREFEET) * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = x * 10000;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    case SQUAREFEET:
        if (y == 0)
        {
            switch (to)
            {
            case HECTARES:
                total = measureConvert2D(x, 0, SQUAREFEET, SQUAREMETRES) * 10000;
                measurement = "Hectares";
                break;
            case SQUAREMETRES:
                total = x * 0.092903;
                measurement = "Square metres";
                break;
            case ACRES:
                total = x / 43560;
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = x / 10763910.4;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = x / 27878400;
                measurement = "Square miles";
                break;
            case SQUAREINCHES:
                total = x * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = measureConvert2D(x, 0, SQUAREFEET, SQUAREMETRES) * 10000;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    case HECTARES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUAREFEET:
                total = measureConvert2D(x, 0, HECTARES, ACRES) * 43560;
                measurement = "Hectares";
                break;
            case SQUAREMETRES:
                total = x * 10000;
                measurement = "Square metres";
                break;
            case ACRES:
                total = x * 2.47105;
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = x / 100;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = x / 258.999;
                measurement = "Square miles";
                break;
            case SQUAREINCHES:
                total = measureConvert2D(x, 0, HECTARES, SQUAREMETRES) * 10000 * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = measureConvert2D(x, 0, HECTARES, SQUAREMETRES) * 10000;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    case ACRES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUAREFEET:
                total = x * 43560;
                measurement = "Hectares";
            case SQUAREMETRES:
                total = x * 4046.86;
                measurement = "Square metres";
            case HECTARES:
                total = x * 0.404686;
                measurement = "Acres";
            case SQUAREKILOMETRES:
                total = x / 247.105;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = x / 640;
                measurement = "Square miles";
                break;
            case SQUAREINCHES:
                total = measureConvert2D(x, 0, ACRES, SQUAREFEET) * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = measureConvert2D(x, 0, ACRES, SQUAREMETRES) * 10000;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    case SQUAREKILOMETRES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUAREMETRES:
                total = x * 1000000;
                measurement = "Square metres";
                break;
            case SQUAREFEET:
                total = measureConvert2D(x * 1000000, 0, SQUAREMETRES, SQUAREFEET);
                measurement = "Square feet";
                break;
            case HECTARES:
                total = x * 100;
                measurement = "Hectares";
                break;
            case ACRES:
                total = measureConvert2D(x * 100, 0, HECTARES, ACRES);
                measurement = "Acres";
                break;
            case SQUAREMILES:
                total = measureConvert2D(x * 100, 0, HECTARES, SQUAREMILES);
                measurement = "Square miles";
                break;
            case SQUAREINCHES:
                total = measureConvert2D(x, 0, SQUAREKILOMETRES, SQUAREMETRES) * 10000 * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = x * 10000000000.0;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    case SQUAREINCHES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUARECENTIMETRES:
                total = x * 6.4516;
                measurement = "Square centimetres";
                break;
            case SQUAREMETRES:
                total = x / 1550.0031;
                measurement = "Square metres";
                break;
            case SQUAREFEET:
                total = x / 144;
                measurement = "Square feet";
                break;
            case HECTARES:
                total = measureConvert2D(x / 144, 0, SQUAREFEET, HECTARES);
                measurement = "Hectares";
                break;
            case ACRES:
                total = measureConvert2D(x / 144, 0, SQUAREFEET, ACRES);
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = measureConvert2D(x, 0, SQUAREINCHES, SQUAREMETRES) / 1000000;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = measureConvert2D(x / 144, 0, SQUAREFEET, SQUAREMILES);
                measurement = "Square miles";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;

    case SQUARECENTIMETRES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUAREINCHES:
                total = x / 6.4516;
                measurement = "Square inches";
                break;
            case SQUAREMETRES:
                total = x / 10000;
                measurement = "Square metres";
                break;
            case SQUAREFEET:
                total = measureConvert2D(x / 10000, 0, SQUAREMETRES, SQUAREFEET);
                measurement = "Square feet";
                break;
            case HECTARES:
                total = x / 100000000.0;
                measurement = "Hectares";
                break;
            case ACRES:
                total = measureConvert2D(x / 10000, 0, SQUAREMETRES, ACRES);
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = x / 10000000000.0;
                measurement = "Square kilometres";
                break;
            case SQUAREMILES:
                total = measureConvert2D(x / 10000, 0, SQUAREMETRES, SQUAREMILES);
                measurement = "Square miles";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;

    case SQUAREMILES:
        if (y == 0)
        {
            switch (to)
            {
            case SQUAREMETRES:
                total = x * 2589988.11;
                measurement = "Square metres";
                break;
            case SQUAREFEET:
                total = x * 27878400;
                measurement = "Square feet";
                break;
            case HECTARES:
                total = x * 258.999;
                measurement = "Hectares";
                break;
            case ACRES:
                total = x * 640;
                measurement = "Acres";
                break;
            case SQUAREKILOMETRES:
                total = x * 2.58999;
                measurement = "Square kilometres";
                break;
            case SQUAREINCHES:
                total = measureConvert2D(x, 0, SQUAREMILES, SQUAREFEET) * 144;
                measurement = "Square inches";
                break;
            case SQUARECENTIMETRES:
                total = measureConvert2D(x, 0, SQUAREMILES, SQUAREMETRES) * 10000;
                measurement = "Square centimetres";
                break;
            default:
                measurement = "Not a valid output measurement.";
                break;
            }
        }
        else
        {
            measurement = "Y needs to be 0 for 2D to 2D conversion.";
        }
        break;
    default:
        measurement += " Not a valid input measurement.";
        break;
    }
    if (printResult)
        Serial.println(String(total) + " " + measurement);
    return total;
}
