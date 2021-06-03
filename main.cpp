#include <iostream>
#include "StringCls.h"

int main()
{
    StringCls obj("test");
    std::cout << obj << std::endl;

    std::cout << obj.substr(1, 2) << std::endl;

    std::cin.get();
}