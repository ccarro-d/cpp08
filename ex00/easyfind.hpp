/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:48:03 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/04 20:49:48 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <sstream>

template <typename T>
typename T::const_iterator easyfind(const T& container, int tofind) // Volvemos a usar typename porque iterator es un tipo definido dentro de otro tipo que es T. Necesitamos un const_iterator porque el container que recibimos es una referencia no modificable (const)
{
	typename T::const_iterator found = std::find(container.begin(), container.end(), tofind);
	if (found == container.end())
	{
		std::stringstream ss;
		ss << "Value " << tofind << " not found ";
		throw std::runtime_error(ss.str()); // Excepción que deriva std::exception al que le podemos pasar un mensaje en su constructor para su método what()
	}
	return (found);
}

#endif