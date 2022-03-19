

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
	: MyExceptions("Err: grade too High.")
{
}

Form::GradeTooLowException::GradeTooLowException()
	: MyExceptions("Err: grade too Low.")
{
}

Form::UnsignedFormException::UnsignedFormException()
	: MyExceptions("Err: Form not Signed.")
{
}

Form::FileException::FileException()
	: MyExceptions("Err: Could not create/open File .")
{
}

Form::InvalidFormException::InvalidFormException()
	: MyExceptions("Err: Invalid Form Name.")
{
}

Form::FormIsNullException::FormIsNullException()
	: MyExceptions("Err: Form is NULLLLLLLLLLLLLLLLLLLLLLLLL")
{
}

Form::Form(const std::string n, int grd_sign, int grd_exec, std::string targ)
	: name(n), gradeSign(grd_sign), gradeExec(grd_exec), target(targ)
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
							   gradeExec(copy.gradeExec),
							   target(copy.target)
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

std::string Form::getTarget() const
{
	return (this->target);
}

void Form::setStatus(bool is_Signed)
{
	this->is_Signed = is_Signed;
}

void Form::beSigned(Bureaucrat const &br)
{
	if (br.getGrade() <= this->getGradeSign())
		this->setStatus(true);
	else
		throw GradeTooLowException();
}

void Form::execute(Bureaucrat const &executor) const
{
	if (this->getStatus() == false)
		throw UnsignedFormException();
	else if (executor.getGrade() > this->gradeExec)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outStream, const Form &rhs)
{
	outStream << rhs.getName() << ", Form sign grade: " << rhs.getGradeSign() << ", execution grade : "
			  << rhs.getGradeExec() << "\nState: ";
	if (rhs.getStatus())
		outStream << "Signed";
	else
		outStream << "Unsigned";
	outStream << std::endl;
	return outStream;
}