/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:36:00 by hthant            #+#    #+#             */
/*   Updated: 2025/10/13 11:56:52 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BIGINT_HPP
# define BIGINT_HPP
 
# include <iostream>
# include <wait.h>

class bigint{
	private: 
		std::string _value;
	public:
		bigint();
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		bigint(unsigned int n);
		bigint(std::string value);
		std::string getValue() const;
		std::string toStr(unsigned int n);
		bigint operator+(const bigint& number);
		bigint operator+=(const bigint& number);
		bigint operator++();
		bigint operator++(int);
		bigint operator<<(int n);
		bigint operator>>(int n);
		bigint& operator<<=(int n);
};

std::ostream& operator<<(std::ostream& os, const bigint& b);


# endif 
