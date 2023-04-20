#include "Harl.hpp"
#include <iostream>

void Harl::complain(const std::string& level) {
	typedef void (Harl::*Complaint)();
	struct ComplaintMap {
		std::string level;
		Complaint complaint;
	};

	static const ComplaintMap complaint_map[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};

	const int map_size = sizeof(complaint_map) / sizeof(complaint_map[0]);
	for (int i = 0; i < map_size; i++)
	{
		const ComplaintMap &cm = complaint_map[i];
		if (level == cm.level) {
			(this->*cm.complaint)();
			return;
		}
	}
	std::cerr << "Invalid complaint level: " << level << std::endl;
}


void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
