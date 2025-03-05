#include "Serializer.hpp"
#include "Data.hpp"
/*
What is Serialization and Deserialization?

Serialization is the process of converting an object into a format
that can be easily saved or transmitted. In this case,
the object is converted into an integer (`uintptr_t`),
which can be saved or transmitted over a network.

Deserialization is the reverse process where the data saved
or transmitted in a serialized format is converted back into an object.

Why is this needed?

Serialization and deserialization are useful in the following scenarios:
1. State Preservation:
    You can save the state of an object to a file or database and restore it later.
2. Data Transmission:
    You can transmit objects over a network between different systems or processes.
3. Object Cloning:
    You can create a copy of an object by serializing and then deserializing it.*/

int main() {
    // Create a new Data object
    Data* original = new Data(42, "Original Data");

    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << original << std::endl;
    std::cout << "ID: " << original->id << ", Name: " << original->name << std::endl;

    // Serialize the Data object to uintptr_t
    uintptr_t raw = Serializer::serialize(original);
    std::cout << "\nSerialized Data:" << std::endl;
    std::cout << "Raw uintptr_t: " << raw << std::endl;

    // Deserialize uintptr_t back to Data pointer
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;

    // Check if the original and deserialized pointers match
    if (original == deserialized) {
        std::cout << "\nSerialization and deserialization were successful!" << std::endl;
    } else {
        std::cout << "\nSerialization and deserialization failed!" << std::endl;
    }

    // Free the allocated memory
    delete original;

    return 0;
}
