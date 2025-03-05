#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Cat copied\n";
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed\n";
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        if (brain) delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}
