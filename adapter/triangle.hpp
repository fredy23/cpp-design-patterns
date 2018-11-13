#pragma once

#include <cmath>
#include <algorithm>

#include "ishape.hpp"

class Triangle : public IShape
{
public:
    Triangle(double p_side1, double p_side2, double p_side3)
        : m_sides{p_side1, p_side2, p_side3}
    {
        m_name = "Triangle";
    }

    double getArea() const override
    {
        auto halfPerimeter = (m_sides[0] + m_sides[1] + m_sides[2]) / 2.0;
        double result {halfPerimeter};

        std::for_each(std::begin(m_sides), std::end(m_sides), [&result, halfPerimeter](double p_side)
        {
            result *= (halfPerimeter - p_side);
        });

        return std::sqrt(result);
    }

    double getPerimeter() const override
    {
        return m_sides[0] + m_sides[1] + m_sides[2];
    }

private:
    double m_sides[3];
};
