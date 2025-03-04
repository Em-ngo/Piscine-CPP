#include "Serializer.hpp"

// Convert a pointer to an integer (unsigned long)
unsigned long Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

// Convert an integer (unsigned long) back to a pointer
Data* Serializer::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw);
}
