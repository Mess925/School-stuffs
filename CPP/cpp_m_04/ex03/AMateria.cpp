/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:12:40 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:19:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria():_type("Unknown"){}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria& AMateria::operator=(const AMateria& other){
	(void) other;
	return *this;
}

AMateria::AMateria(std::string const& type):_type(type){}

std::string const& AMateria::getType() const{
	std::cout << this->_type<< " is the type" << std::endl ;
	return  this->_type;
}

AMateria::~AMateria(){}

void AMateria::use(ICharacter& target){
	(void) target;
}
