#pragma once

#include "igun.hpp"
#include "ienemy.hpp"

class RevolverGun : public IGun
{
public:
    RevolverGun()
    {
        setName("Revolver");
    }

    void shoot(IEnemy& p_enemy) noexcept override
    {
        if(m_bullets > 0)
        {
            p_enemy.injure(60.0);
            --m_bullets;
        }
    }

    bool isUsable() const noexcept override
    {
        return m_bullets > 0;
    }

private:
    int m_bullets {7};
};
