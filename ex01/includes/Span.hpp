#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <array>
#include <cstdlib>
#include "../includes/Utils.hpp"

class Span
{
    public:
        class IllegalAddException : public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return RED ILLEGAL_ADD RESET;
            }
        };
        class IllegalSpanException: public std::exception {
        public:
            virtual const char* what() const throw()
            {
                return RED EMPTY_SPAN RESET;
            }
        };
        Span(unsigned int N);
        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
        unsigned int     size();
    private:
        unsigned int const N;
        std::vector<int> elements;
};

#endif