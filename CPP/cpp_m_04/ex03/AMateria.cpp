/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:12:40 by hthant            #+#    #+#             */
/*   Updated: 2025/10/01 19:58:13 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria():_type("Unknown"){}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria& AMateria::operator=(const AMateria& other){
	(void) other;
	std::cout << "C A OP " << std::endl;
	return *this;
}

AMateria::AMateria(std::string const& type):_type(type){}

std::string const& AMateria::getType() const{
	return this->_type;
}

