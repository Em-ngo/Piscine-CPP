#include "Array.hpp"
#include <string>

int main() {
    // array of integers
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 2;
    }

    std::cout << "Integer array: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n";

    // array of strings
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "Templates";

    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << "\n";

    // Test: Copy constructor
    Array<int> copyArray = intArray;
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << "\n";

    //  Test: Assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << "\n";

    // Test: Exception handling 
    try {
        std::cout << "Trying to access index 10 in intArray...\n";
        std::cout << intArray[10] << "\n"; 
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}
