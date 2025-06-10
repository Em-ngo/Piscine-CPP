#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

void PmergeMe::sortAndPrint(const std::vector<int> &numbers) {
    std::vector<int> vec(numbers);
    std::deque<int> deq(numbers.begin(), numbers.end());

    clock_t startVec = clock();
    fordJohnsonSort(vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;

    clock_t startDeq = clock();
    fordJohnsonSort(deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::vector : " << timeVec << " seconds" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() 
              << " elements with std::deque : " << timeDeq << " seconds" << std::endl;
}


void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> sortedBigs;
    int straggler = -1;

    createPairs(vec, pairs, straggler);
    sortBigElements(pairs, sortedBigs);
    insertSmalls(pairs, sortedBigs, straggler);

    vec = sortedBigs; 
}

void PmergeMe::fordJohnsonSort(std::deque<int> &deq) {
    std::vector<std::pair<int, int> > pairs;
    std::deque<int> sortedBigs;
    int straggler = -1;

    createPairs(deq, pairs, straggler);
    sortBigElements(pairs, sortedBigs);
    insertSmalls(pairs, sortedBigs, straggler);

    deq = sortedBigs; 
}


template <typename T>
void PmergeMe::createPairs(T &container, std::vector<std::pair<int, int> > &pairs, int &straggler) {
    typename T::iterator it = container.begin();
    while (it != container.end()) {
        int first = *it;
        ++it;
        if (it != container.end()) {
            int second = *it;
            ++it;
            if (first > second) std::swap(first, second);
            pairs.push_back(std::make_pair(first, second));
        } else {
            straggler = first;
        }
    }
}

// [4, 3, 8, 1, 7] -> Créer des paires (min, max) et straggler = chiffre orphelin
// [3,4], [1,8], [7]

template <typename T>
void PmergeMe::sortBigElements(std::vector<std::pair<int, int> > &pairs, T &sortedBigs) {
    for (size_t i = 0; i < pairs.size(); i++) {
        sortedBigs.push_back(pairs[i].second);
    }
    std::sort(sortedBigs.begin(), sortedBigs.end());
}

// Extraire les nombres les plus grands de chaque paire et les trie 
// On prend 4 et 8 -> on trie [4, 8] 

template <typename T>
void PmergeMe::insertSmalls(std::vector<std::pair<int, int> > &pairs, T &sortedBigs, int straggler) {
    for (size_t i = 0; i < pairs.size(); i++) {
        typename T::iterator pos = std::lower_bound(sortedBigs.begin(), sortedBigs.end(), pairs[i].first);
        sortedBigs.insert(pos, pairs[i].first);
    }
    if (straggler != -1) {
        typename T::iterator pos = std::lower_bound(sortedBigs.begin(), sortedBigs.end(), straggler);
        sortedBigs.insert(pos, straggler);
    }
}

// Reste 3 et 1, on insère 1 -> [1, 4, 8] et ensuite 3 -> [1, 3, 4, 8]
// Si straggler != -1 on insère aussi avec lower_bound.
