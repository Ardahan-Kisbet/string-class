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
    StringCls(size_t length);              // given length constructor
    StringCls(const char *other);          // c-string constructor
    StringCls(const StringCls &other);     // copy constructor
    StringCls(StringCls &&other) noexcept; // move constructor
    ~StringCls();                          // destructor

    // data management
    void swap(StringCls& lhs, StringCls& rhs);

    // operators
    // assignment operator
    StringCls& operator=(const StringCls& other);

    // move assignment operator
    StringCls& operator=(StringCls&& other);

    // output stream operator
    friend std::ostream &operator<<(std::ostream &output, const StringCls &other);

    // comparison operator
    bool operator==(const StringCls &other);

    // conversion operators

    // utility methods
    // comparison method
    int compare(const StringCls& other);

    // find and replace methods

    // split methods
    // substring
    StringCls substr(size_t pos, size_t len);

};

#endif