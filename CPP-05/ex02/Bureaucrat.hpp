#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"


class AForm;


class Bureaucrat {
    
private :
        std::string const _name;
        int _grade;

public :
        Bureaucrat();
        Bureaucrat(Bureaucrat const &obj);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat const &rhs);
        Bureaucrat(std::string name, int grade);


        std::string const getName() const;
        int   getGrade() const ;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                    const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                    const char *what() const throw();
        };
 
        void signForm(AForm &form);
        void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif