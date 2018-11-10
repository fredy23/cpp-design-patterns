#pragma once

#include "igun.hpp"
#include "ienemy.hpp"

class PlasmaGun : public IGun
{
public:
    PlasmaGun()
    {
        setName("Plasma Gun");
    }

    void shoot(IEnemy& p_enemy) noexcept override
    {
        if(m_plasmaAmount > 0.0)
        {
            p_enemy.injure(0.1 * m_plasmaAmount);
            m_plasmaAmount -= 75.0;
        }
    }

    bool isUsable() const noexcept override
    {
        return m_plasmaAmount > 0.0;
    }

private:
    double m_plasmaAmount {500.0};
};
