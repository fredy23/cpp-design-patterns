#pragma once

#include <string>

class INameable
{
public:
    void setName(const std::string& p_name)
    {
        m_name = p_name;
    }

    std::string getName() const
    {
        return m_name;
    }

protected:
    std::string m_name {};
};
