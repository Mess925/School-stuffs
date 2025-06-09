/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:54:10 by hthant            #+#    #+#             */
/*   Updated: 2025/05/27 20:13:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <stdlib.h>
# include <sstream>

# define MAX_CONTACTS 8

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS];
    int _contactIndex;
    int _contactCount;
    
public:
    PhoneBook(){
        _contactCount = 0;
        _contactIndex = 0;
    }
    bool IsValidPhoneNumber(const std::string &phoneNumber) const;
    void ContactSearch() const;
    void ContentInit();
};


# endif