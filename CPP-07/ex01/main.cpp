#include "Iter.hpp"
#include <string>

int main() {
    /*Array of integers*/
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Numbers: ";
    iter(numbers, size, printElement);
    std::cout << "\n";

    /*Array of strings*/
    std::string words[] = {"Hello", "World", "C++", "Templates"};
    size_t wordSize = sizeof(words) / sizeof(words[0]);

    std::cout << "Words: ";
    iter(words, wordSize, printElement);
    std::cout << "\n";

    /*Array of doubles*/
    double decimals[] = {3.14, 2.71, 1.618, 0.577, 1.414};
    size_t doubleSize = sizeof(decimals) / sizeof(decimals[0]);

    std::cout << "Decimals: ";
    iter(decimals, doubleSize, printElement);
    std::cout << "\n";
    
    return 0;
}
