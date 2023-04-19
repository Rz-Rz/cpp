#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
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
		Contact contacts[8];
		int numContacts;
};

#endif
