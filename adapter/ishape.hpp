#pragma once

#include <string>

class IShape
{
public:
    std::string getName() const
    {
        return m_name;
    }

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual ~IShape() = default;    

protected:
    std::string m_name {};
};
