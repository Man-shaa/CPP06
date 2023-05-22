/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/22 15:11:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int	main(void)
{
	Base	*obj = Base::generate();

	Base::identify(obj);
	Base::identify(*obj);
	delete (obj);
	return (0);
}
