#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <sstream>

class ScalarConverter {
public:
    ScalarConverter();  // Default constructor
    ScalarConverter(const ScalarConverter& other);  // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& other);  // Assignment operator
    ~ScalarConverter();  // Destructor

 // Converts the given literal to different scalar types and prints the results
    static void convert(const std::string& literal);

private:
    // Prints the character representation of the given value
    static void printChar(double value);

    // Prints the integer representation of the given value
    static void printInt(double value);

    // Prints the float representation of the given value
    static void printFloat(double value);

    // Prints the double representation of the given value
    static void printDouble(double value);

    // Counts the number of decimal digits in the given value
    static int countDecimalDigits(double value);
};

#endif
