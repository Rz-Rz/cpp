#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string darkestSecret);
		void setFirstName(std::string &firstName);
		void setLastName(std::string &lastName);
		void setNickname(std::string &lastName);
		void setDarkestSecret(std::string &darkestSecret);
		void setPhone(std::string &phone);
		std::string getPhone();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getDarkestSecret();
		void printContact();
		
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phone;
		std::string darkestSecret;
};

#endif
