#include "StringCls.h"

// default constructor
StringCls::StringCls() : m_str(nullptr), m_strLen(0) {}

// destructor
StringCls::~StringCls() { delete[] m_str; }

// c-string constructor
StringCls::StringCls(const char *other)
{
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
    this->m_strLen = length + 1;
    this->m_str[length] = '\0';
}

// copy constructor
StringCls::StringCls(const StringCls &other)
{
    std::cout<< "copy ctor called"<< std::endl;
    if (other.m_strLen != this->m_strLen)
    {
        // reset this
        delete[] this->m_str;
        this->m_str = new char[other.m_strLen];
    }

    for (size_t i = 0; i < other.m_strLen; ++i)
    {
        this->m_str[i] = other.m_str[i];
    }
    this->m_strLen = other.m_strLen;
}

// move constructor
StringCls::StringCls(StringCls &&other) noexcept
{
    std::cout<< "move ctor called"<< std::endl;
    this->m_str = other.m_str;
    this->m_strLen = other.m_strLen;
    other.m_str = nullptr;
    other.m_strLen = 0;
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

    // TODO

    // three way output = , < , >
    return res;
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
