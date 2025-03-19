/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:47:46 by hthant            #+#    #+#             */
/*   Updated: 2025/03/19 19:47:13 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <sstream>
#include <cstdlib>
#define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int _ContactIndex;
    int _ContactCount;

    
    public:
    PhoneBook() : _ContactIndex(0), _ContactCount(0) {}
    
    // Getter methods
    int getContactIndex() const { return _ContactIndex; }
    int getContactCount() const { return _ContactCount; }
    
    // Setter methods
    void setContactIndex(int index) { _ContactIndex = index; }
    void setContactCount(int count) { _ContactCount = count; }
    
    bool IsValidPhoneNumber(const std::string &phoneNumber) const;
    void ContactSearch() const;
    void ContentInit();
};

#endif
