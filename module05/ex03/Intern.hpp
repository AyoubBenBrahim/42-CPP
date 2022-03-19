
#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

enum TASK
{
    RobotomyRequestF,
    PresidentialPardonF,
    ShrubberyCreationF,
    Invalid
};

class Intern
{
public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();

    Form *makeForm(const std::string, const std::string);
    TASK mapping(std::string const &form);
};

#endif // !INTERN_H