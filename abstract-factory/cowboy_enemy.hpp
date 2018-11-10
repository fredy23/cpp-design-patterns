#pragma once

#include "ienemy.hpp"

class CowboyEnemy : public IEnemy
{
public:
    CowboyEnemy()
    {
        setName("Cowboy");
    }

    void injure(double p_damage) noexcept override
    {
        m_health -= (m_health > p_damage ? p_damage : m_health);
    }
};
