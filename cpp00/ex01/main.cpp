#include <string>
#include <sstream>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"


int main()
{
	PhoneBook phoneBook;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD")
		{
			std::string firstName, lastName, nickname, phone, darkestSecret;

			std::cout << "Enter first name: ";
			std::getline(std::cin, firstName);

			std::cout << "Enter last name: ";
			std::getline(std::cin, lastName);

			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);

			std::cout << "Enter phone number: ";
			std::getline(std::cin, phone);

			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);

			Contact newContact(firstName, lastName, nickname, phone, darkestSecret);
			phoneBook.addContact(newContact);
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.displayContacts();

			std::cout << "Enter index of contact to display: ";
			std::string input;
			std::getline(std::cin, input);
			std::stringstream ss(input);
			int index;
			if (!(ss >> index))
			{
				std::cout << "Invalid input" << std::endl;
				continue;
			}
			if (index < 0 || index >= phoneBook.getNumContacts())
			{
				std::cout << "Invalid index" << std::endl;
				continue;
			}
			else
			{
				Contact contact = phoneBook.getContact(index);
				contact.printContact();
			}
		}
		else if (cmd == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}
}
