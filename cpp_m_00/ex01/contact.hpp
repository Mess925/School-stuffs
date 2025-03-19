/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:46:03 by hthant            #+#    #+#             */
/*   Updated: 2025/03/19 19:21:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
private:
    std::string _FirstName;
    std::string _LastName;
    std::string _NickName;
    std::string _PhoneNumber;
    std::string _DarkestSecret;

public:
    Contact() {}

    Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
        : _FirstName(first), _LastName(last), _NickName(nick), _PhoneNumber(phone), _DarkestSecret(secret) {}

    void DisplayAll(int index) const;
    void DisplayContact() const;
};

#endif
