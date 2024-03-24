#include "../includes/Span.hpp"

Span::Span(void)
{
    if (DEBUG_MODE == 1)
        std::cout << RED << DEFAULT_CONSTRUCTOR << RESET << std::endl;
}

Span::Span(unsigned int const N) : N(N)
{
    if (DEBUG_MODE == 1)
        std::cout << GREEN << PARAMTER_CONSTRUCTOR << RESET << std::endl;
    if (N < 0)
    {
        delete this;
        throw IllegalSpanSizeException();
    }
}

Span::Span(const Span & other)
{
    if (DEBUG_MODE == 1)
        std::cout << GREEN << COPY_CONSTRUCTOR << RESET << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (DEBUG_MODE == 1)
        std::cout << GREEN << ASSIGMENT_OPERATOR << RESET << std::endl;
    if (this != &other)
    {
        this->N = other.N;
        this->elements = other.elements;
    }
    return *this;
}

Span::~Span()
{
    if (DEBUG_MODE == 1)
        std::cout << GREEN << DESTRUCTOR << RESET << std::endl;
}

void Span::addNumber(int number)
{
    if (elements.size() >= N)
        throw IllegalAddException();
    elements.push_back( number );
    if (DEBUG_MODE == 1)
        std::cout << GREEN SUCESS_ADD RESET << std::endl;
}

int Span::shortestSpan()
{
    //std::cout << *this << std::endl;
    std::list<int>::const_iterator iter = this->getList()->begin();
    std::list<int>::const_iterator iter2 = this->getList()->begin();
    int span = std::abs((*++iter) - *iter2);
    //std::cout << GREEN  << "Span: " << span << RESET << std::endl;
    if(elements.size() < 2)
        throw IllegalSpanException();
    while (iter2 != this->getList()->end())
    {
        //std::cout << RED << "Out iter: " << *iter2 << RESET << std::endl;
        iter = iter2;
        while(++iter != this->getList()->end())
        {
            //std::cout << YELLOW << "In iter: " << *iter << RESET << std::endl;
            if (std::abs(*iter - *iter2) < span)
            {
                span = std::abs(*iter - *iter2);
                //std::cout << CYAN  << "New Span: " << span << " with: " << *iter << ", " << *iter2 << RESET << std::endl;
            }
        }
        ++iter2;
    }
    return (span);
}

int Span::longestSpan()
{
    std::list<int>::const_iterator iter = this->getList()->begin();
    int smallest = *iter;
    int biggest = *(++iter);
    if(elements.size() < 2)
        throw IllegalSpanException();
    if (smallest > biggest)
    {
        int temp = smallest;
        smallest = biggest;
        biggest = temp;
    }
    while (++iter != this->getList()->end())
    {
        if (smallest > *iter)
            smallest = *iter;
        if (biggest < *iter)
            biggest = *iter;
    }
    if (DEBUG_MODE == 1)
        std::cout << MAGENTA << "biggestSpan(): Smallest && Biggest: " 
            << smallest << ", " << biggest << RESET << std::endl;
    return (biggest - smallest);
}

const std::list<int>* Span::getList() const{
    return &elements;
}

std::ostream& operator<<(std::ostream &os, const Span& span)
{
    std::list<int>::const_iterator iter = span.getList()->begin();
    while (iter != span.getList()->end())
    {
        os << *iter << " ";
        iter++;
    }
    return os;
}