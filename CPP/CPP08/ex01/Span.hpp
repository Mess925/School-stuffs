/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:33:28 by hthant            #+#    #+#             */
/*   Updated: 2025/09/11 17:41:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>

class Span {
	private:
		unsigned int _maxN;
		std::vector<int> _nums;
	public:
		Span();
		Span(int n);
		Span(unsigned int maxN);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		unsigned int shortestSpan() ;
		unsigned int longestSpan() ;
		std::vector<int>& getarray ();
		void addNumber(std::vector<int>& vec);
};

# endif
