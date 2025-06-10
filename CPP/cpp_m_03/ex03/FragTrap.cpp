/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:53:34 by hthant            #+#    #+#             */
/*   Updated: 2025/06/08 21:04:12 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed") {
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default" << this->_name <<" is called." <<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout<< "FragTrap " << this->_name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy " << other._name << " is created" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if(this != &other)
    ClapTrap::operator=(other);
    {
    }   
    std::cout<<"FragTrap " << other._name << " is asigned."<<std::endl;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout<<"FragTrap "<<this->_name << " is destroyed." <<std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->_hitPoint <= 0) {
        std::cout << "FragTrap " << this->_name << " is dead and can't attack!" << std::endl;
        return;
    }

    if (this->_energyPoint <= 0) {
        std::cout << "FragTrap " << this->_name << " has no energy to attack!" << std::endl;
        return;
    }

    this->_energyPoint--;
    std::cout << "FragTrap " << this->_name << " attacks " << target
              << ", dealing " << this->_attackDamage << " damage!" << std::endl;
}


void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->_name << " requested a high five." << std::endl;
}