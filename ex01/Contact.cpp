#include "Contact.hpp"
#include <string>

void Contact::setLastName(std::string &lastName)
{
	this->lastName = lastName;
}

void Contact::setFirstName(std::string &firstName)
{
	this->firstName = firstName;
}

void Contact::setNickname(std::string &nickname)
{
	this->nickname = nickname;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

void Contact::setPhone(std::string &phone)
{
	this->phone = phone;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

std::string Contact::getPhone()
{
	return this->phone;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phone = phone;
	this->darkestSecret = darkestSecret;
}
