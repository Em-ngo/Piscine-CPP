#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

    Bureaucrat alice("Alice", 45);
    Bureaucrat bob("Bob", 20);

    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Target1");
    PresidentialPardonForm pardon("Target2");

    try {
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);
        std::cout << "\n";
        alice.signForm(robotomy);
        alice.executeForm(robotomy);
        std::cout << "\n";
        bob.signForm(pardon);
        bob.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}