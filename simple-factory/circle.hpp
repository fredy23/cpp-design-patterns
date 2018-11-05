#pragma once

#include <cmath>

#include "ishape.hpp"

class Circle : public IShape
{
public:
    Circle(double p_radius)
        : m_radius{p_radius}
    {
    }

    double getArea() const noexcept override
    {
        return M_PI * m_radius * m_radius;
    }

private:
    double m_radius;
};
