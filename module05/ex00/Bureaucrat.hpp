#ifndef BUREAU_HPP
#define BUREAU_HPP

#include <exception>
#include <iostream>
#include <string>

class GradException : public std::runtime_error
{
public:
	GradException(const std::string &error) : std::runtime_error(error.c_str())
	{
	}
};

class Bureaucrat
{
private:
	std::string const name;
	int  grade; // 1 - 150

public:
	Bureaucrat(void);
	Bureaucrat(std::string , int );
	~Bureaucrat(void);
	Bureaucrat(std::string const &);
	Bureaucrat(const Bureaucrat &);

	Bureaucrat &operator=(const Bureaucrat &);
	std::string getName(void) const;
	int getGrade(void) const;

	void incrGrade();
	void decrGrade();

	class GradeTooHighException : public GradException //std::exception
	{
	public:
		GradeTooHighException();
	};

	class GradeTooLowException : public GradException // public std::exception
	{
	public:
		GradeTooLowException();
	};
};

std::ostream &operator<<(std::ostream &outStream, Bureaucrat const &);

#endif