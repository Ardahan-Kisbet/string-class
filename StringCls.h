#ifndef STRING_CLS_H
#define STRING_CLS_H

#include <iostream>

class StringCls
{
private:
    char *m_str = nullptr;
    size_t m_strLen = 0;

public:
    // constructors
    StringCls();                           // default constructor
    StringCls(const char *other);          // c-string constructor
    StringCls(const StringCls &other);     // copy constructor
    StringCls(StringCls &&other) noexcept; // move constructor
    ~StringCls();                          // destructor

    // data management

    // operators

    // output stream operator
    friend std::ostream &operator<<(std::ostream &output, const StringCls &other);

    // comparison operator
    bool operator==(const StringCls &other);

    // conversion operators

    // utility methods
    void Print();

    // find and replace methods

    // split methods
};

#endif