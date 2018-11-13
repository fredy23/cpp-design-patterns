#pragma once

#include "right_triangle.hpp"
#include "ishape.hpp"

class RightTriangleAdapter : public IShape, private RightTriangle
{
public:
    RightTriangleAdapter(double p_firstCathetus, double p_secondCathetus)
        : RightTriangle(p_firstCathetus, p_secondCathetus)
    {
        m_name = "Right triangle";
    }

    double getArea() const override
    {
        return 0.5 * getFirstCathetus() * getSecondCathetus();
    }

    double getPerimeter() const override
    {
        return getFirstCathetus() + getSecondCathetus() + getHypotenuse();
    }
};
