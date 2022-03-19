
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void test(Bureaucrat &bur, Form &form)
{
    std::cout << "\n\033[33m" << form.getName() << "\033[0m form: " << std::endl;
    std::cout << "Signing by " << bur.getName() << std::endl;
    bur.signForm(form);
    std::cout << "Executing by " << bur.getName() << std::endl;
    bur.executeForm(form);
}

int main()
{
    Bureaucrat Laarbi("Laarbi", 30);
    Bureaucrat BoYo("BoYo", 1);
    Bureaucrat Terab("Terab", 45);

    ShrubberyCreationForm shrub(BoYo.getName());
    PresidentialPardonForm presiden(Terab.getName());
    RobotomyRequestForm robot(Laarbi.getName());

    std::cout << "\033[34mNormal\033[0m tests : " << std::endl;

    test(Laarbi, robot);
    test(BoYo, shrub);
    test(Terab, presiden);

    return (0);
}