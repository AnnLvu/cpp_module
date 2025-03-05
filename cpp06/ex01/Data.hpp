#ifndef DATA_HPP
#define DATA_HPP

#include <string>

// Structure to hold data with an ID and a name
struct Data
{
    int id;
    std::string name;

    // Default constructor
    Data() : id(0), name("") {}

    // Constructor to initialize the fields
    Data(int id, const std::string& name) : id(id), name(name) {}

    // Copy constructor
    Data(const Data& other) : id(other.id), name(other.name) {}

    // Assignment operator
    Data& operator=(const Data& other) {
        if (this != &other) {
            id = other.id;
            name = other.name;
        }
        return *this;
    }

    // Destructor
    ~Data() {}
};

#endif
