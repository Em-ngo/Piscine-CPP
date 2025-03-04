#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>  
#include <exception> 
#include <limits>

class Span {
private:
    unsigned int _maxSize;  // Maximum number of elements
    std::vector<int> _numbers;  // Stores the numbers

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    void addNumber(int number);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    void printNumbers() const;
};

#endif
