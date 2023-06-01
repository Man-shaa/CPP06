/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:45:51 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/25 14:57:12 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

ScalarConverter	&ScalarConverter::operator = (ScalarConverter const &toCopy)
{
	(void)toCopy;
	return (*this);
}

bool	onlyDigit(std::string input)
{
	int	i = 0;
	int	eskilyadespouainx = 0;

	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0
		|| input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
		return (true);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while ((input[i] && (input[i] <= '9' && input[i] >= '0')))
	{
		if (input[i] == '.')
			eskilyadespouainx++;
		i++;
	}
	if (input[i] == 'f')
		i++;
	if (i == static_cast<int>(input.size()) && eskilyadespouainx <= 1)
		return (true);
	return (false);
}

int	ScalarConverter::convert(std::string input)
{
	if (onlyDigit(input) == false || (input.size() > 9 && input[9]!= 'f'))
	{
		std::cout << "invalid argument" << std::endl;
		return (1);
	}
	ScalarConverter::printChar(input);
	ScalarConverter::printInt(input);
	ScalarConverter::printFloat(input);
	ScalarConverter::printDouble(input);
	return (0);
}

void	ScalarConverter::printChar(std::string str)
{
	std::istringstream	iss(str);
	int					value;
	int					eskilyaunpouain = str.find('.') + 1;

	while (eskilyaunpouain != 0 && eskilyaunpouain < static_cast<int>(str.size()) && str[eskilyaunpouain] == '0')
		eskilyaunpouain++;
	if (str[eskilyaunpouain] == 'f')
		eskilyaunpouain++;
	if (eskilyaunpouain == static_cast<int>(str.size()))
		eskilyaunpouain = 1;
	else
		eskilyaunpouain = 0;
	if (iss >> std::fixed >> value && str.compare("0") > 0 && (!(str.find('.') < str.size()) || eskilyaunpouain))
	{
		char c = static_cast<char>(value);
		if (value >= 32 && value <= 126)
			std::cout << "Char : " << c << std::endl;
		else
			std::cout << "Char : Non displayable" << std::endl;

	}
	else
		std::cout << "Char : impossible" << std::endl;
}

void	ScalarConverter::printInt(std::string str)
{
	std::istringstream	iss(str);
	int 				i;

	if (iss >> i)
		std::cout << "Int : " << i << std::endl;
	else if (str.compare("pi") == 0)
		std::cout << "3" << std::endl;
	else
		std::cout << "Int : impossible" << std::endl;
}

void	ScalarConverter::printFloat(std::string str)
{
	std::istringstream	iss(str);
	float 				f;
	int					eskilyaunf = str.find('f');

	eskilyaunf = eskilyaunf > 0 ? 1 : 0;
	if (iss >> f)
	{
		if (str.size() - str.find('.') > 1 && str.find('.') < str.size())
		{
			std::cout << "Float : "<< std::setprecision(str.size() - str.find('.') - eskilyaunf - 1)
			<< std::fixed << f << "f" << std::endl;
		}
		else
		{
			std::cout << "Float : "<< std::setprecision(1)
			<< std::fixed << f << "f" << std::endl;
		}
	}
	else if (str.compare("nan") == 0 || str.compare("+inf") == 0 || str.compare("-inf") == 0)
		std::cout << "Float : " << str << "f" << std::endl;
	else if (str.compare("nanf") == 0 || str.compare("+inff") == 0 || str.compare("-inff") == 0)
		std::cout << "Float : " << str << std::endl;
	else if (str.compare("pi") == 0)
		std::cout << "3.14159265358979323846f" << std::endl;
	else
		std::cout << "Float : impossible" << std::endl;
}

void	ScalarConverter::printDouble(std::string str)
{
	std::istringstream	iss(str);
	double 				d;

	if (iss >> d)
		std::cout << "Double : " << d << std::endl;
	else if (str.compare("nan") == 0 || str.compare("+inf") == 0 || str.compare("-inf") == 0)
		std::cout << "Double : " << str << std::endl;
	else if (str.compare("nanf") == 0 || str.compare("+inff") == 0 || str.compare("-inff") == 0)
		std::cout << "Double : " << str.replace(str.size() - 1, 1, "\0") << std::endl;
	else if (str.compare("pi") == 0)
		std::cout << "3.14159265358979323846" << std::endl;
	else
		std::cout << "Double : impossible" << std::endl;
}
