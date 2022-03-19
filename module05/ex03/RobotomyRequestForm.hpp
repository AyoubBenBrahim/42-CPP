
#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm &);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &);
	virtual ~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &executor) const;
};

#endif