#include "Stack.hpp"

int main() {
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    std::cout << "Top element: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Top element after pop: " << intStack.top() << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("A");
    stringStack.push("B");
    stringStack.push("C");

    std::cout << "Top string element: " << stringStack.top() << std::endl;

    return 0;
}
