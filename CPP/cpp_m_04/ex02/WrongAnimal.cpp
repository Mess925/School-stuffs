/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:35:08 by hthant            #+#    #+#             */
/*   Updated: 2025/06/09 19:35:45 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAniaml.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal"){
    std::cout << "WrongAnimal Default Constructor is created." <<std::endl;
}

WrongAnimal:: WrongAnimal(const WrongAnimal& other):type(other.type){
    std::cout<<"Wrong Animal Copy Constructor " << other.type << " is created." << std::endl;
} 

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if(this!= &other){
        this->type = other.type;
    }
    std::cout << "Wrong Animal is assigned." << std::endl;
    return *this;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type){
    std::cout<<"Wrong Animal Para Constructor "<<this->type << "is created."<<std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong Animal is making a sound."<<std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

WrongAnimal::~WrongAnimal(){
    std::cout <<"Wrong Animal Destructor is called."<<std::endl;
}