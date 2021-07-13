#include <iostream>
#include "StringCls.h"
#include <vector>

int main()
{
    // c-string ctor
    std::cout << "\n\t#c-string ctor object creation example" << std::endl;
    StringCls obj("test");
    std::cout << obj << std::endl;

    // substring
    std::cout << "\n\t#substring example" << std::endl;
    StringCls t =obj.substr(1, 2); 
    std::cout << obj.substr(1, 2) << std::endl;

    // move ctor + move assignment operator
    std::cout << "\n\t#move ctor + move assignment operator example" << std::endl;
    std::vector<StringCls> vec;
    vec.push_back(StringCls("Move gonna be called"));

    // c-string ctor + copy assignment operator
    std::cout << "\n\t#c-string ctor + copy assignment operator example" << std::endl;
    StringCls s1 = "s1";
    StringCls s2("s2");
    s1 = s2;
    std::cout << s1 << std::endl;

    // copy ctor
    std::cout << "\n\t#copy ctor example" << std::endl;
    StringCls s3 = s1;
    std::cout << s3 << std::endl;

    // comparison
    std::cout << "\n\t#comparison example" << std::endl;
    StringCls s4("comparable text");
    StringCls s5("comparable text");
    cmp_res = s4.compare(s5);
    if(cmp_res == 0)
        std::cout << "s4 and s5 strings are equal."<< std::endl;

    std::cin.get();
}