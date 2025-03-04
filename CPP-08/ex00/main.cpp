#include "Easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
    // Test with std::vector<int>
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found 30 in vector at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Vector test failed: " << e.what() << std::endl;
    }

    // Test with std::list<int> 
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found 25 in list at position: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cout << "List test failed: " << e.what() << std::endl;
    }

    // Test with std::deque<int> 
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);

    try {
        std::deque<int>::iterator it = easyfind(deq, 500);
        std::cout << "Found 500 in deque at position: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Deque test failed: " << e.what() << std::endl;
    }

    // Test with missing value
    try {
        easyfind(vec, 99);  // Should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught (not found in vector): " << e.what() << std::endl;
    }

    try {
        easyfind(lst, 10);  // Should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught (not found in list): " << e.what() << std::endl;
    }

    try {
        easyfind(deq, 600);  // Should throw an exception
    } catch (const std::exception &e) {
        std::cout << "Exception caught (not found in deque): " << e.what() << std::endl;
    }

    return 0;
}
