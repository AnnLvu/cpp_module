#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    virtual ~WrongCat();

    void makeSound() const; // Note: Not virtual, does not override WrongAnimal::makeSound
};

#endif
