#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << "===== Test MutantStack =====" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17); 
    std::cout << "Top: " << mstack.top() << std::endl; // Result : 17

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Result : 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Iterating through MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin(); // Result : 5
    MutantStack<int>::iterator ite = mstack.end(); // Result : 0
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Wit std::list
    std::cout << "===== Test std::list =====" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Iterating through std::list:" << std::endl;
    std::list<int>::iterator lit = lst.begin(); // Result : 5
    std::list<int>::iterator lite = lst.end(); // Result : 0
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}
