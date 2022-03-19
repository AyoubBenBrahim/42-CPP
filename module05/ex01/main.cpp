
#include "Form.hpp"

int main()
{

        std::cout << "< =================== >" << std::endl;

        try
        {
                Bureaucrat Laarabi("Laarabi", 60);
                Bureaucrat BoYo("BoYo", 1);
                Form LaBourse("LaBourse", 12, 10);
                Form s1337("s1337", 70, 12);
                BoYo.signForm(LaBourse);
                Laarabi.signForm(LaBourse);
                Laarabi.incrGrade();
                std::cout << "After incremeting " << Laarabi.getName() << "'s grade" << std::endl;
                std::cout << Laarabi;
                Laarabi.signForm(s1337);
                BoYo.decrGrade();
                std::cout << BoYo;
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << std::endl;
        }

        std::cout << "\n< =================== >\n"
                  << std::endl;

        try
        {
                Bureaucrat Laarabi("Laarabi", 100);
                Form s1337("s1337", 70, 12);
                std::cout << Laarabi;
                s1337.beSigned(Laarabi);
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << std::endl;
        }
}