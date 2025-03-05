#include "Functions.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    std::cout << "Program started. Generating a random object...\n";

    srand(time(0));
    // Generate a random object
    Base* base = generate();

    std::cout << "Identifying object with pointer:" << std::endl;
    identify(base);

    std::cout << "Identifying object with reference:" << std::endl;
    identify(*base);

    std::cout << "Cleaning up the dynamically allocated memory...\n";
    delete base;

    std::cout << "Program finished successfully.\n";
    return 0;
}
