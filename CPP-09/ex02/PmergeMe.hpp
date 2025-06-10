#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <utility>
#include <sys/time.h>
#include <cctype>
#include <cstdlib>

class PmergeMe {
private:
    double getTimeInMicroseconds();
    
    template <typename T>
    void createPairs(T &container, std::vector<std::pair<int, int> > &pairs, int &straggler);
    
    std::vector<size_t> generateJacobsthalSequence(size_t n);
    std::vector<size_t> generateInsertionOrder(size_t n);
    
    template <typename T>
    void insertSmallsWithJacobsthal(std::vector<std::pair<int, int> > &pairs, T &sortedBigs, int straggler);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const &);
    PmergeMe&operator=(PmergeMe const &);
    void sortAndPrint(const std::vector<int> &numbers);
    void fordJohnsonSort(std::vector<int> &vec);
    void fordJohnsonSort(std::deque<int> &deq);
};

#endif