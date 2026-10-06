/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 23:49:29 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/07 00:28:20 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);

		typename std::stack<T>::container_type::iterator	iterator
		iterator& begin();
		iterator& end();
};

#endif