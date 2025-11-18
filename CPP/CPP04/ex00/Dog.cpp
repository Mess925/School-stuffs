/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:55:58 by hthant            #+#    #+#             */
/*   Updated: 2025/06/09 18:17:13 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout<<"Dog Default Constructor is created." <<std::endl;
}

Dog::Dog(const std::string type): Animal(type){
    this->type = type;
    std::cout<<"Dog Para Constructor "<< this->type << " is created."<< std::endl;
}

Dog::Dog(const Dog& other): Animal(other){
    this->type = other.type;
    std::cout<<"Dog Copy Constructor "<< other.type << " is created."<< std::endl;
}

Dog&::Dog::operator=(const Dog& other){
    if(this != &other){
        Animal::operator=(other);
    }
    std::cout<<"Dog "<< other.type << " is assigned." << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout<<"Dog Destructor is called." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "woof! woof!" << std::endl;
}