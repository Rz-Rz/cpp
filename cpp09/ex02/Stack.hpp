#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> stack;

public:
    // Constructor (optional)
    Stack() {}

    // Push an element onto the stack
    void push(const T& value) {
        stack.push_back(value);
    }

	// Get the size of the stack
	int size() {
		return stack.size();
	}

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        stack.pop_back();
    }

    // Get the top element from the stack
    T top() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot get top element." << std::endl;
            // Handle error as appropriate for your application
            // The following line is just an example
            return T(); // Return a default-constructed value
        }
        return stack.back();
    }

	void printStack()
	{
		int i = stack.size();
		while (!stack.empty())
		{
			T topElement = top();
			std::cout << "Level of Simulated recursion: " << i << std::endl;
			Printer<T>::print(std::cout, topElement);
			std::cout << std::endl;
			i--;
			pop();
		}
	}

    // Check if the stack is empty
    bool isEmpty() {
        return stack.empty();
    }
};
#endif
