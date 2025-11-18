/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:55:48 by hthant            #+#    #+#             */
/*   Updated: 2025/06/22 11:55:45 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    this->brain = new Brain();
    std::cout<<"Cat Default Constructor is created." <<std::endl;
}

Cat::Cat(const std::string type): Animal(type){
    this->type = type;
    this->brain = new Brain();
    std::cout<<"Cat Para Constructor "<< this->type << " is created."<< std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    std::cout<<"Cat Copy Constructor "<< other.type << " is created."<< std::endl;
}

Cat& Cat::operator=(const Cat& other){
    if(this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout<<"Cat "<< other.type << " is assigned." << std::endl;
    return *this;
}

Cat::~Cat(){
    delete this->brain;
    std::cout<<"Cat Destructor is called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "meow! meow!" << std::endl;
}

Brain* Cat::getBrain() const{
    return (brain);
}
