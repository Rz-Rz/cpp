#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of the string in memory: " << &str << std::endl;
    std::cout << "Address stored in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address stored in stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
