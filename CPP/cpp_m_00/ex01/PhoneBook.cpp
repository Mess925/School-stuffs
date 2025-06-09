/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:14:42 by hthant            #+#    #+#             */
/*   Updated: 2025/05/28 14:50:03 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool PhoneBook::IsValidPhoneNumber(const std::string &phoneNumber) const {
    for (size_t i = 0; i < phoneNumber.length(); i++) {
        if (!isdigit(phoneNumber[i])) {
            return (false);
        }
    }
    return (!phoneNumber.empty());
}

void PhoneBook::ContactSearch() const
{
    int index;
    std::string input;

    if ((_contactCount) == 0)
    {
        std::cout << "No contacts to search.\n";
        return;
    }
    else
    {
        std::cout << std::setw(10) << "Index" << "|"
        << std::setw(10) << "FirstName" << "|"
        << std::setw(10) << "LastName" << "|"
        << std::setw(10) << "Nickname" << "|" << std:: endl;
    }
    for (int i = 0; i < _contactCount; i++)
        contacts[i].DisplaySummary(i + 1);

    do{
        std::cout << "Enter contact index: ";
        if (!getline(std::cin, input))
            exit(1);
        std::stringstream ss(input);
        if (!(ss >> index))
            std::cout << "Invalid input. Please enter a valid number.\n";
        if (index >= 1 && index <= _contactCount)
            contacts[index - 1].DisplayAll();
        else
           std::cout << "Invalid index. Please enter a valid contact number.\n";   
    }while (index < 1 || index > _contactCount);
}

void CheckError(std::string &str, const std::string &Input)
{
    do {
        if (!getline(std::cin, str))
            exit(1);
        if (str.empty())
            std::cout << Input << " Cannot be empty. Please enter again: ";
    } while (str.empty());
}

void PhoneBook::ContentInit()
{
    std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;

    std::cout << "Enter First Name: ";
    CheckError(FirstName, "First Name");
    std::cout << "Enter Last Name: ";
    CheckError(LastName, "Last Name");
    std::cout << "Enter Nick Name: ";
    CheckError(NickName, "Nick Name");
    std::cout << "Enter Phone Number: ";
    if (!getline(std::cin, PhoneNumber))
        exit(1);
    while (PhoneNumber.empty() || !IsValidPhoneNumber(PhoneNumber))
    {
        std::cout << "Invalid phone number! Please enter only digits: ";
        if (!getline(std::cin, PhoneNumber))
            exit(1);
    }
    std::cout << "Enter Darkest Secret: ";
    CheckError(DarkestSecret, "Darkest Secret");

    int newIndex = _contactIndex % MAX_CONTACTS;
    contacts[newIndex] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);

    _contactIndex++;
    if (_contactCount < MAX_CONTACTS)
        _contactCount++;

    std::cout << "Contact added successfully!" << std::endl;
}
