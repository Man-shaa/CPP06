/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:34:02 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/22 15:04:47 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cmath>

class Base
{
	public:

		virtual ~Base(void);

		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);
};

#endif
