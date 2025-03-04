#include "Serializer.hpp"

int main() {
    
    Data original;
    original.id = 42;
    original.name = "Serializer Test";
    original.value = 3.14;

    unsigned long raw = Serializer::serialize(&original);

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original Address: " << &original << std::endl;
    std::cout << "Deserialized Address: " << deserialized << std::endl;

    if (deserialized == &original) {
        std::cout << "✅ Deserialization successful! The pointers match." << std::endl;
    } else {
        std::cout << "❌ Deserialization failed! The pointers do not match." << std::endl;
    }

    std::cout << "\nOriginal Data:\n";
    std::cout << "ID: " << original.id << "\n";
    std::cout << "Name: " << original.name << "\n";
    std::cout << "Value: " << original.value << "\n";

    std::cout << "\nDeserialized Data:\n";
    std::cout << "ID: " << deserialized->id << "\n";
    std::cout << "Name: " << deserialized->name << "\n";
    std::cout << "Value: " << deserialized->value << "\n";

    return 0;
}
