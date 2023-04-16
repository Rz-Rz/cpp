#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <array>
#include "Contact.hpp"


class PhoneBook 
{
	public:
		PhoneBook() : numContacts(0) {};
		void addContact(Contact &contact);
		int getNumContacts();
		Contact getContact(int index);
		void displayContacts();
		
	private:
		std::array<Contact, 8> contacts;
		int numContacts;
};

#endif
