

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
	: GradeException("Err: grade too High.")
{
}

Form::GradeTooLowException::GradeTooLowException()
	: GradeException("Err: grade too Low.")
{
}

Form::Form(std::string const &n, int grd_sign, int grd_exec)
	: name(n), gradeSign(grd_sign), gradeExec(grd_exec)
{
	is_Signed = false;
	if (this->gradeSign < 1 || this->gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeSign > 150 || this->gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
}

Form::Form(Form const &copy) : name(copy.name),
							   is_Signed(copy.is_Signed),
							   gradeSign(copy.gradeSign),
							   gradeExec(copy.gradeExec)
{
	*this = copy;
}

Form &Form::operator=(Form const &rhs)
{
	this->is_Signed = rhs.getStatus();
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getStatus(void) const
{
	return (this->is_Signed);
}

int Form::getGradeSign(void) const
{
	return (this->gradeSign);
}

int Form::getGradeExec(void) const
{
	return (this->gradeExec);
}

void Form::setStatus(bool is_Signed)
{
	this->is_Signed = is_Signed;
}

void Form::beSigned(Bureaucrat const &br)
{
	if (br.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	// else if (this->getStatus() == false)
	// {
	// 	std::cout << this->getName() << " is already sign." << std::endl;
	// 	return;
	// }
	this->setStatus(true);
	// this->is_Signed = true;
}

std::ostream &operator<<(std::ostream &outStream, Form const &rhs)
{
	outStream << rhs.getName() << ", Form " << rhs.getStatus() << std::endl;
	return outStream;
}