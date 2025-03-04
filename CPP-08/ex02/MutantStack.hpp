#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}  
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}  
    ~MutantStack() {} 
    MutantStack &operator=(const MutantStack &other) {  
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    typedef typename std::deque<T>::iterator iterator;
    iterator begin() { return this->c.begin(); } // underlying container (c)
    iterator end() { return this->c.end(); }

    typedef typename std::deque<T>::const_iterator const_iterator;
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif
