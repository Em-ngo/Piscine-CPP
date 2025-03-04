#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const &exec) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (exec.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "Bzzzz... Drilling noises..." << std::endl;

    if (rand() % 2) {
        std::cout << target << " has been successfully robotomized!" << std::endl;
    } else {
        std::cout << "The robotomy of " << target << " failed!" << std::endl;
    }
}
