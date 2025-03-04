#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private :
        std::string const _name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

public :

        Form();
        Form(Form const &obj);
        Form &operator=(Form const &rhs);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };
}; 

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif