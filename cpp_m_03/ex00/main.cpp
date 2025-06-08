/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:48:49 by hthant            #+#    #+#             */
/*   Updated: 2025/06/08 16:33:27 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout <<std::endl <<"_______________Creating Original ClapTrap___________________" << std::endl;
    ClapTrap original ("A");
    
    std::cout <<std::endl <<"_________________Creating Copy Claptrap_____________________" << std::endl;
    ClapTrap copy = original;
    
    std::cout <<std::endl <<"______________Assgning the original Claptrap________________" <<std::endl;
    original.attack("B");
    original.takeDamage(5);
    original.beRepaired(1);

    std::cout <<std::endl <<"______________________ENERGY POINT TEST______________________" <<std::endl;
    ClapTrap c ("C");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    c.attack("B");
    
    std::cout <<std::endl <<"______________________REPARE AND DIE TEST____________________" <<std::endl;
    copy.takeDamage(9);
    copy.beRepaired(5);
    copy.takeDamage(5);
    copy.beRepaired(5);
    copy.takeDamage(6);
    copy.beRepaired(10);
    std::cout <<std::endl <<"__________________________END OF TEST_________________________"<<std::endl;

}