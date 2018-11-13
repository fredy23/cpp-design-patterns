#pragma once

#include <cmath>

class RightTriangle
{
public:
    RightTriangle(double p_firstCathetus, double p_secondCathetus)
        : m_firstCathetus{p_firstCathetus}, m_secondCathetus{p_secondCathetus}
    {
        m_hypotenuse = std::sqrt(
            m_firstCathetus * m_firstCathetus + 
            m_secondCathetus * m_secondCathetus);
    }

    double getFirstCathetus() const noexcept
    {
        return m_firstCathetus;
    }

    double getSecondCathetus() const noexcept
    {
        return m_secondCathetus;
    }

    double getHypotenuse() const noexcept
    {
        return m_hypotenuse;
    }

private:
    double m_firstCathetus;
    double m_secondCathetus;
    double m_hypotenuse;
};
