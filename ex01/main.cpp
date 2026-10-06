/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:13:49 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/06 21:00:56 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib> // Random
#include <ctime> // Time
#include <algorithm>
#include <climits> // UINT_MAX

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp shortestSpan:  " << sp.shortestSpan() << std::endl;
	std::cout << "sp longestSpan:  " << sp.longestSpan() << std::endl << std::endl;

	int j = 0;
	std::vector<int> range;
	range.push_back(j++);
	range.push_back(j++);
	range.push_back(j++);
	range.push_back(j++);
	range.push_back(j++);
	Span spa = Span(5);
	spa.addRange(range.begin(), range.end());
	std::cout << "spa shortestSpan:  " << spa.shortestSpan() << std::endl;
	std::cout << "spa longestSpan:  " << spa.longestSpan() << std::endl << std::endl;

	Span limits = Span(2);
	limits.addNumber(INT_MIN);
	limits.addNumber(INT_MAX);
	std::cout << "limits shortestSpan:  " << limits.shortestSpan() << std::endl;
	std::cout << "limits longestSpan:  " << limits.longestSpan() << std::endl;
	try
	{
		limits.addNumber(2);
		std::cout << "Extra number added" << std::endl << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	

	Span empty;
	try
	{
		std::cout << "empty shortestSpan: " << empty.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "empty longestSpan: " << empty.longestSpan() << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl << std::endl;
	
	int	span_size = 10001;
	if (span_size < 2)
		return (0);
	Span rdom(span_size);
	std::vector<int> checker;
	checker.reserve(span_size);
	unsigned int shortestSpan = -1; // Para unsigned int -1 equivale a UINT_MAX, que es = INT_MAX - INT_MIN;
	int shortestSpanMembers[2];
	srand(time(NULL));
	for (int i = 0; i < span_size; i++)
	{
		if (i == 0)
			std::cout << "rdom vector content: ";
		int randomized = rand();
		rdom.addNumber(randomized);
		std::cout << randomized;
		if (i != span_size - 1)
			std::cout << ", "; 
		else
			std::cout << std::endl << std::endl << std::endl;
		checker.push_back(randomized);
	}
	std::sort(checker.begin(), checker.end());
	std::vector<int>::const_iterator first = checker.begin();
	std::vector<int>::const_iterator last = checker.end() - 1;
	std::vector<int>::const_iterator it = first;
	std::vector<int>::const_iterator prev = it;
	while (it != checker.end())
	{
		if (it == checker.begin())
			std::cout << "rdom vector content sorted: ";
		else
		{
			unsigned int diff = static_cast<unsigned int>(*it) - static_cast<unsigned int>(*prev);
			if (diff < shortestSpan)
			{
				shortestSpan = diff;
				shortestSpanMembers[0] = *prev;
				shortestSpanMembers[1] = *it;
			}
			++prev;
		}
		if (it != last)
			std::cout << *it << ", "; 
		else
			std::cout << *it << std::endl << std::endl << std::endl;
		++it;
	}
	
	std::cout << "rdom min member: " << *first << std::endl;
	std::cout << "rdom shortestSpan: " << rdom.shortestSpan() << std::endl;
	std::cout << "rdom shortestSpanMembers: " << shortestSpanMembers[0] << " & " << shortestSpanMembers[1] << std::endl;
	std::cout << "rdom max member: " << *last << std::endl;
	std::cout << "rdom longestSpan: " << rdom.longestSpan() << std::endl;
	
	return (0);
}
