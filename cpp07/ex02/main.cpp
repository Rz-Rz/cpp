#include <iostream>
#include "Array.hpp"
#include <cstdlib>


#define MAX_VAL 750
int main()
{
    Array<int> arr(5); // Create an array of 5 integers

    // Assign some values
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        arr[i] = i * 2;
    }

    // Print the values
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    // Test out-of-range access
    try
    {
        int value = arr[10]; // Attempt to access the 10th element
        (void)value; // Remove unused variable warning
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Caught an out_of_range exception: " << e.what() << '\n';
    }

     // Test with std::string
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    for (unsigned int i = 0; i < strArray.size(); ++i)
    {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    // Test out of range
    try
    {
        std::cout << "Accessing out of range index: " << strArray[5] << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
