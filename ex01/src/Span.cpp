#include "../includes/Span.hpp"

Span::Span(unsigned int const N) : N(N)
{
    this->elements = this->_vector.begin();
}

unsigned int Span::size()
{
    int i = -1;
    unsigned int counter = 0;
    while (elements[++i] != '\0')
        counter++;
    return counter;
}

void Span::addNumber(int number)
{
    if (this->size() >= N)
        throw IllegalAddException();
    elements[this->size() + 1] = number;
    std::cout << GREEN SUCESS_ADD RESET << std::endl;
}

int Span::shortestSpan()
{
    int i = 0;
    if (this->size() <= 0)
        throw IllegalSpanException();
    int smallest = elements[0];
    int second_smallest = elements[0];
    while (elements[++i] != '\0')
    {
        if (elements[i] > smallest && elements[i] < second_smallest)
            second_smallest = elements[i];
        if (elements[i] < smallest)
            smallest = elements[i];
    }
    std::cout << GREEN SUCESS_SPAN RESET << std::endl;
    return (second_smallest - smallest);
}

int Span::longestSpan()
{
    int i = 0;
    if (this->size() <= 0)
        throw IllegalSpanException();
    int shortest = elements[0];
    int biggest = elements[0];
    while (elements[++i] != '\0')
    {
        if (elements[i] > biggest)
            biggest = elements[i];
        if (elements[i] < shortest)
            shortest = elements[i];
        std::cout << "Current biggest and smallest: " << biggest << shortest << std::endl;
    }
    std::cout << GREEN SUCESS_SPAN RESET << std::endl;
    return (biggest - shortest);
}