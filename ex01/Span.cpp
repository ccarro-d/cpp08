/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 23:39:17 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/05 22:26:52 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : maxSize_(0) {}

Span::Span(unsigned int N) : maxSize_(static_cast<std::vector<int>::size_type>(N)) // Convertimos el tipo int en std::vector<int>::size_type
{
	numbers_.reserve(N);
}

Span::Span(const Span& other) : maxSize_(other.maxSize_), numbers_(other.numbers_) {}

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
	//return ("Number addition is impossible because the storage is full");
	return ("Insufficient storage for number addition");
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
	return ("At least two stored numbers are needed for span calculation");
}

unsigned int Span::shortestSpan() const
{
	if (numbers_.size() <= 1)
		throw SpanCalculationException();
	std::vector<int> temporary = numbers_;
	std::sort(temporary.begin(), temporary.end());
	std::vector<int>::const_iterator prev = temporary.begin();
	std::vector<int>::const_iterator next = temporary.begin();
	++next;
	unsigned int minSpan = static_cast<unsigned int>(*next) - static_cast<unsigned int>(*prev);
	++prev;
	++next;
	while (next != temporary.end())
	{
		unsigned int checkSpan = static_cast<unsigned int>(*next) - static_cast<unsigned int>(*prev);
		if (checkSpan < minSpan)
			minSpan = checkSpan;
		++prev;
		++next;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const
{
	if (numbers_.size() <= 1)
		throw Span::SpanCalculationException();
	std::vector<int>::const_iterator min = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator max = std::max_element(numbers_.begin(), numbers_.end());
	unsigned int maxSpan = static_cast<unsigned int>(*max) - static_cast<unsigned int>(*min);
	return (maxSpan);
}
