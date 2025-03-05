#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;  // Test: should delete Dog correctly
    delete i;  // Test: should delete Cat correctly

    std::cout << "\n--- Testing deep copy ---\n";
    Dog originalDog;
    originalDog.makeSound();

    Dog copyDog = originalDog;  // Test copy constructor for Dog
    copyDog.makeSound();

    std::cout << "\n--- Testing array of Animals ---\n";
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    // Testing WrongAnimal and WrongCat:
    std::cout << "\n--- Testing WrongAnimal and WrongCat ---\n";

    const WrongAnimal* wa = new WrongAnimal();
    const WrongCat* wc = new WrongCat();

    // Calling makeSound to see what each class does:
    wa->makeSound();  // Expect "Some wrong animal sound"
    wc->makeSound();  // Expect "Meow (but wrong)!"

    std::cout << "Type of wa: " << wa->getType() << std::endl;  // Expect "WrongAnimal"
    std::cout << "Type of wc: " << wc->getType() << std::endl;  // Expect "WrongCat"

    delete wa;  // Test: should delete WrongAnimal correctly
    delete wc;  // Test: should delete WrongCat correctly

    return 0;
}
