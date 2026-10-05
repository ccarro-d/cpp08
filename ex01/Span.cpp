/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:39:17 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/05 00:26:59 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

Span::Span() : maxSize_(0) {}

Span::Span(unsigned int N) : maxSize_(N)
{
	numbers_.reserve(N);
}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize_ = other.maxSize_;
		numbers_ = other.numbers_;
	}
	return (*this);
}

Span::~Span() {}

const char *Span::SpanCapacityException::what() const throw()
{
	return ("Number addition is impossible because the storage is full");
}

void Span::addNumber(int toAdd)
{
	if (numbers_.size() < maxSize_)
		numbers_.push_back(toAdd);
	else
		throw Span::SpanCapacityException();
}

const char *Span::SpanCalculationException::what() const throw()
{
	return ("At least two stores numbers are needed for span calculation");
}

int Span::shortestSpan() const
{
	if (numbers_.size() <= 1)
		throw SpanCalculationException();
	std::vector<int> temporary = numbers_;
	std::sort(temporary.begin(), temporary.end());
	std::vector<int>::const_iterator prev = temporary.begin();
	std::vector<int>::const_iterator next = temporary.begin();
	++next;
	int minSpan = *next - *prev;
	++prev;
	++next;
	while (next != temporary.end())
	{
		int checkSpan = *next - *prev;
		if (checkSpan < minSpan)
			minSpan = checkSpan;
		++prev;
		++next;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (numbers_.size() <= 1)
		throw Span::SpanCalculationException();
	std::vector<int>::const_iterator min = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator max = std::max_element(numbers_.begin(), numbers_.end());
	return (*max - *min);
}

void Span::addRandomNumbersToRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	srand(time(NULL));
	while (first != last && first != numbers_.end())
}