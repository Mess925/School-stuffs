/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 09:48:49 by hthant            #+#    #+#             */
/*   Updated: 2025/06/11 00:46:58 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap dt("Shiny");

    std::cout << "\n=== Using attack() ===" << std::endl;
    dt.attack("target_dummy");
    dt.takeDamage(10);
    dt.beRepaired(10);

    std::cout << "\n=== Who am I? ===" << std::endl;
    dt.whoAmI();

    std::cout << "\n=== Test complete ===" << std::endl;
    return 0;
}

