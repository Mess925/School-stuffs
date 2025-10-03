/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:02:34 by hthant            #+#    #+#             */
/*   Updated: 2025/10/02 12:35:54 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("cure"){}

Cure::Cure(const Cure& other){
	*this = other;
}

Cure& Cure::operator=(const Cure& other){
	(void) other;
	return *this;
}

Cure::~Cure(){}

AMateria* Cure:: clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

