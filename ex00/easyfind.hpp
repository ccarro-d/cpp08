/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:48:03 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/09 22:48:21 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <sstream>

// Para contenedores modificables. Aunque retorne un iterator, el código que recibe el resultado el que puede convertirlo implícitamente a const_iterator dentro de un contenedor modificable
template <typename T>
typename T::iterator easyfind(T& container, int tofind) // typename indica que T::iterator es un tipo dependiente del parametro template T.
{
	typename T::iterator found = std::find(container.begin(), container.end(), tofind);
	if (found == container.end())
	{
		std::stringstream ss;
		ss << "Value " << tofind << " not found ";
		throw std::runtime_error(ss.str()); // Excepción que deriva std::exception al que le podemos pasar un mensaje en su constructor para su método what()
	}
	return (found);
}


// Para contenedores const
template <typename T>
typename T::const_iterator easyfind(const T& container, int tofind) // typename indica que T::const_iterator es un tipo dependiente. Al recibir const T&, devolvemos un iterator que no permite modificar los elementos.
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