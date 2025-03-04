#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    
}

void ShrubberyCreationForm::execute(Bureaucrat const &exec) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (exec.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        throw std::ios_base::failure("Error creating file");
    file << "   🌳   \n  🌳🌳  \n 🌳🌳🌳 \n";
    file.close();
}