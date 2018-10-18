#pragma once

#include <cmath>

#include "shape.hpp"

class Circle : public Shape
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
