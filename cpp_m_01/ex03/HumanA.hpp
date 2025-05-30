/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:40:00 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 19:59:29 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
    Weapon& weapon;
    std::string _Name;
public:
    HumanA(std::string name, Weapon& weapon)
    : weapon(weapon), _Name(name) {}
    void attack();
};

# endif