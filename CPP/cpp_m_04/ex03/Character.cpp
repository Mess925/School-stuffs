/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:29:14 by hthant            #+#    #+#             */
/*   Updated: 2025/10/02 13:58:31 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

Character::Character(){
	for(size_t i =0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	_name = "Unname";
}

Character::Character(const Character& other){
	this->_name = other._name;
	for(size_t i = 0; i < 4; i++){
		if(other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone(); 
		else
			this->_inventory[i] = NULL;
	}	
}

Character& Character::operator=(const Character& other){
	if( this!= &other ){
		this->_name = other._name;
	}

	for(size_t i = 0; i < 4;i++){
		if(this->_inventory[i]){
			delete this->_inventory[i]; 
			this->_inventory[i] = NULL;
		}
	}
	for(size_t i = 0; i < 4; i++){
		if(other._inventory[i]){
			this->_inventory[i] = other._inventory[i]->clone();
		}
		else {
			this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character(){}

Character::Character(std::string name){
	this->_name = name;
	for(size_t i =0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

std::string const& Character:: getName() const{
	return this->_name;
}

int Character::availableIdx(void){
	for(size_t i =0; i < 4; i++){
		if(this->_inventory[i] == NULL)
			return i;
	}
	return (-1) ;
}

void Character::equip(AMateria* m){

}

void Character::unequip(int idx){

}

void Character::use(int idx, ICharacter& target){

}
