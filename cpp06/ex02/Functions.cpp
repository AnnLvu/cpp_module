#include "Functions.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
    int randValue = rand() % 3; // Generate a random number between 0 and 2
    if (randValue == 0)
        return new A;
    else if (randValue == 1)
        return new B;
    else
        return new C;
}


void identify(Base* p)
{
    try {
        A* a = dynamic_cast<A*>(p);
        if (a) {
            std::cout << "A" << std::endl;
            return;
        }

        B* b = dynamic_cast<B*>(p);
        if (b) {
            std::cout << "B" << std::endl;
            return;
        }

        C* c = dynamic_cast<C*>(p);
        if (c) {
            std::cout << "C" << std::endl;
            return;
        }
    } catch (...) {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (...) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (...) {
            std::cout << "C" << std::endl;
        }
    }
}

