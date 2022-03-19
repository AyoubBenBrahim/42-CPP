

#include "Intern.hpp"

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &burokrat)
{
    *this = burokrat;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &burokrat)
{
    (void)burokrat;
    return (*this);
}

TASK Intern::mapping(std::string const &form)
{
    if (form == "RobotomyRequestForm")
        return RobotomyRequestF;
    else if (form == "PresidentialPardonForm")
        return PresidentialPardonF;
    else if (form == "ShrubberyCreationForm")
        return ShrubberyCreationF;

    return Invalid;
}

Form *Intern::makeForm(const std::string formName, const std::string target)
{
    switch (mapping(formName))
    {
    case RobotomyRequestF:
        return new RobotomyRequestForm(target);
        break;
    case PresidentialPardonF:
        return new PresidentialPardonForm(target);
        break;
    case ShrubberyCreationF:
        return new ShrubberyCreationForm(target);
        break;
    default:
        throw Form::InvalidFormException();
        // std::cout << "invalid form name" << std::endl;
        // return nullptr;
    }
}