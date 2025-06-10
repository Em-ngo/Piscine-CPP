#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe&PmergeMe::operator=(PmergeMe const &) {
    return *this;
}


PmergeMe::PmergeMe(PmergeMe const &) {}


double PmergeMe::getTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

void PmergeMe::sortAndPrint(const std::vector<int> &numbers) {
    std::vector<int> vec(numbers);
    std::deque<int> deq(numbers.begin(), numbers.end());
    
    double startVec = getTimeInMicroseconds();
    fordJohnsonSort(vec);
    double endVec = getTimeInMicroseconds();
    double timeVec = endVec - startVec;
    
    double startDeq = getTimeInMicroseconds();
    fordJohnsonSort(deq);
    double endDeq = getTimeInMicroseconds();
    double timeDeq = endDeq - startDeq;
    
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
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
    if (vec.size() <= 1) return;
    
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> sortedBigs;
    int straggler = -1;
    
    createPairs(vec, pairs, straggler);
    
    // Extraire les grands éléments pour le tri récursif
    for (size_t i = 0; i < pairs.size(); i++) {
        sortedBigs.push_back(pairs[i].second);
    }
    
    // Tri récursif des grands éléments -> recreer des pairs
    fordJohnsonSort(sortedBigs);
    
    // Insérer les petits éléments 
    insertSmallsWithJacobsthal(pairs, sortedBigs, straggler);
    
    vec = sortedBigs;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &deq) {
    if (deq.size() <= 1) return;
    
    std::vector<std::pair<int, int> > pairs;
    std::deque<int> sortedBigs;
    int straggler = -1;
    
    createPairs(deq, pairs, straggler);
    
    // Extraire les grands éléments pour le tri récursif
    for (size_t i = 0; i < pairs.size(); i++) {
        sortedBigs.push_back(pairs[i].second);
    }
    
    // Tri récursif des grands éléments (cœur de Ford-Johnson)
    fordJohnsonSort(sortedBigs);
    
    // Insérer les petits éléments selon la séquence de Jacobsthal
    insertSmallsWithJacobsthal(pairs, sortedBigs, straggler);
    
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
            if (first > second) 
                std::swap(first, second);
            pairs.push_back(std::make_pair(first, second));
        } else {
            straggler = first;
        }
    }
}

// Génère la séquence de Jacobsthal : 1, 3, 5, 11, 21, 43, 85, ...
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    if (n == 0) 
        return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n == 1) 
        return jacobsthal;
    
    jacobsthal.push_back(3);
    
    for (size_t i = 2; jacobsthal.back() < n; i++) {
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > n) break;
        jacobsthal.push_back(next);
    }
    
    return jacobsthal;
}

// Génère l'ordre d'insertion basé sur la séquence de Jacobsthal
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(n);
    std::vector<bool> inserted(n + 1, false);
    
    // Toujours insérer le premier élément
    order.push_back(1);
    inserted[1] = true;
    
    // Pour chaque nombre de Jacobsthal, insérer les éléments en ordre décroissant
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t jacob_num = jacobsthal[i];
        size_t prev_jacob = jacobsthal[i-1];
        
        // Insérer de jacob_num vers prev_jacob+1 (ordre décroissant)
        for (size_t j = std::min(jacob_num, n); j > prev_jacob && !inserted[j]; j--) {
            order.push_back(j);
            inserted[j] = true;
        }
    }
    
    // Insérer les éléments restants
    for (size_t i = 1; i <= n; i++) {
        if (!inserted[i]) {
            order.push_back(i);
        }
    }
    
    return order;
}

template <typename T>
void PmergeMe::insertSmallsWithJacobsthal(std::vector<std::pair<int, int> > &pairs, T &sortedBigs, int straggler) {
    // Si straggler seul et pas de pairs, insert le straggler
    if (pairs.empty()) {
        if (straggler != -1) {
            typename T::iterator pos = std::lower_bound(sortedBigs.begin(), sortedBigs.end(), straggler);
            sortedBigs.insert(pos, straggler);
        }
        return;
    }
    
    // Insérer le premier petit élément (il va toujours au début)
    sortedBigs.insert(sortedBigs.begin(), pairs[0].first);
    
    // Générer l'ordre d'insertion pour les éléments restants
    std::vector<size_t> insertionOrder = generateInsertionOrder(pairs.size() - 1);
    
    // Insérer les petits éléments selon l'ordre de Jacobsthal
    for (size_t i = 0; i < insertionOrder.size(); i++) {
        size_t idx = insertionOrder[i] - 1; // Convertir en 0-based pour pairs
        if (idx + 1 < pairs.size()) { // idx+1 car on a déjà inséré pairs[0]
            int smallElement = pairs[idx + 1].first;
            typename T::iterator pos = std::lower_bound(sortedBigs.begin(), sortedBigs.end(), smallElement);
            sortedBigs.insert(pos, smallElement);
        }
    }
    
    // Insérer le straggler s'il existe
    if (straggler != -1) {
        typename T::iterator pos = std::lower_bound(sortedBigs.begin(), sortedBigs.end(), straggler);
        sortedBigs.insert(pos, straggler);
    }
}