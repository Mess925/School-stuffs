/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:51:05 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 15:34:57 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
    std::string _type;
public:
    Weapon(std::string type);
    const std::string& getType();
    void setType(std::string type);
};

Weapon::Weapon(std::string type)
{
    _type = type;
}
# endif