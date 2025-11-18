/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:54:42 by hthant            #+#    #+#             */
/*   Updated: 2025/10/03 20:34:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <cstddef>

MateriaSource::MateriaSource(){
	for(size_t i =0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for(size_t i =0 ;i < 4; i++){
		if(other._templates[i])
			this->_templates[i] = other._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){

	if(this != &other){
	for(size_t i = 0; i < 4; i++){
		if(this->_templates[i]){
			delete this->_templates[i];
			this->_templates[i] = NULL;
		}
	}
	for(size_t i =0; i < 4; i++){
		if(other._templates[i]){
			this->_templates[i] = other._templates[i]->clone();
		}
		else {
			this->_templates[i] = NULL;
		}
	}}
	return *this;
}

MateriaSource::~MateriaSource(){
	for(size_t i =0; i < 4; i++)
		delete _templates[i];
}

void MateriaSource::learnMateria(AMateria* m){
	if(!m )
		return;
	for(size_t i = 0; i < 4; i++){
		if(_templates[i] == NULL){
			this->_templates[i] = m;
			return;
		}
	}

}

AMateria* MateriaSource::createMateria(std::string const & type){
	for(size_t i = 0; i < 4; i++){
		if(this->_templates[i]){
			if(this->_templates[i]->getType() ==  type){
				AMateria* newMateria = this->_templates[i]->clone();
				return  newMateria;
			}
		}
	}
	return (0);
}

/*
AMateria* MateriaSource::createMateria(std::string const & type){
	for(size_t i = 0; i < 4; i++){
		if(this->_templates[i] && this->_templates[i]->getType() == type)
	
		{
			AMateria* newMateria = this->_templates[i]->clone();
			std::cout << newMateria << std::endl;
			return newMateria;
		}
	}
	return (0);
} */
