#include "PmergeMe.hpp"
#include <cstdlib>

int main(int ac, char** av) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <list of positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]);
        if (arg.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int num = std::atoi(arg.c_str());
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }

    PmergeMe sorter;
    sorter.sortAndPrint(numbers);

    return 0;
}
