
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class MyExceptions : public std::runtime_error
{
public:
    MyExceptions(const std::string &error) : std::runtime_error(error.c_str())
    {
    }
};

class Form
{

private:
    std::string const name;
    bool is_Signed;
    int const gradeSign;
    int const gradeExec;
    std::string target;

public:
    Form(void);
    Form(std::string, int, int, std::string);
    ~Form(void);
    Form(Form const &);

    Form &operator=(Form const &);
    std::string getName(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    bool getStatus(void) const;
    std::string getTarget(void) const;
    void setStatus(bool is_Signed);

    void beSigned(Bureaucrat const &);

    virtual void execute(Bureaucrat const &executor) const = 0;
    // virtual void 	action() const = 0;

    class GradeTooHighException : public MyExceptions
    {
    public:
        GradeTooHighException();
    };

    class GradeTooLowException : public MyExceptions
    {
    public:
        GradeTooLowException();
    };

    class UnsignedFormException : public MyExceptions
    {
    public:
        UnsignedFormException();
    };

    class FileException : public MyExceptions
    {
    public:
        FileException();
    };

    class InvalidFormException : public MyExceptions
    {
    public:
        InvalidFormException();
    };

    class FormIsNullException : public MyExceptions
    {
    public:
        FormIsNullException();
    };
};

std::ostream &operator<<(std::ostream &outStream, Form const &);

#endif
