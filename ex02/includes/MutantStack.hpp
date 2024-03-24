#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>
#include "../includes/Utils.hpp"

template<typename T> 
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack& operator=(const MutantStack &other)
        {
            if (this != &other)
                this->c = other.c;
            return *this;
        }
        MutantStack (MutantStack &other) {
            *this = other;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(){ return this->c.begin();}
        iterator end(){ return this->c.end();};
        iterator rbegin() { return this->c.rbegin();}
        iterator rend() { return this->c.rend();}
};

#endif