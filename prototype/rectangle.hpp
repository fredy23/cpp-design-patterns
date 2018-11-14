#pragma once

#include <memory>
#include "ishape.hpp"

class Rectangle : public IShape
{
public:
    Rectangle(double p_width, double p_height)
        : m_width{p_width}, m_height{p_height}
    {
    }

    double getPerimeter() const noexcept override
    {
        return 2.0 * (m_width + m_height);
    }

    void enlarge(double p_scaleFactor) noexcept override
    {
        m_width *= p_scaleFactor;
        m_height *= p_scaleFactor;
    }

    std::unique_ptr<IShape> clone() const override
    {
        return std::make_unique<Rectangle>(*this);
    }

private:
    double m_width;
    double m_height;
};
