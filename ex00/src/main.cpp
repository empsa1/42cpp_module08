#include "../includes/easyfind.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

void printList(const std::list<int>& list) {
    std::cout << "List members: ";
    for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << CYAN << *it << RESET << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> list1;

    list1.push_back(10);
    list1.push_back(21);
    list1.push_back(13);
    list1.push_back(41);
    list1.push_back(30);
    list1.push_back(-20);
    list1.push_back(100);
    printList(list1);
    try
    {
        std::cout << YELLOW << "Trying to find 100 in the list" << RESET << std::endl;
        easyfind(list1, 100);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try
    {
        std::cout << YELLOW << "Trying to find 2 in the list" << RESET << std::endl;
        easyfind(list1, 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try
    {
        std::cout << YELLOW << "Trying to find 1 in the list" << RESET << std::endl;
        easyfind(list1, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << YELLOW << "Trying to find -1000 in the list" << RESET << std::endl;
        easyfind(list1, -1000);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}