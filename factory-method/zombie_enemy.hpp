#pragma once

#include "ienemy.hpp"

class ZombieEnemy : public IEnemy
{
public:
    ZombieEnemy()
        : IEnemy{500}
    {
    }

    void attack(IEnemy& p_enemy) noexcept override
    {
        if(m_swordDamage > 0)
        {
            p_enemy.injure(m_swordDamage);
            m_swordDamage -= 5;
        }
        else
        {
            p_enemy.injure(5);
        }
    }

private:
    double m_swordDamage {40};
};
