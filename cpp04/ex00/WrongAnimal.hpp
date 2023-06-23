#include <string>

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		virtual void makeSound() const;
		std::string getType() const;

		WrongAnimal &operator=(const WrongAnimal &other);

	protected:
		std::string type;
};
#endif

