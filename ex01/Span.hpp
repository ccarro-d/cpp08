/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:14:43 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/05 22:26:41 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <exception>

class Span
{
	private:
		std::vector<int>::size_type maxSize_; // Es un tipo de dato entero sin signo (unsigned) que se utiliza para representar el tamaño o los índices de un std::vector<int>
		std::vector<int> numbers_;
		
	public:
		Span();
		Span(const Span& other);
		Span(unsigned int N);
		~Span();
		Span& operator=(const Span& other);
		
		void addNumber(int toAdd);
		unsigned int shortestSpan() const; // Solo debe recuperar información, no modificar el contenedor. Unsigned int porque la diferencia siempre va a ser positiva y por si nos hacen una diferencia que sea mayor que INT_MAX (ej: INT_MAX - INT_MIN)
		unsigned int longestSpan() const; // Solo debe recuperar información, no modificar el contenedor. Unsigned int porque la diferencia siempre va a ser positiva y por si nos hacen una diferencia que sea mayor que INT_MAX (ej: INT_MAX - INT_MIN)
		template <typename Iterator> // Porque podemos recibir un iterator de cualquier tipo de container
		void addRange(Iterator first, Iterator last);
		
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

#include "Span.tpp"

#endif