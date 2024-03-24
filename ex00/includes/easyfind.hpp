#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Utils.hpp"

template<typename T>
typename T::iterator easyfind(T& container, int parameter2)
{
    typename T::iterator it = std::find(container.begin(), container.end(), parameter2);
    if (it != container.end()) {
        std::cout << GREEN << "Value was found" << RESET << std::endl;
        return it;
    } else {
        throw std::runtime_error( RED "Value not found in container" RESET);
    }
}

#endif
