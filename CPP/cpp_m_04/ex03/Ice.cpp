/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:29:46 by hthant            #+#    #+#             */
/*   Updated: 2025/10/01 20:30:05 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "Ice.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice& other) : AMateria(other){}

Ice& Ice::operator=(const Ice& other){
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice(){}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter& target){}
