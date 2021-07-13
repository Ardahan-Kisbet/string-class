#include "StringCls.h"

// default constructor
StringCls::StringCls() : m_str(nullptr), m_strLen(0) {}

// destructor
StringCls::~StringCls() { delete[] m_str; }

// c-string constructor
StringCls::StringCls(const char *other)
{
    std::cout << "c-string ctor is called" << std::endl;
    m_strLen = 0;
    while (other != nullptr && *other != '\0')
    {
        ++m_strLen;
        ++other;
    }

    m_str = new char[m_strLen + 1];
    m_str[m_strLen] = '\0';
    for (int i = m_strLen - 1; i >= 0; --i)
    {
        --other;
        m_str[i] = *other;
    }
}

// given length constructor
StringCls::StringCls(size_t length)
{
    this->m_str = new char[length + 1] {};
    this->m_strLen = length;
    this->m_str[length] = '\0';
}

// copy constructor
StringCls::StringCls(const StringCls &other)
{
    std::cout<< "copy ctor is called"<< std::endl;
    if (other.m_strLen != this->m_strLen)
    {
        // reset this
        delete[] this->m_str;
        this->m_str = nullptr;
        this->m_str = new char[other.m_strLen + 1];
        this->m_str[other.m_strLen] = '\0';
    }

    this->m_strLen = other.m_strLen;
    strncpy(this->m_str, other.m_str, this->m_strLen);
}

// copy assignment operator
StringCls& StringCls::operator=(const StringCls& other)
{
    std::cout<<"assignment operator is called"<< std::endl;
    if(this != &other)
    {
        delete[] this->m_str;
        this->m_str = nullptr;
        this->m_str = new char[other.m_strLen + 1];
        this->m_str[other.m_strLen] = '\0';
        this->m_strLen = other.m_strLen;
        strncpy(this->m_str, other.m_str, this->m_strLen);
    }
    // Else: same address, prevent self assignmet

    return *this;
}

// move constructor
StringCls::StringCls(StringCls &&other) noexcept : m_str(nullptr), m_strLen(0)
{
    std::cout<< "move ctor is called"<< std::endl;
    
    // std move turns other to rvalue
    // therefore; move assignment operator will be called in this line
    *this = std::move(other);
}

// move assignment operator
StringCls& StringCls::operator=(StringCls&& other)
{
    std::cout<<"move assignment operator is called"<< std::endl;
    if(this != &other)
    {
        // free before moving
        delete[] this->m_str;
        this->m_strLen = 0;

        // copy pointer of other data
        this->m_str = other.m_str;
        this->m_strLen = other.m_strLen;

        // release other data
        other.m_str = nullptr;
        other.m_strLen = 0;

    }
    // Else: do not move object to itself, possible loss of data due to data free operation

    return *this;
}

// output stream operator
std::ostream &operator<<(std::ostream &output, const StringCls &other)
{
    output << other.m_str;
    return output;
}

// equal operator
bool StringCls::operator==(const StringCls &other)
{
    // pre-check with lengths
    if (this->m_strLen != other.m_strLen)
        return false;

    // check each characters
    for (size_t i = 0; i < this->m_strLen; ++i)
    {
        if (this->m_str[i] != other.m_str[i])
            return false;
    }

    return true;
}

// comparison method
int StringCls::compare(const StringCls& other)
{
    int res;
    char * s1, *s2;
    s1 = m_str;
    s2 = other.m_str;
    // three way output = , < , >
    while (*s1 != '\0' && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    
    if(*s1 == *s2)
        return 0;

    return *s1 < *s2 ? -1 : 1;
}

// substring method
StringCls StringCls::substr(size_t pos, size_t len)
{
    StringCls temp(len);
    for(size_t i = 0; i < len; ++i)
    {
        temp.m_str[i] = this->m_str[pos + i];
    }

    return temp;
}

// swap two strings
void StringCls::swap(StringCls& lhs, StringCls& rhs)
{
    // TODO
    //
}