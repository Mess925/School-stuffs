/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:51:00 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 15:39:42 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

const std::string& Weapon::getType() {
    return (_type);
}

void Weapon::setType(std::string type) {
    this->_type = type;
}