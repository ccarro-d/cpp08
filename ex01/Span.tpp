/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarro-d <ccarro-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 19:54:54 by ccarro-d          #+#    #+#             */
/*   Updated: 2026/10/05 21:16:07 by ccarro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void Span::addRange(Iterator first, Iterator last) // Asumimos que first y last son válidos
{
	typename std::iterator_traits<Iterator>::difference_type distance = std::distance(first, last);
	std::vector<int>::size_type rangeSize = static_cast<std::vector<int>::size_type>(distance);
	if (maxSize_ - numbers_.size() < rangeSize)
		throw SpanCapacityException();
	numbers_.insert(numbers_.end(), first, last);
}