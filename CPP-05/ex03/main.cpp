#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern intern;
    Bureaucrat alice("Alice", 1);

    // Create forms
    AForm *form1 = intern.makeForm("shrubbery creation", "Home");
    AForm *form2 = intern.makeForm("robotomy request", "Bender");
    AForm *form3 = intern.makeForm("presidential pardon", "John Doe");
    AForm *form4 = intern.makeForm("unknown form", "Target");

    // Execute forms
    if (form1) {
        alice.signForm(*form1);
        alice.executeForm(*form1);
        delete form1;
    }
    if (form2) {
        alice.signForm(*form2);
        alice.executeForm(*form2);
        delete form2;
    }
    if (form3) {
        alice.signForm(*form3);
        alice.executeForm(*form3);
        delete form3;
    }
    delete form4;
    return 0;
}