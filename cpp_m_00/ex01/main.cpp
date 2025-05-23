/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:20:24 by hthant            #+#    #+#             */
/*   Updated: 2025/05/23 16:23:19 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	std::string Command;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Please Enter A Command (ADD / SEARCH / EXIT): ";
		if (!getline(std::cin, Command))
			return (1);
		if (Command == "ADD")
			phoneBook.ContentInit();
		else if (Command == "SEARCH")
			phoneBook.ContactSearch();
		else if (Command == "EXIT")
		{
			std::cout << "Exiting The PhoneBook......\n";
			break;
		}
		else
			std::cout << "Invalid command. Use ADD, SEARCH, or EXIT.\n";
	}
	return (0);
}
