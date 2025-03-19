/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:46:39 by hthant            #+#    #+#             */
/*   Updated: 2025/03/19 17:24:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::DisplayContact() const
{
	std::cout << "First Name: " << _FirstName << std::endl;
	std::cout << "Last Name: " << _LastName << std::endl;
	std::cout << "Nick Name: " << _NickName << std::endl;
	std::cout << "Phone Number: " << _PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _DarkestSecret << std::endl;
}

void Contact::DisplayAll(int index) const
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << (_FirstName.length() > 10 ? _FirstName.substr(0, 9) + "." : _FirstName) << "|"
			  << std::setw(10) << (_LastName.length() > 10 ? _LastName.substr(0, 9) + "." : _LastName) << "|"
			  << std::setw(10) << (_NickName.length() > 10 ? _NickName.substr(0, 9) + "." : _NickName) << "|" << std:: endl;
}

