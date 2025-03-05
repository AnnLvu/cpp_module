#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}
