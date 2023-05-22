/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:13:52 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/22 14:26:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct	Data
{
	std::string	str;
}				Data;

class Serializer
{
	private:

	public:

		Serializer(void);
		Serializer(Serializer const &copy);
		~Serializer(void);

		Serializer	&operator = (Serializer const &toCopy);

		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif