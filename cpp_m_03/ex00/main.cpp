/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:48:49 by hthant            #+#    #+#             */
/*   Updated: 2025/06/07 10:54:41 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "=== Creating Original ClapTrap ===" << std::endl;
    ClapTrap original("OG");

    std::cout << "\n=== Copying ClapTrap ===" << std::endl;
    ClapTrap copy = original; // Calls copy constructor

    std::cout << "\n=== Modifying Original, Not Copy ===" << std::endl;
    original.attack("Dummy");
    original.takeDamage(4);
    original.beRepaired(6); // Should max at 10 HP

    std::cout << "\n=== Check Copy Hasn't Changed ===" << std::endl;
    copy.attack("Still Dummy");

    std::cout << "\n=== Repair Beyond Max Test ===" << std::endl;
    ClapTrap healer("Medic");
    healer.takeDamage(5); // down to 5 HP
    healer.beRepaired(10); // should go to max 10 HP, not 15

    std::cout << "\n=== Before/After HP & Energy Test ===" << std::endl;
    ClapTrap stat("Stats");
    stat.takeDamage(3); // 7 HP
    stat.beRepaired(2); // 9 HP
    stat.attack("Target1"); // -1 energy
    stat.beRepaired(3); // 10 HP capped

    std::cout << "\n=== Repair Beyond Max Test ===" << std::endl;
    ClapTrap ko("Die");
    ko.takeDamage(100); // 

    std::cout << "\n=== End of Test ===" << std::endl;
    return 0;
}