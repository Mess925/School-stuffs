#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	Contact contact;
	// int index = 1;
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
		else
		{
			std::cout << "Invalid command. Use ADD, SEARCH, or EXIT.\n";
		}
	}
	// contact.DisplayContact();
	// while (index < 9)
	// {
	// 	contact.DisplayAll(index);
	// 	index++;
	// }
	return (0);
}