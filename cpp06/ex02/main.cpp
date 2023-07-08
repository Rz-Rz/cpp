#include "Base.hpp"

int main() {
    Base* ptr = generate();
	Base* ptr2 = generate();

    identify(ptr);
    identify(*ptr);

    identify(ptr2);
	identify(*ptr2);

    delete ptr;
	delete ptr2;
    return 0;
}
