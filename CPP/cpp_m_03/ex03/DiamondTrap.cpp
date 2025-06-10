/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:33:48 by hthant            #+#    #+#             */
/*   Updated: 2025/06/11 00:41:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " created (default)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name) {
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->_name << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}
