#include <string>

class Contact
{
	public:
		Contact();
		Contact(std::string name, std::string phone, std::string email);
		void setName(std::string name);
		void setPhone(std::string phone);
		void setEmail(std::string email);
		std::string getName();
		std::string getPhone();
		std::string getEmail();
		void printContact();
		
	private:
		std::string name;
		std::string phone;
		std::string email;
};
