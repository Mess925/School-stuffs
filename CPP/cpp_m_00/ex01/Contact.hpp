/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:14:22 by hthant            #+#    #+#             */
/*   Updated: 2025/05/27 19:58:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
private:
    
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact() {}

    Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret) {
        _firstName = first;
        _lastName = last;
        _nickName = nick;
        _phoneNumber = phone;
        _darkestSecret = secret;
    }
    void DisplaySummary(int index) const;
    void DisplayAll() const;
};

# endif