

#include "Intern.hpp"

int main()
{

    {
        try
        {
            Intern someRandomIntern;
            Form *rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "\n==============\n\n";

    {
        try
        {
            Intern someRandomIntern;
            Bureaucrat Laarbi("Laarbi", 150);
            Bureaucrat BoYo("BoYo", 20);
            Form *roboto = NULL;

            roboto = someRandomIntern.makeForm("RobotomyRequestForm", Laarbi.getName());

            std::cout << "\n";
            Laarbi.signForm(*roboto);
            std::cout << "\n\n";
            Laarbi.executeForm(*roboto);
            std::cout << "\n\n";
            BoYo.signForm(*roboto);
            std::cout << "\n\n";
            BoYo.executeForm(*roboto);
            std::cout << "\n\n";
            roboto = nullptr;
            roboto = someRandomIntern.makeForm("invalid form name", "Laarbi");
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
