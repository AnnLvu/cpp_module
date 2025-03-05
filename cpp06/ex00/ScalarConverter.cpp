#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    // Default constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    // Copy constructor
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    // Assignment operator
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    // Destructor
}

void ScalarConverter::convert(const std::string& literal) {
    double value;
    std::string input = literal;

    // Handle pseudo-literals with 'f' suffix
    if (input == "-inff" || input == "+inff" || input == "nanf") {
        value = std::strtod(input.c_str(), NULL);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // Handle pseudo-literals without 'f' suffix
    if (input == "-inf" || input == "+inf" || input == "nan") {
        value = std::strtod(input.c_str(), NULL);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
        return;
    }

    // Remove 'f' at the end if present
    if (input.length() > 1 && input[input.length() - 1] == 'f') {
        input = input.substr(0, input.length() - 1);  // Remove the last 'f' character
    }

    // Check for char
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        value = static_cast<double>(c);

        // Check for control characters and DEL (\x7f)
        if ((c >= 0 && c <= 31) || c == 127) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            printChar(value);
        }
        printInt(value);
        printFloat(value);
        printDouble(value);
    } else {
        try {
            // Attempt to convert the string to a number
            char* end;
            value = std::strtod(input.c_str(), &end);

            // Check for additional characters
            if (*end == '\0') {
                // Print each type
                printChar(value);
                printInt(value);
                printFloat(value);
                printDouble(value);
            } else {
                throw std::invalid_argument("Invalid input literal");
            }
        } catch (const std::exception&) {
            // If conversion fails, print error messages
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}

void ScalarConverter::printChar(double value) {
    // Prints the character representation of the given value
    if (std::isnan(value) || std::isinf(value) || value < 0 || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if ((value >= 0 && value <= 31) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
    // Prints the integer representation of the given value
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
    // Prints the float representation of the given value
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else {
        float floatValue = static_cast<float>(value);
        int precision = countDecimalDigits(value);
        std::cout << std::fixed << std::setprecision(precision) << "float: " << floatValue << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    // Prints the double representation of the given value
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else {
        int precision = countDecimalDigits(value);
        std::cout << std::fixed << std::setprecision(precision) << "double: " << value << std::endl;
    }
}

int ScalarConverter::countDecimalDigits(double value) {
    // Counts the number of decimal digits in the given value
    std::stringstream ss;
    ss << std::fixed << value;
    std::string str = ss.str();
    std::size_t pos = str.find('.');
    if (pos == std::string::npos)
        return 0; // If there is no decimal point, there are no decimal digits
    // Remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (str[str.size() - 1] == '.')
        return 1; // If the number is an integer, return 1 to display .0
    return str.size() - pos - 1; // Number of digits after the decimal point
}
