#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class PresidentialPardonForm : public AForm {

private:
    const std::string target;

public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const &exec) const;
};

#endif
