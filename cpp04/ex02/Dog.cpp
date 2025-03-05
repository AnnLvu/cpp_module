#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copied\n";
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}
