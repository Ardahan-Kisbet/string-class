#include <iostream>
#include "StringCls.h"
#include <vector>

int main()
{
    StringCls obj("test");
    std::cout << obj << std::endl;

    std::cout << "substring example" << std::endl;
    StringCls t =obj.substr(1, 2); 
    std::cout << obj.substr(1, 2) << std::endl;

    std::vector<StringCls> vec;
    vec.push_back(StringCls("Move gonna be called"));

    std::cin.get();
}