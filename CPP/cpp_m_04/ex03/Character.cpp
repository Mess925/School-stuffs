/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:29:14 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:37:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iterator>
#include <string>

Character::Character(){
	for(size_t i =0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	_name = "Unname";
	std::cout << "Character " << this->_name << " is created." <<std::endl;
}

Character::Character(const Character& other){
	this->_name = other._name;
	for(size_t i = 0; i < 4; i++){
		if(other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone(); 
		else
			this->_inventory[i] = NULL;
	}	
	std::cout << "Character " << this->_name << " is created." <<std::endl;
}

Character& Character::operator=(const Character& other){
	if( this!= &other ){
		this->_name = other._name;
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
	}}
	return *this;
}

Character::~Character(){
	for(size_t i = 0; i < 4; i++)
		delete _inventory[i];
}


Character::Character(std::string name){
	this->_name = name;
	for(size_t i =0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
	std::cout << "Character " << this->_name << " is created." <<std::endl;
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
	if(!m )
		return;
	int availableIdx = this->availableIdx();
	if(availableIdx == -1 )
		return;
	if(availableIdx >= 0 && availableIdx <= 3)
		_inventory[availableIdx] = m;
}

void Character::unequip(int idx){
	if(idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if(idx >= 0 and idx <= 3 && _inventory[idx]){
		std::cout << this->_name << " : " ;
		_inventory[idx]->use(target);
	}
}
