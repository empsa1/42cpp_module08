#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <list>
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
                return RED SPAN_TOO_SMALL RESET;
            }
        };
        class IllegalSpanSizeException: public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return RED SPAN_SIZE_ERROR RESET;
                }
        };
        Span(unsigned int N);
        Span(const Span &);
        ~Span();
        Span& operator=(const Span&);
        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
        const std::list< int >*   getList( void ) const;
    private:
        unsigned int N;
        std::list<int> elements;
        Span(void);
};
    std::ostream& operator<<( std::ostream&, const Span& );

#endif