

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <fstream>
#include "Form.hpp"

class Bureaucrat;


class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
	virtual ~ShrubberyCreationForm();
    virtual void			execute(Bureaucrat const & executor) const;
};

#endif
