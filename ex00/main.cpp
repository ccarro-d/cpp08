/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 20:14:30 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/09 22:50:33 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main(void)
{
	int i = 0;
	std::vector<int> v; // Caso vector
	v.push_back(i++);
	v.push_back(i++);
	v.push_back(i++);
	v.push_back(i++);
	v.push_back(i++);
	try
	{
		std::vector<int>::iterator it = easyfind(v, 2);
		std::cout << "Value " << *it << " found in vector v" << std::endl; 
		std::cout << "Modifying iterator content" <<  std::endl;
		*it *= 2; 
		std::cout << "Value in iterator changed to " << *it << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in vector v" << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator first = v.begin();
		std::vector<int>::const_iterator it = easyfind(v, *first);
		std::cout << "Value " << *it << " found in vector v" << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in vector v" << std::endl;
	}
	try
	{
		std::vector<int>::const_iterator last = v.end();
		--last; // Para quedarnos con la última posición no vacía
		std::vector<int>::const_iterator it = easyfind(v, *last);
		std::cout << "Value " << *it << " found in vector v" << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in vector v" << std::endl;
	}

	std::list<int> l; // Caso list
	l.push_back(i++);
	l.push_back(i++);
	l.push_back(i++);
	l.push_back(i++);
	l.push_back(i++);
	try
	{
		std::list<int>::const_iterator it = easyfind(l, 7);
		std::cout << "Value " << *it << " found in list l" << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in list l" << std::endl;
	}

	std::deque<int> d; // Caso deque
	d.push_back(i++);
	d.push_back(i++);
	d.push_back(i++);
	d.push_back(i++);
	d.push_back(i++);
	try
	{
		std::deque<int>::const_iterator it = easyfind(d, 2);
		std::cout << "Value " << *it << " found in deque d" << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in deque d" << std::endl;
	}
	
	std::vector<int> w; // Caso límite container vacío
	try
	{
		std::vector<int>::const_iterator it = easyfind(w, 2);
		std::cout << "Value " << *it << " found in vector w" << std::endl; 
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "in vector w" << std::endl;
	}
	
	return (0);
}