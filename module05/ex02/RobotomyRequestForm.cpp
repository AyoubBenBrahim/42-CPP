
#include "RobotomyRequestForm.hpp"
#include <time.h> 

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &frm)
	: Form(frm)
{
	*this = frm;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &fr)
{
	this->Form::operator=(fr);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		this->Form::execute(executor);
		std::cout << "DrrrrrrrrrrrrrrrrrrrrrRRRRrilling...." << std::endl;
		srand(time(NULL));
		int random = rand() % 2;
		if (random)
			std::cout << this->getTarget() << " has been robotomized successfully 50\% of the time." << std::endl;
		else
			std::cout << "The executor failed to robotomize <" << this->getTarget() << ">." << std::endl;
	}
	catch (Form::UnsignedFormException const &e)
	{
		std::cout << this->getTarget() << " robotomization failure. ";
		std::cout << "UnsignedFormException" << std::endl;
	}
	catch (Form::GradeTooLowException const &e)
	{
		std::cout << this->getTarget() << " robotomization failure. ";
		std::cout << "GradeTooLowException" << std::endl;
	}
}