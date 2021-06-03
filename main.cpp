#include <iostream>
#include "StringCls.h"

int main()
{
    StringCls obj("test");
    std::cout << obj << std::endl;

    StringCls t =obj.substr(1, 2); 
    std::cout << obj.substr(1, 2) << std::endl;

    std::cin.get();
}