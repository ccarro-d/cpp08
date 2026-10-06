/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 23:56:37 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/07 00:29:53 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
	*this = other;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		this->c = other.c;
	return(*this);
}

template <typename T>
typename std::stack<T>::container_type::iterator& MutantStack<T>::begin()
{
	
}