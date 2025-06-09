/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:55:43 by hthant            #+#    #+#             */
/*   Updated: 2025/06/09 19:26:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout<<"Animal Default Constructor " << type << " is created."<< std::endl;
}

Animal::Animal(const std::string type):type(type){
    std::cout <<"Animal Para Constructor "<<type << " is created."<<std::endl;
}

Animal::Animal(const Animal& other): type(other.type){
    std::cout<<"Aniaml Copy Constructor " << other.type<< " is created."<<std::endl;
}

Animal& Animal::operator=(const Animal& other){
    if(this != &other){
        this->type = other.type;
    }
    std::cout << "Animal is assigned." << std::endl;
    return *this;
}

void Animal::makeSound() const {
    std::cout<<"Animal is making a sound."<<std::endl;
}

std::string Animal::getType() const{
    return this->type;
}

Animal::~Animal(){
    std::cout<<"Animal Destructor is called."<<std::endl;
}