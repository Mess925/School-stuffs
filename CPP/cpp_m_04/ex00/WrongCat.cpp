/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:38:48 by hthant            #+#    #+#             */
/*   Updated: 2025/06/09 19:39:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout<<"WrongCat Default Constructor is created." <<std::endl;
}

WrongCat::WrongCat(const std::string type): WrongAnimal(type){
    this->type = type;
    std::cout<<"WrongCat Para Constructor "<< this->type << " is created."<< std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
    this->type = other.type;
    std::cout<<"WrongCat Copy Constructor "<< other.type << " is created."<< std::endl;
}

WrongCat&::WrongCat::operator=(const WrongCat& other){
    if(this != &other){
        WrongAnimal::operator=(other);
    }
    std::cout<<"WrongCat "<< other.type << " is assigned." << std::endl;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout<<"WrongCat Destructor is called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "blah! blah!" << std::endl;
}