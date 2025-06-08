/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:52:52 by hthant            #+#    #+#             */
/*   Updated: 2025/06/08 16:27:34 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("UNnamed"), _hitPoint(10), _energyPoint(10), _attackDamage(0){
    std::cout<<"Default ClapTrap " <<_name << "is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(10){
    std::cout<<"ClapTrap " <<_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoint(other._hitPoint), _energyPoint(other._energyPoint) , _attackDamage(other._attackDamage){
    std::cout<<"ClapTrap " << _name<< "(coppied) is created." <<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if(this != &other)
    {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    std::cout<< "ClapTrap " << this->_name << " is assigned"<<std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout<< "ClapTrap " << this->_name <<" is destroyed"<<std::endl;
}

void ClapTrap::attack(const std::string& target){
    if(this->_hitPoint < 1){
        std::cout<< "ClapTrap " << this->_name << "is not alive."<< std::endl;
        return;    
    }
    if(this->_energyPoint < 1){
        std::cout<< "ClapTrap " <<this->_name<<" does not have enought [Energy Point] to attack."<<std::endl;
        return;
    }
    std::cout<<"ClapTrap "<<this->_name<<" attacks " <<target<<", causing "<<this->_attackDamage<<" points of damage!"<<std::endl;
    this->_energyPoint -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(this->_hitPoint < 1){
        std::cout<< "ClapTrap " << this->_name << " is not alive and cannot be attacked."<< std::endl;
        return;    
    }
    int oldhitpoint = this->_hitPoint;
    this->_hitPoint -= (int)amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    std::cout<< "ClapTrap "<<this->_name<< "'s hit point before: " << oldhitpoint << " HP." << std::endl;
    std::cout<<"ClapTrap " <<this->_name<< "'s hit point after Damage: " << this->_hitPoint << " HP." << std::endl;
    if(this->_hitPoint <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
        this->_hitPoint = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_hitPoint < 1) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired." << std::endl;
        return ;
    }
    if (this->_energyPoint < 1) {
        std::cout << "ClapTrap " << this->_name << " does not have enough energy pint to be repaired." << std::endl;
        return ;
    }
    int oldHP = this->_hitPoint;
    this->_hitPoint += (int)amount;
    if (this->_hitPoint > 10)
    {
        std::cout << "ClapTrap " << this->_name << " has reached the hit point limit." << std::endl;
        this->_hitPoint = 10;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired: " << oldHP << " -> " << this->_hitPoint << " HP." << std::endl;
    this->_energyPoint -= 1;
}

