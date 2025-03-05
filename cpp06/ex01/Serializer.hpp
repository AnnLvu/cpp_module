#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#include <iostream>
class Serializer
{
private:
    Serializer();                                 // Private constructor
    ~Serializer();
    Serializer(const Serializer&);               // Private copy constructor
    Serializer& operator=(const Serializer&);    // Private assignment operator

public:
    static uintptr_t serialize(Data* ptr);       // Serialize a pointer to uintptr_t
    static Data* deserialize(uintptr_t raw);     // Deserialize uintptr_t to pointer
};

#endif

