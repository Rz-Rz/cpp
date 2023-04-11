#include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook();
		void addEntry();
		void printAllEntries();
		void printEntry();
		void removeEntry();
		void saveToFile();
		void loadFromFile();
		
	private:
		Contact *contact;
		int numEntries;
		int maxEntries;
}
