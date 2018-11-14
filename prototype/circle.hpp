#pragma once

#include <memory>
#include <cmath>

#include "ishape.hpp"

class Circle : public IShape
{
public:
    Circle(double p_radius)
        : m_radius{p_radius}
    {
    }

    double getPerimeter() const noexcept override
    {
        return 2.0 * M_PI * m_radius;
    }

    void enlarge(double p_scaleFactor) noexcept override
    {
        m_radius *= p_scaleFactor;
    }

    std::unique_ptr<IShape> clone() const override
    {
        return std::make_unique<Circle>(*this);
    }

private:
    double m_radius;
};
