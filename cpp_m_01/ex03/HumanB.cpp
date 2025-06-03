/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:39:54 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 15:06:11 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : _Name(name) , weapon(NULL){}

void HumanB::attack() {
    if (weapon)
        std::cout << _Name << " attacks with their " << weapon->getType() << std::endl;
    else
    {
        std::cout << _Name << " has no weapon to attack with" << std::endl;
        return;
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}