/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:57:27 by hthant            #+#    #+#             */
/*   Updated: 2025/10/30 15:50:48 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <string>

class bigint {

	private:
		std::string _value;
	public:
		bigint();
		bigint(const bigint& other);
		bigint& operator= (const bigint &other);
		~bigint();

		bigint(unsigned int number);
		bigint(std::string value);

		std::string getValue() const;
		bigint operator+(const bigint& number);
		bigint& operator+=(const bigint& number);
		bigint& operator++();
		bigint operator++(int i);
};

std::ostream& operator<<(std::ostream& os, const bigint& b);

# endif
