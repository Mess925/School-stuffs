/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:23:26 by hthant            #+#    #+#             */
/*   Updated: 2025/03/20 15:53:46 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

bool PhoneBook::IsValidPhoneNumber(const std::string &phoneNumber) const
{
    if (phoneNumber.empty())
        return false;

    bool hasPlus = false;
    bool openParen = false;
    size_t digitCount = 0;

    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        char c = phoneNumber[i];
        switch (c)
        {
            case '+':
                if (hasPlus || i != 0) return false;
                hasPlus = true;
                break;
            case '(':
                if (openParen || (i > 0 && !std::isspace(phoneNumber[i - 1]) && !std::ispunct(phoneNumber[i - 1])))
                    return false;
                openParen = true;
                break;
            case ')':
                if (!openParen || (i > 0 && !std::isdigit(phoneNumber[i - 1])))
                    return false;
                openParen = false;
                break;
            case '-':
            case ' ':
                if (i == 0 || i == phoneNumber.length() - 1 || !std::isdigit(phoneNumber[i - 1]))
                    return false;
                break;
            default:
                if (std::isdigit(c))
                    digitCount++;
                else
                    return false;
                break;
        }
    }
    return (digitCount >= 7 && digitCount <= 15);
}


void PhoneBook::ContactSearch() const
{
    int index;
    std::string input;

    if ((_ContactCount) == 0)
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
    for (int i = 0; i < _ContactCount; i++)
        contacts[i].DisplayAll(i + 1);

    std::cout << "Enter contact index: ";
    if (!getline(std::cin, input))
        exit(1);
    std::stringstream ss(input);
    if (!(ss >> index))
    {
        std::cout << "Invalid input. Please enter a valid number.\n";
        return;
    }
    if (index >= 1 && index <= _ContactCount)
        contacts[index - 1].DisplayContact();
    else
        std::cout << "Invalid index. Please enter a valid contact number.\n";
}

void CheckError(std::string &str, const std::string &Input)
{
    if (!getline(std::cin, str))
        exit(1);
    while (str.empty())
    {
        std::cout << Input << " cannot be empty. Please enter again: ";
        if (!getline(std::cin, str))
            exit(1);
    }
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

    int newIndex = _ContactIndex % MAX_CONTACTS;
    contacts[newIndex] = Contact(FirstName, LastName, NickName, PhoneNumber, DarkestSecret);

    newIndex = (newIndex + 1);
    if (_ContactCount < MAX_CONTACTS)
        _ContactCount++;

    std::cout << "Contact added successfully!" << std::endl;
}

