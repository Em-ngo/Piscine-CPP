#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();

        void fordJohnsonSort(std::vector<int> &vec);
        void fordJohnsonSort(std::deque<int> &deq);
        void sortAndPrint(const std::vector<int> &numbers);
    
        template <typename T>
        void createPairs(T &container, std::vector<std::pair<int, int> > &pairs, int &straggler);
    
        template <typename T>
        void sortBigElements(std::vector<std::pair<int, int> > &pairs, T &sortedBigs);
    
        template <typename T>
        void insertSmalls(std::vector<std::pair<int, int> > &pairs, T &sortedBigs, int straggler);
    };

#endif
