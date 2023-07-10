#include "Conversion.hpp"

Conversion::Conversion(std::string in) : input(in)
{
	_isChar = false;
	_isInt = false;
	_isFloat = false;
	_isDouble = false;
	_isPseudoLiteral = false;

	isInt(in);
	isFloat(in);
	isDouble(in);
	isPseudoLiteral(in);
}

Conversion::~Conversion()
{
}

Conversion::Conversion(const Conversion &copy)
{
	_isChar = false;
	_isInt = false;
	_isFloat = false;
	_isDouble = false;
	_isPseudoLiteral = false;

	*this = copy;
}

Conversion &Conversion::operator=(const Conversion &rhs)
{
	if (this == &rhs)
		return *this;

	this->input = rhs.input;
	return *this;
}

void Conversion::isInt(std::string input)
{
	int i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return;
		i++;
	}
	this->_isInt = true;
}

void Conversion::isFloat(std::string input)
{
	int i = 0;

	bool isDot = false;
	if (input.c_str()[0] == '-')
		i++;
	while (input[i])
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.' && input[i] != 'f')
			return;
		if (input[i] == '.' && isDot == true)
			return;
		if (input[i] == 'f' && (input[i + 1] || isDot == false))
			return;
		if (input[i] == '.')
			isDot = true;
		i++;
	}
	if (input[i - 1] == 'f')
	{
		this->_isFloat = true;
		return;
	}
}

void Conversion::isDouble(std::string input)
{
	int i = 0;
	bool isDot = false;
	if (input[i] == '-')
		i++;
	while (input[i] != '\0')
	{
		if ((input[i] < '0' || input[i] > '9') && input[i] != '.')
			return;
		if (input[i] == '.' && isDot == true)
			return;
		if (input[i] == '.')
			isDot = true;
		i++;
	}
	if (isDot)
		this->_isDouble = true;
}

void Conversion::isPseudoLiteral(std::string input)
{
	if (input == "-inff" || input == "+inff" ||  input == "inff" || input == "nanf" 
		|| input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
	{
		this->_isPseudoLiteral = true;
		if (this->input[this->input.length() - 1] == 'f' && this->input[this->input.length() - 2] == 'f')
			this->input = input.substr(0, input.length() - 1);
		if (input == "inf" || input == "inff")
			this->input = input.insert(0, "+");
		if (input == "nanf")
			this->input = "nan";
	}
}

void Conversion::printOrchestration()
{
	if (this->input.length() == 1 && !isdigit(this->input[0]))
	{
		this->charHandler();
		this->_isChar = true;
	}
	else if (_isInt)
		this->intergerHandler();
	else if (_isFloat)
		this->floatHandler();
	else if (_isDouble)
		this->doubleHandler();

	if (_isPseudoLiteral)
		this->printPseudoLiteral();
	else if (_isChar || _isInt || _isFloat || _isDouble)
		Conversion::printer();
	else
		std::cerr << "WRONG INPUT\n";
}

void Conversion::printPseudoLiteral()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << this->input << "f" << std::endl;
	std::cout << "double: " << this->input << std::endl;
}

void Conversion::charHandler()
{
	this->charHolder = this->input[0];

	this->intHolder = static_cast<int>(this->charHolder);
	this->floatHolder = static_cast<float>(this->charHolder);
	this->doubleHolder = static_cast<double>(this->charHolder);
}

void Conversion::intergerHandler()
{
	try
	{
		this->intHolder = std::stol(this->input, nullptr, 10);
	}
	catch(const std::exception& e)
	{
		this->intHolder = LONG_MAX;
	}
	
	this->charHolder = static_cast<char>(this->intHolder);
	this->floatHolder = static_cast<float>(this->intHolder);
	this->doubleHolder = static_cast<double>(this->intHolder);
}

void Conversion::floatHandler()
{
	this->floatHolder = std::stod(this->input); // stod is cpp11 not 98, just noticed

	this->intHolder = static_cast<long>(this->floatHolder);
	this->charHolder = static_cast<char>(this->floatHolder);
	this->doubleHolder = static_cast<double>(this->floatHolder);
}

void Conversion::doubleHandler()
{
	this->doubleHolder = std::stod(this->input);

	this->intHolder = static_cast<long>(this->doubleHolder);
	this->charHolder = static_cast<char>(this->doubleHolder);
	this->floatHolder = static_cast<double>(this->doubleHolder);
}

void Conversion::printer()
{
	if (this->intHolder > std::numeric_limits<char>::max() || this->intHolder < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(this->charHolder))
		std::cout << "char: '" << this->charHolder << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (std::numeric_limits<int>::max() < this->intHolder || this->intHolder < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->intHolder << std::endl;

	if (this->floatHolder < -FLT_MAX || this->floatHolder > FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << this->floatHolder << "f" << std::endl;

	if (this->doubleHolder < -DBL_MAX || this->doubleHolder > DBL_MAX)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << this->doubleHolder << std::endl;
}
