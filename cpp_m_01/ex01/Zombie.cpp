/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:21:54 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 04:19:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void Zombie::announce() 
{
    std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

void Zombie::setName(std::string name)
{
    this->_Name = name;
}
