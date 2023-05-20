/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:46:13 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/20 16:57:30 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "tuto : ./convert [str]" << std::endl;
		return (1);
	}
	std::string	input = av[1];
	ScalarConverter::convert(input);
	return (0);
}
