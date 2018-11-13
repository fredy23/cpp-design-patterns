#pragma once

#include "ishape.hpp"

class Rectangle : public IShape
{
public:
    Rectangle(double p_width, double p_height)
        : m_width{p_width}, m_height{p_height}
    {
        m_name = "Rectangle";
    }

    double getArea() const override
    {
        return m_width * m_height;
    }

    double getPerimeter() const override
    {
        return 2 * (m_width + m_height);
    }

private:
    double m_width;
    double m_height;
};
