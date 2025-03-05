#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal created\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copied\n";
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

//void Animal::makeSound() const {
//    std::cout << "Some generic animal sound\n";
//}

std::string Animal::getType() const {
    return type;
}

