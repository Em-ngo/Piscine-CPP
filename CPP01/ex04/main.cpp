/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:15:55 by engo              #+#    #+#             */
/*   Updated: 2024/06/19 21:06:55 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <unistd.h> 
#include <cerrno>
#include "Replace.hpp"


int main(int ac, char **av) {
    
    if (ac != 4) {
        std::cerr << "\033[0;31mError format: " << av[0] << " <filename> <string1> <string2>\033[00m\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::ifstream inFile(filename.c_str());
    if (!inFile) {
        std::cerr << "\033[0;31mError opening file: \033[00m" << filename << "\n";
        return 1;
    }

    inFile.seekg(0, std::ios::end);
    if (inFile.tellg() == 0) {
        std::cerr << "\033[0;31mError: file is empty, nothing to replace.\n\033[00m";
        inFile.close();
        return 1;
    }

     if (access(filename.c_str(), R_OK) != 0) {
        std::cerr << "\033[0;31mError: file is not readable: \033[00m" << filename << std::endl;
        return 1;
    }

    if (access(filename.c_str(), W_OK) != 0) {
        std::cerr << "\033[0;31mError: file is not writable: \033[00m" << filename << std::endl;
        return 1;
    }
    
    inFile.seekg(0, std::ios::beg);

    bool found = false;
    if (!found) {
        std::cerr << "\033[0;31mError: no occurrence of '" << s1 << "' found in the text file, nothing to change.\033[00m\n";
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outFile(outputFilename.c_str());
    if (!outFile) {
        std::cerr << "\033[0;31mError creating file: \033[00m" << outputFilename << "\n";
        return 1;
    }

    std::string line;
    bool foundNonEmptyLine = false;
    
    while (getline(inFile, line)) {
        if (s1.empty()) {
            std::cerr << "\033[0;31mError: cannot replace empty string\n\033[00m";
            return 1;
        }
        
        foundNonEmptyLine = true;
 
        std::string replacedLine = replaceAll(line, s1, s2);
        outFile << replacedLine << "\n";
    }

    if (!foundNonEmptyLine) {
        std::cerr << "\033[0;31mError: file contains only empty lines, nothing to replace.\n\033[00m";
        return 1;
    }

    inFile.close();
    outFile.close();

    std::cout << "\033[0;32mFile processing completed. \033[00mOutput file: " << outputFilename << "\n";
    return 0;
}
