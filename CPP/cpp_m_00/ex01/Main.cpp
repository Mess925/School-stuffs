/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:39:21 by hthant            #+#    #+#             */
/*   Updated: 2025/05/27 19:58:29 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <string.h>
# include <iostream>

int	main(void)
{
	std::string Command;
	PhoneBook phoneBook;

	while (1)
	{
		std::cout << "Enter ONE Command (ADD / SEARCH / EXIT): ";
		std::getline(std::cin, Command);
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