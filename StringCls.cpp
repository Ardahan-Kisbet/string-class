#include "StringCls.h"

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