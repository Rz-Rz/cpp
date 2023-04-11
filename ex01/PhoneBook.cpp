#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>



int main()
{
	PhoneBook phoneBook;
	int choice;
	
	do
	{
		std::cout << "ADD - Add an entry to the phone book" << std::endl;
		std::cout << "SEARCH - Show the information of the contact" << std::endl;
		std::cout << "Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
			
		switch(choice)
		{
			case ADD:
				phoneBook.addEntry();
				break;
			case SEARCH:
				phoneBook.printEntry();
				break;
			case EXIT:
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
				break;
		}
	} while (choice != 7);

	return 0;
}
