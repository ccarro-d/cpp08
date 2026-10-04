/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:14:43 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/04 23:56:28 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int maxSize_;
		std::vector<int> numbers_;
		
	public:
		Span();
		Span(const Span& other);
		Span(unsigned int N);
		~Span();
		Span& operator=(const Span& other);
		
		void addNumber(int toAdd);
		int shortestSpan() const; // Solo debe recuperar información, no modificar el contenedor
		int longestSpan() const; // Solo debe recuperar información, no modificar el contenedor
		
		class SpanCapacityException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class SpanCalculationException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif