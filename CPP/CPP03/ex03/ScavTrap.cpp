/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:24:02 by hthant            #+#    #+#             */
/*   Updated: 2025/06/11 00:40:46 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed") {
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default " << this->_name <<" is called." <<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout<< "ScavTrap " << this->_name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScaveTrap copy " << other._name << " is created" << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    if(this != &other)
    ClapTrap::operator=(other);
    {
    }   
    std::cout<<"ScaveTrap " << other._name << " is asigned."<<std::endl;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout<<"ScaveTrap "<<this->_name << " is destroyed." <<std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hitPoint <= 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and can't attack!" << std::endl;
        return;
    }

    if (this->_energyPoint <= 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy to attack!" << std::endl;
        return;
    }

    this->_energyPoint--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target
              << ", dealing " << this->_attackDamage << " damage!" << std::endl;
}


void ScavTrap::guardGate(){
    std::cout << "ScaveTrap " <<this->_name << " is now in Gate keeper Mood."<< std::endl;
}