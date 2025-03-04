#include "Intern.hpp"

// Constructor and Destructor
Intern::Intern() {

}
Intern::Intern(const Intern &other) { 
    (void)other; 
}

Intern &Intern::operator=(const Intern &rhs) { 
    (void)rhs; return *this; 
}

Intern::~Intern() {

}

// Helper functions for form creation
AForm *createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// makeForm Method
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    const std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(*formCreators[])(const std::string &) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };

    for (size_t i = 0; i < 3; ++i) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Error: Form \"" << formName << "\" not recognized." << std::endl;
    return NULL; 
}