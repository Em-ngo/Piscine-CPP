#include "Span.hpp"
#include <vector>
#include <cstdlib>  
#include <ctime>  

int main() {
 
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;  // Expected: 2
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;    // Expected: 14

    // Testing exceptions
    try {
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span emptySpan(3);
        emptySpan.shortestSpan();  
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Testing big insertion
    Span bigSpan(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(rand() % 1000000);  

    bigSpan.addRange(numbers.begin(), numbers.end());

    std::cout << "Big Span - Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Span - Longest: " << bigSpan.longestSpan() << std::endl;

    return 0;
}
