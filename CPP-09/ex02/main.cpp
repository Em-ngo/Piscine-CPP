#include "PmergeMe.hpp"
#include <sstream>
#include <limits>

bool isValidPositiveInteger(const std::string& str) {
    if (str.empty()) return false;
    
    // Vérifier si c'est un nombre négatif
    if (str[0] == '-') return false;
    
    // Vérifier si tous les caractères sont des chiffres
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    
    // Vérifier si le nombre n'est pas trop grand
    std::istringstream iss(str);
    long long num;
    iss >> num;
    
    if (iss.fail() || num > std::numeric_limits<int>::max() || num < 0) {
        return false;
    }
    
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided" << std::endl;
        return 1;
    }
    
    std::vector<int> numbers;
    
    // Valider et convertir les arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (!isValidPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        
        int num = std::atoi(arg.c_str());
        numbers.push_back(num);
    }
    
    // Vérifie les doublons avant de lancer l'algo
    for (size_t i = 0; i < numbers.size(); i++) {
        for (size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
    }
    
    // Trier et afficher
    PmergeMe sorter;
    sorter.sortAndPrint(numbers);
    
    return 0;
}