#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    virtual ~WrongAnimal();

    virtual void makeSound() const;
    std::string getType() const;
};

#endif

