#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
unsigned int easyfind(T& container, int parameter2)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << "Found" << std::endl;
    else
        std::cout << "Not Found" << std::endl;
}       
#endif