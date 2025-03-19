/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:23:26 by hthant            #+#    #+#             */
/*   Updated: 2025/03/19 18:15:48 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "phonebook.hpp"

void PhoneBook::ContactSearch() const
{
    int index;
    std::string input;

    if (getContactCount() == 0) {
        std::cout << "No contacts to search.\n";
        return;
    }
    for (int i = 0; i < getContactCount(); i++)
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
    if (index >= 1 && index <= getContactCount())
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
    CheckError(PhoneNumber, "Phone Number");
    std::cout << "Enter Darkest Secret: ";
    CheckError(DarkestSecret, "Darkest Secret");

    int newIndex = getContactIndex() >= MAX_CONTACTS ? getContactIndex() % MAX_CONTACTS : getContactIndex();
    setContactIndex(newIndex + 1);

    if (getContactCount() < MAX_CONTACTS)
        setContactCount(getContactCount() + 1);

    std::cout << "Contact added successfully!" << std::endl;
}
