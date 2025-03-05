#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copied\n";
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destroyed\n";
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        std::cout << "Brain assigned\n";
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    return (index >= 0 && index < 100) ? ideas[index] : "";
}
