
#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat *bokrat = new Bureaucrat("bokrat11", 17);
			bokrat->incrGrade();
			std::cout << *bokrat;
			delete bokrat;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "------------" << std::endl;
			Bureaucrat *bokrat = new Bureaucrat("bokrat22", 1);
			std::cout << *bokrat;
			bokrat->incrGrade();
			delete bokrat;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "------------" << std::endl;
			Bureaucrat *bokrat = new Bureaucrat("bokrat33", 150);
			std::cout << *bokrat;
			bokrat->decrGrade();
			delete bokrat;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n=========================================\n\n";

	{
		Bureaucrat *sokrat = new Bureaucrat("Laarbi", 2);
		try
		{
			sokrat = new Bureaucrat("test", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << *sokrat;
		sokrat->incrGrade();
		std::cout << *sokrat;

		try
		{
			sokrat->incrGrade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "GradeTooLowException" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "GradeTooHighException" << std::endl;
		}
		for (int i = 0; i < 152; i++)
		{
			try
			{
				sokrat->decrGrade();
			}
			catch (Bureaucrat::GradeTooLowException &e)
			{
				std::cout << "GradeTooLowException" << std::endl;
			}
			catch (Bureaucrat::GradeTooHighException &e)
			{
				std::cout << "GradeTooHighException" << std::endl;
			}
		}

		std::cout << *sokrat;
		Bureaucrat b(*sokrat);
		
		delete sokrat;
	}

	return (0);
}
