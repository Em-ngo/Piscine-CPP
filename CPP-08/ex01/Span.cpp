#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {

}

Span::~Span() {

}


Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {

}


Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Cannot add more numbers, Span is full.");
    _numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw std::out_of_range("Not enough space to add all numbers.");
    _numbers.insert(_numbers.end(), begin, end);
}


int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end()); 

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); i++) {
        int diff = sortedNumbers[i] - sortedNumbers[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}


int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}

void Span::printNumbers() const {
    std::cout << "Stored numbers: ";
    for (size_t i = 0; i < _numbers.size(); i++) {
        std::cout << _numbers[i] << " ";
    }
    std::cout << std::endl;
}
