

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreation", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &frm)
	: Form(frm)
{
	*this = frm;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &frm)
{
	this->Form::operator=(frm);

	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->Form::execute(executor);
	std::string outputFile = this->getTarget().append("_shrubbery");

	std::ofstream outStream(outputFile);
	if (!outStream.is_open())
		throw Form::FileException();

	outStream << std::endl;
	outStream << "              ,@@@@@@@," << std::endl;
	outStream << "      ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outStream << "   ,&\\%\\%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outStream << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outStream << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outStream << "  %&&%/ %&\\%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outStream << "  `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outStream << "      |o|        | |         | |" << std::endl;
	outStream << "      |.|        | |         | |" << std::endl;
	outStream << "___ \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	outStream << "---   -------- --------  --------  -----" << std::endl;
	outStream << "-  -----    ------ ----  ----- ------" << std::endl;

	outStream.close();
}
