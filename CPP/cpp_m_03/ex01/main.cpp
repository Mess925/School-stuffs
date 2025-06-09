/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:48:49 by hthant            #+#    #+#             */
/*   Updated: 2025/06/08 20:58:25 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
# include "ScavTrap.hpp"

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
    copy.takeDamage(10);
    copy.beRepaired(10);
    std::cout <<std::endl <<"__________________________END OF CLAPTRAP TEST_______________"<<std::endl << std::endl;





    std::cout <<std::endl <<"_______________Creating Original ScavTrap___________________" << std::endl;
    ScavTrap soriginal ("A");
    
    std::cout <<std::endl <<"_________________Creating Copy Scavtrap_____________________" << std::endl;
    ScavTrap scopy = soriginal;
    
    std::cout <<std::endl <<"______________Assgning the original Scavtrap________________" <<std::endl;
    soriginal.attack("B");
    soriginal.takeDamage(5);
    soriginal.beRepaired(1);

    std::cout <<std::endl <<"______________________ENERGY POINT TEST______________________" <<std::endl;
    ScavTrap s ("C");
    for (int i = 0; i < 55; i++)
    {
        s.attack("B");
    }
    s.guardGate();
    
    std::cout <<std::endl <<"______________________REPARE AND DIE TEST____________________" <<std::endl;
    scopy.takeDamage(90);
    scopy.beRepaired(5);
    scopy.takeDamage(5);
    scopy.beRepaired(5);
    scopy.takeDamage(15);
    scopy.beRepaired(10);
    std::cout <<std::endl <<"__________________________END OF SCAVTRAP TEST_______________"<<std::endl;
}