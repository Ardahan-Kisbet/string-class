#ifndef STRING_CLS_H
#define STRING_CLS_H

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

    // comparison operators
    bool operator==(const StringCls &other);

    // conversion operators

    // utility methods

    // find and replace methods

    // split methods
};

#endif