#include "../includes/Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    {
        //Test case 0: 2 number span
        try
        {
            std::cout << "Simple 2 sized span test" << std::endl;
            Span sp = Span(2);
            sp.addNumber(1);
            sp.addNumber(2);
            std::cout << YELLOW << sp << RESET << std::endl;
            std::cout << CYAN << sp.shortestSpan() << RESET << std::endl;
            std::cout << CYAN << sp.longestSpan() << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        //Test case 1: Subject test
        try
        {
            std::cout << "Subject main test" << std::endl;
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << YELLOW << "Current span: " << sp << RESET << std::endl;
            std::cout << CYAN << "Shortest Span: " << sp.shortestSpan() << RESET << std::endl;
            std::cout << CYAN << "Biggest span: " << sp.longestSpan() << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        //Test case2: Small and empty span
        try
        {
            std::cout << "Adding element to span with 0 length" << std::endl;
            Span sp = Span(0);
            sp.addNumber(0);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            std::cout << "Smallest Span with 1 element" << std::endl;
            Span sp2 = Span(1);
            sp2.addNumber(1);
            std::cout << YELLOW << "Current span: " << sp2 << RESET << std::endl;
            std::cout << CYAN << "Shortest Span: " << sp2.shortestSpan() << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            std::cout << "Longest Span with 1 element" << std::endl;
            Span sp2 = Span(1);
            sp2.addNumber(1);
            std::cout << YELLOW << "Current span: " << sp2 << RESET << std::endl;
            std::cout << CYAN << "Biggest span: " << sp2.longestSpan() << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        // Test case 3: Add numbers within capacity and calculate spans
        try
        {
            std::cout << "Test Case 1: Adding numbers within capacity and calculating spans" << std::endl;
            Span span1(10);
            for (int i = 1; i <= 10; ++i) {
                span1.addNumber(i);
            }
            std::cout << YELLOW << "Current span: " << span1 << RESET << std::endl;
            std::cout << CYAN << "Shortest Span: " << span1.shortestSpan() << RESET << std::endl;
            std::cout << CYAN << "Biggest span: " << span1.longestSpan() << RESET << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        // Test case 4: Attempt to add more numbers than capacity
        try {
            std::cout << "\nTest Case 2: Attempting to add more numbers than capacity" << std::endl;
            Span span2(5);
            for (int i = 1; i <= 6; ++i) {
                span2.addNumber(i);
            }
        } catch (const Span::IllegalAddException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        // Test case 5: Calculate spans with fewer numbers
        try {
            std::cout << "\nTest Case 3: Calculating spans with fewer numbers" << std::endl;
            Span span3(3);
            span3.addNumber(10);
            span3.addNumber(20);
            std::cout << YELLOW << "Current span: " << span3 << RESET << std::endl;
            std::cout << CYAN << "Shortest Span: " << span3.shortestSpan() << RESET << std::endl;
            std::cout << CYAN << "Biggest span: " << span3.longestSpan() << RESET << std::endl;
        }
        catch (const Span::IllegalSpanException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    {
        // Test case 6: Add large number of numbers and calculate spans
        try {
            std::cout << "\nTest Case 4: Adding large number of numbers and calculating spans" << std::endl;
            const int SIZE = 30000;
            Span span4(SIZE);
            for (int i = 0; i < SIZE; ++i) {
            span4.addNumber(i);
        }
            std::cout << YELLOW << "Current span: " << span4 << RESET << std::endl;
            std::cout << CYAN << "Shortest Span: " << span4.shortestSpan() << RESET << std::endl;
            std::cout << CYAN << "Biggest span: " << span4.longestSpan() << RESET << std::endl;
        }
        catch (const Span::IllegalSpanException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
