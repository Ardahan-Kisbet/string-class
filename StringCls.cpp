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

// copy constructor
StringCls::StringCls(const StringCls &other)
{
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