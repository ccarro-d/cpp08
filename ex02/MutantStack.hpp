/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 23:49:29 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/07 19:16:55 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator begin();
		iterator end();
		
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp"

#endif