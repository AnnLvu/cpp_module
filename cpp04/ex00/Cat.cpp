#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
