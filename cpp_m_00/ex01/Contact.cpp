/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:14:16 by hthant            #+#    #+#             */
/*   Updated: 2025/05/27 17:14:29 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

void Contact::DisplayAll() const 
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nick Name: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void Contact::DisplaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << (_firstName.length() > 10 ? _firstName.substr(0, 9) + "." : _firstName) << "|"
			  << std::setw(10) << (_lastName.length() > 10 ? _lastName.substr(0, 9) + "." : _lastName) << "|"
			  << std::setw(10) << (_nickName.length() > 10 ? _nickName.substr(0, 9) + "." : _nickName) << "|" << std:: endl;
}