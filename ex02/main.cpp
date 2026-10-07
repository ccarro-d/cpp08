/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 23:58:42 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/07 21:10:59 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::cout << "MutantStack created" <<std::endl;
	std::cout << "MutantStack is empty? --> ";
	if (mstack.empty())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "Let's add elements" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		int element = i * 3 + i;
		mstack.push(element);
		std::cout << "Element " << element << " was added to MutantStack" << std::endl;
	}
	std::cout << "MutantStack is empty? --> ";
	if (mstack.empty())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << "MutantStack size? --> " << mstack.size() << std::endl;
	std::cout << std::endl << "Top element is " << mstack.top() << std::endl;
	
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();
	int elements = 0;
	while (it != end)
	{
		++it;
		++elements;
	}
	--it;
	std::cout << "_______" << std::endl;
	for (int j = 0; j < elements; j++)
	{
		std::cout << "|     |" << std::endl;
		if (*it / 10 == 0)
			std::cout << "|  " << *it << "  |" << std::endl;
		else
			std::cout << "|  " << *it << " |" << std::endl;
		std::cout << "|_____|" << std::endl;
		if (j < elements - 1) // Para no decrementar más allá de begin()
			--it;
	}
	
	
	mstack.pop();
	std::cout << std::endl << "MutantStack top element deleted" << std::endl;
	std::cout << "Top element is " << mstack.top() << std::endl;
	--elements; // Actualizamos número de elementos
	it = mstack.end(); // Nuevo iterador al final (arriba del todo)
	--it;
	std::cout << "_______" << std::endl;
	for (int j = 0; j < elements; j++)
	{
		std::cout << "|     |" << std::endl;
		if (*it / 10 == 0)
			std::cout << "|  " << *it << "  |" << std::endl;
		else
			std::cout << "|  " << *it << " |" << std::endl;
		std::cout << "|_____|" << std::endl;
		if (j < elements - 1) // Para no decrementar más allá de begin()
			--it;
	}

	
	it = mstack.end(); // Nuevo iterador al final (arriba del todo)
	--it;
	*it = 99;
	std::cout << std::endl << "Top element changed to " << mstack.top() << std::endl;
	std::cout << "_______" << std::endl;
	for (int j = 0; j < elements; j++)
	{
		std::cout << "|     |" << std::endl;
		if (*it / 10 == 0)
			std::cout << "|  " << *it << "  |" << std::endl;
		else
			std::cout << "|  " << *it << " |" << std::endl;
		std::cout << "|_____|" << std::endl;
		if (j < elements - 1) // Para no decrementar más allá de begin()
			--it;
	}

	const MutantStack<int> cmstack(mstack);
	MutantStack<int>::const_iterator cit = cmstack.begin();
	++cit;
	//*cit = 3; // Al ser const, no podemos modificar su contenido. No compila si quitamos este comment

	return 0;
}