#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private :
        std::string const _name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

public :

        AForm();
        AForm(AForm const &obj);
        AForm &operator=(AForm const &rhs);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const &exec) const = 0;

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            const char *what() const throw();
        };
}; 

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif