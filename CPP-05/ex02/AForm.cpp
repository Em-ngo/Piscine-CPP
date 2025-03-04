#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150) {

}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &obj) : _name(obj._name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {

}

AForm &AForm::operator=(AForm const &rhs) {
    if (this != &rhs) {
        isSigned = rhs.isSigned;
    }
    return *this;
}

AForm::~AForm() {

}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
    out << "Form: " << AForm.getName() << ", Signed: " << (AForm.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << AForm.getGradeToSign() << ", Grade to Execute: " << AForm.getGradeToExecute();
    return out;
}