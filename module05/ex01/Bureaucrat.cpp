#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: GradException("Err: grade too High.")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	: GradException("Err: grade too Low.")
{
}

Bureaucrat::Bureaucrat(std::string nm, int gr) : name(nm), grade(gr)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{

	if (copy.grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (copy.grade > 150)
		throw Bureaucrat::GradeTooLowException();

	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this == &rhs)
		return *this;

	this->grade = rhs.getGrade();
	std::cout << "Name is const and can't be overwritten, only grade was copied\n";
	// this->name = rhs.getName();

	return (*this);
}

std::string Bureaucrat::getName(void) const { return this->name; }
int Bureaucrat::getGrade(void) const { return this->grade; }

void Bureaucrat::incrGrade(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decrGrade(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

void							Bureaucrat::signForm(Form & frm)
{
	try {
		frm.beSigned(*this);
		std::cout << "<" << this->name << "> signs <" << frm.getName()<< ">" << std::endl;
	} catch (Form::GradeTooLowException const & e) {
		std::cout << "<" << this->name << "> cannot sign <" << frm.getName() << ">" << " because " << e.what() << std::endl;	
	} catch (std::exception const & e) {
		std::cout << "<" << this->name << "> cannot sign " << frm.getName() << ">" <<  " because " << e.what() << std::endl;	
	}
}

std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &rhs)
{
	outStream << "<" << rhs.getName() << ">, bureaucrat grade <" << rhs.getGrade() << ">.\n";
	return outStream;
}
