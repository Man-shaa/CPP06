/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:33:52 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/22 15:09:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
	return ;
}

Base	*Base::generate(void)
{
	srand(time(0));
	int randomNbr = rand() % 3;
	if (randomNbr == 0)
		return (new A());
	else if (randomNbr == 1)
		return (new B());
	return (new C());
}

void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Le type de p est A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Le type de p est B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Le type de p est C" << std::endl;
	else
		std::cerr << "Le type de p est inconnu" << std::endl;
}

void	Base::identify(Base& p)
{
	identify(&p);
}
