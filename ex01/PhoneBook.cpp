#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>


std::string truncate(std::string str, int length)
{
	if (str.length() > length)
	{
		return str.substr(0, length - 1) + ".";
	}
	else
	{
		return str;
	}
}

void PhoneBook::addContact(Contact &contact)
{
	if (this->numContacts < 8)
	{
		contacts[numContacts] = contact;
		numContacts++;
	}
	else
	{
		for (int i = 1; i < this->numContacts; i++)
		{
			contacts[i - 1] = contacts[i];
		}
		contacts[this->numContacts - 1] = contact;
	}
}

int PhoneBook::getNumContacts()
{
	return this->numContacts;
}

Contact PhoneBook::getContact(int index)
{
	if (index >= 0 && index < this->numContacts)
	{
		return this->contacts[index];
	}
	else
	{
		return Contact();
	}
}

void PhoneBook::displayContacts()
{
	std::cout << std::setw(10) << std::right << "Index" << " | ";
	std::cout << std::setw(10) << std::right << "First Name" << " | ";
	std::cout << std::setw(10) << std::right << "Last Name" << " | ";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < this->numContacts; i++)
	{
		std::cout << std::setw(10) << std::right << i << " | ";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getFirstName(), 10) << " | ";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getLastName(), 10) << " | ";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].getNickname(), 10) << " | ";
	}
}
