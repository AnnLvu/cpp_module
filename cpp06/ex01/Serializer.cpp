#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer&) {

}

Serializer::~Serializer() {

}

Serializer& Serializer::operator=(const Serializer&) {
    return *this;
}


uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr); // Convert pointer to uintptr_t
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw); // Convert uintptr_t back to pointer
}
