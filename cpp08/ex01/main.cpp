#include <iostream>
#include "span.hpp"

int main()
{
    // Test with a small span
    Span smallSpan(5);
    smallSpan.addNumber(1);
    smallSpan.addNumber(3);
    smallSpan.addNumber(5);
    smallSpan.addNumber(7);
    smallSpan.addNumber(9);

    std::cout << "Small span shortest span: " << smallSpan.shortestSpan() << std::endl;
    std::cout << "Small span longest span: " << smallSpan.longestSpan() << std::endl;

    // Test with a large span
    Span largeSpan(10000);
    for (int i = 0; i < 10000; ++i)
    {
        largeSpan.addNumber(i);
    }

    std::cout << "Large span shortest span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Large span longest span: " << largeSpan.longestSpan() << std::endl;

    // Test with a span of size 1 (should throw an exception)
    Span singleSpan(1);
    singleSpan.addNumber(42);

    try
    {
        std::cout << "Single span shortest span: " << singleSpan.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Single span longest span: " << singleSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test with an empty span (should throw an exception)
    Span emptySpan(0);

    try
    {
        emptySpan.addNumber(42);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
