#include "ScalarConverter.hpp"

int main()
{
    const char* testInputs[] = {
        "42",           // Integer
        "-42",          // Negative integer
        "0",            // Zero
        "42.0f",        // Floating-point (float)
        "nan",          // NaN
        "nanf",         // NaN float
        "+inf",         // Positive infinity
        "-inf",         // Negative infinity
        "a",            // Character
        "127",          // Max char value
        "128",          // Out of char range
        "3.1415",       // Double type floating-point
        "1e10",         // Large double value
        "-3.40282e38",  // Near float minimum value
        "invalid",      // Invalid format
        "42..24",       // Invalid format
        "42.24ff",      // Invalid format
        "-inffff"       // Invalid format
    };

    const std::size_t numTests = sizeof(testInputs) / sizeof(testInputs[0]);

    for (std::size_t i = 0; i < numTests; ++i)
    {
        std::cout << "=====================================" << std::endl;
        std::cout << "Testing input: \"" << testInputs[i] << "\"" << std::endl;
        std::cout << "-------------------------------------" << std::endl;

        ScalarConverter::convert(testInputs[i]);

        std::cout << "=====================================\n" << std::endl;
    }

    return 0;
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         std::cout << "wrong number of arguments!" << std::endl;
//         return 1;
//     }

//     ScalarConverter::convert(av[1]);

//     return 0;
// }
