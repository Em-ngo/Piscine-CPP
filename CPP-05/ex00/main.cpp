#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("François", 2);
        std::cout << b << std::endl;

        b.incrementGrade();
        std::cout << b << std::endl;

        b.incrementGrade(); // should throw an exception
    }   
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n";

    try {
        Bureaucrat c("Jean", 149);
        std::cout << c << std::endl;

        c.decrementGrade();
        std::cout << c << std::endl;

        c.decrementGrade(); // should throw an exception
    }
    catch (std::exception &ee) {
        std::cerr << ee.what() << std::endl;
    }
}