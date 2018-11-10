#pragma once

#include "ienemy.hpp"

class AlienEnemy : public IEnemy
{
public:
    AlienEnemy()
    {
        m_health = 300.0;
        setName("Alien");
    }

    void injure(double p_damage) noexcept override
    {
        if(m_forceField > 0.0)
        {
            auto forceFieldDamage = 2 * p_damage;
            m_forceField -= (m_forceField > forceFieldDamage ? forceFieldDamage : m_forceField); 
        }
        else
        {
            m_health -= (m_health > p_damage ? p_damage : m_health);
        }
    }

private:
    double m_forceField {100.0};
};
