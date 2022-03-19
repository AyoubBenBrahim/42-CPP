
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class GradeException : public std::runtime_error
{
public:
	GradeException(const std::string &error) : std::runtime_error(error.c_str())
	{
	}
};

class Form
{

private:
    std::string const   name;
    bool                is_Signed;
    int const           gradeSign;
    int const           gradeExec;

public:
    Form(void);
    Form(std::string const &, int, int);
    ~Form(void);
    Form(Form const &);

    Form&       operator=(Form const &);
    std::string getName(void) const;
    int         getGradeSign(void) const;
    int         getGradeExec(void) const;
    bool        getStatus(void) const;
    void        setStatus(bool is_Signed);

    void        beSigned(Bureaucrat const &);

    class GradeTooHighException : public GradeException
    {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public GradeException
    {
    public:
        GradeTooLowException();
    };
};

std::ostream &operator<<(std::ostream &outStream, Form const &);

#endif
