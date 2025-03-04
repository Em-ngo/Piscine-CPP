#include "Form.hpp"

Form::Form() : _name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) {

}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) : _name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &obj) : _name(obj._name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) {

}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        isSigned = rhs.isSigned;
    }
    return *this;
}

Form::~Form() {

}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high for this form!";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low for this form!";
}


std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}