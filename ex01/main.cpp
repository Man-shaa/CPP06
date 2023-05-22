/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:12:57 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/22 14:31:47 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// La fonction uintptr_t serialize(Data *ptr) est définie. Cette fonction prend un 
// pointeur vers un objet de type Data en entrée et retourne une valeur de type uintptr_t. 
// uintptr_t est un type entier non signé capable de stocker des pointeurs sans conversion. 
// La fonction utilise reinterpret_cast pour convertir le pointeur ptr en une valeur de type 
// uintptr_t, qui représente essentiellement l'adresse mémoire à laquelle le pointeur pointe.

// La fonction Data *deserialize(uintptr_t raw) est définie. Cette fonction prend 
// une valeur de type uintptr_t en entrée et retourne un pointeur vers un objet de type Data.
// La fonction utilise reinterpret_cast pour convertir la valeur raw de type uintptr_t en un 
// pointeur de type Data *. Cela reconstitue essentiellement le pointeur original à partir de 
// la valeur sérialisée.

int main(void)
{
    Data data;
    data.str = "Shanley le fou";

    uintptr_t serialized = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == &data)
        std::cout << "Le pointeur est identique." << std::endl;
	else
        std::cout << "Le pointeur n'est pas identique." << std::endl;

    return (0);
}

// int	main(void)
// {
// 	Data		*ptr = new Data;
// 	Data		*serialized;
// 	uintptr_t	raw;

// 	ptr->str = "Shanley le fou";

// 	raw = Serializer::serialize(ptr);

// 	serialized = Serializer::deserialize(raw);

// 	std::cout << "serialized->str = " << serialized->str << std::endl;
// 	delete (ptr);
// 	return (0);
// }
