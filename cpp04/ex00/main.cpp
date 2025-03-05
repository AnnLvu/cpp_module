#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); // Outputs dog sound
meta->makeSound(); // Outputs generic animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\nTesting WrongAnimal and WrongCat:\n";
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Outputs wrong animal sound, not overridden

    delete wrongMeta;
    delete wrongCat;
return 0;
}
