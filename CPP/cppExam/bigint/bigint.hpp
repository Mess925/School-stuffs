/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:59:59 by hthant            #+#    #+#             */
/*   Updated: 2025/10/19 17:21:17 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BIGINT_HPP
# define BIGINT_HPP

# include <ostream>
# include <iostream>
# include <string>

class bigint {
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
		bigint operator+(const bigint& b);
		bigint operator*(const bigint& n);
};

std::ostream& operator<<(std::ostream& os, const bigint b);

# endif
