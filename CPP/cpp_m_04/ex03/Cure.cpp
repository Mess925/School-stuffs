/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:02:34 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:52:26 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("cure"){}

Cure::Cure(const Cure& other) : AMateria(other){}

Cure& Cure::operator=(const Cure& other){
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure(){}

AMateria* Cure:: clone() const{
	std::cout << "Creating clone of cure " << this << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

